#ifndef DEF_XL
#define DEF_XL

#include<string>
#include<vector>
	


#include "ClientDB.h"
#include "ArticleDB.h"
#include "CommandDB.h"
#include "LivraisonDB.h"
#include "utility.h"

#include "Command.h"
#include "Livraison.h"
#include "Client.h"
#include "Article.h"


/*
class Client;
class Article;
class Command;
class Livraison;
*/

class XL {
	
	public:
		
	XL();
	std::vector<Article> getArticles();
	std::vector<Article> getCriticalArticles();
	Client getBestClient( const Article &article);
	float capital();
	
	/*
	void saveClient(json info);
	void saveArticle(json info);
	void saveCommand(json info);
	void saveLivraison(json info);
	void updateClient(json info);
	void updateArticle(json info);
	void updateCommand(json info);
	void updateLivraison(json info);
	void removeClient(unsigned id);
	void removeArticle(unsigned id);
	void removeCommand(unsigned id);
	void removeLivraison(unsigned id);
	void findClient(unsigned id);
	void findArticle(unsigned id);
	void findCommand(unsigned id);
	void findLivraison(unsigned id); */
	
	
	ArticleDB Articles;
	ClientDB  Clients;
	CommandDB Commands;
	LivraisonDB Livraisons;
	Database db;
	
	
	
};

#endif
