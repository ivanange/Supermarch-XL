#include "./Headers/XL.h"

#include<iostream>

using namespace std;
using json = nlohmann::json;


int main() {

	try {
		
		XL marche;
		string nom =  "Clemantine";
		//marche.Clients.add({  { "nom" , nom}, {"prenom", "Dorcas"}, {"dateDeNaissance", "17/07/1934"}, {"genre", "F" } });
		//json test = marche.Clients.find(1).get<Client>();
		
		//marche.Clients.remove(0);
		
		//marche.Livraisons.add({  { "numCommand", 3}, {"quantite", 5}, {"numClient", 5}  } );
		//json test2 = marche.Livraisons.find("0").get<Livraison>();
		//marche.Livraisons.remove(0);
		
		 //marche.Commands.add({ 	{"numClient", 1},{"refArticle", 0},	{"quantite", 1 },	{"etat", "en cours" } });
		 //marche.Commands.add({ 	{"numClient", 1},{"refArticle", 1},	{"quantite", 2 },	{"etat", "livrer" } });
		// marche.Commands.add({ 	{"numClient", 1},{"refArticle", 1},	{"quantite", 5 },	{"etat", "livrer" } });
							
		//json test3 = marche.Commands.find("0").get<Command>();
		//marche.Commands.remove(0);
		
		//marche.Articles.add({ {"quantite", 100}, {"seuil", 130}, {"label", "Kaba"}, {"prix", 300} });
		//marche.Articles.add({ {"quantite", 75}, {"seuil", 30}, {"label", "Naya"}, {"prix", 100} });  
								
		//json test4 = marche.Articles.find(0).get<Article>();
		//marche.Articles.remove(0);
		
		
		
		
		//cout<<test<<endl<<endl<<test2<<endl<<test3<<endl<<test4;
		
		
		
		// XP methods test
		
		 //json Xtest = marche.getCriticalArticles();

		
		
		
		//cout<<Xtest<<endl;
		
		
		
	// Entity tests
	Client client( marche.Clients.find(1), &marche.Articles, &marche.Commands );
	Article article( marche.Articles.find(1), &marche.Clients, &marche.Commands ); 	
	
	json clients = article.getClients();
	json clientArticles = client.getArticles();
	json ongoingCommands = client.getOngoingCommands();
	
	marche.Articles.add(article);
	
	//vector<Command> 	vector<Article> vect = client.getArticles(); marche.Commands.findBY("numCommand", 1);
	cout<<clientArticles<<endl<<endl<<ongoingCommands<<endl<<endl<<clients<<endl<<marche.getBestClient(article).prenom()<<endl<<marche.capital();

		
		
		
	}
	catch(char const* const& err) {
		string error = err;
		cout<<error;
	}
	
	
}
