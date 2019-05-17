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


class XL {
	
	public:
		
	XL();
	std::vector<Article> getArticles();
	std::vector<Article> getCriticalArticles();
	Client getBestClient( const Article &article);
	Client getBestClient( unsigned ref);
	float capital();
	
	
	
	ArticleDB Articles;
	ClientDB  Clients;
	CommandDB Commands;
	LivraisonDB Livraisons;
	
	
	
};

#endif
