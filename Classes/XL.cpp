#include "../Headers/XL.h"
/*
#include "../Headers/Client.h"
#include "../Headers/Article.h"
#include "../Headers/Command.h"
#include "../Headers/Livraison.h"
*/
using namespace std;
using json = nlohmann::json;


	XL::XL() {
		ArticleDB Articles("Articles", DB_DIRECTORY  +"Articles", "ref");
		ClientDB Clients("Clients", DB_DIRECTORY  +"Clients", "numero");
		CommandDB Commands("Commands", DB_DIRECTORY  +"Commands", "numCommand");
		LivraisonDB Livraisons("Livraisons", DB_DIRECTORY  +"Livraisons", "ref");
	}
	vector<Article> XL::getArticles() {
		return Articles.findAll().get<vector<Article>>();
	}
	vector<Article> XL::getCriticalArticles() {
		std::function<bool(json)> filter = [](const json object) -> bool {  return ( object["quantite"] <= object["seuil"] ); };
		return Articles.findIf(filter).get<vector<Article>>();
	}
	Client XL::getBestClient( const Article &article) {
		std::map<int, int> results;
		json commandes = Commands.findBY("refArticle", article.ref() );
		for( JSONIt it = commandes.begin(); it != commandes.end(); it++ ) {
			results[(*it)["numClient"].get<int>()] += (*it)["quantite"].get<int>();
		} 
		int max = std::max_element(results.begin(), results.end(), [] (const std::pair<int,int>& a, const std::pair<int,int>& b)->bool{ return a.second < b.second; } )->first;			
		return Clients.find(max).get<Client>();
	}
	float XL::capital() {
		float capital = 0;
		json articles = Articles.findAll();
		for( JSONIt it = articles.begin(); it != articles.end(); it++ ) {
			capital += ( (*it)["quantite"].get<int>() * ((*it)["prix"].get<float>()) );
		}
		return capital;	
	}
	/*
	void saveClient(json info);
	void saveArticle(json info);
	void saveCommand(json info);
	void saveLivraison(json info);
	
	*/

