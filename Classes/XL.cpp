#include "../Headers/XL.h"

using namespace std;
using json = nlohmann::json;
 

	XL::XL() {
		Articles.init("Articles", DB_DIRECTORY  +"Articles", "ref");
		Clients.init("Clients", DB_DIRECTORY  +"Clients", "numero");
		Commands.init("Commands", DB_DIRECTORY  +"Commands", "numCommand");
		Livraisons.init("Livraisons", DB_DIRECTORY  +"Livraisons", "ref");
	}
	vector<Article> XL::getArticles() { 
		return Articles.findAll().get<vector<Article>>();
	}
	vector<Article> XL::getCriticalArticles() {
		std::function<bool(json)> filter = [](const json object) -> bool {  return ( object["quantite"] <= object["seuil"] ); };
		return Articles.findIf(filter).get<vector<Article>>();
	}
	Client XL::getBestClient( const Article &article) {
		std::map<unsigned, unsigned> results;
		json commandes = Commands.findBY("refArticle", article.ref() );
		for( JSONIt it = commandes.begin(); it != commandes.end(); it++ ) {
			results[(*it)["numClient"].get<unsigned>()] += (*it)["quantite"].get<unsigned>();
		} 
		unsigned max = std::max_element(results.begin(), results.end(), [] (const std::pair<unsigned, unsigned>& a, const std::pair<unsigned,unsigned>& b)->bool{ return a.second < b.second; } )->first;			
		return Clients.find(max).get<Client>();
	}
	float XL::capital() {
		float capital = 0;
		json articles = Articles.findAll();
		for( JSONIt it = articles.begin(); it != articles.end(); it++ ) {
			capital += ( (*it)["quantite"].get<unsigned>() * ((*it)["prix"].get<float>()) );
		}
		return capital;	
	}
	/*
	void saveClient(json info);
	void saveArticle(json info);
	void saveCommand(json info);
	void saveLivraison(json info);
	
	*/

