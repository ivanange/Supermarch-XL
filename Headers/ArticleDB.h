#ifndef DEF_ArticleDB
#define DEF_ArticleDB

#include<string>
#include<vector>

#include "Database.h"
#include "json.hpp"
#include "utility.h"



class ArticleDB : public Database {
	public:
	ArticleDB();
	ArticleDB(std::string nom, std::string fichier, std::string cle );
	void add(nlohmann::json info );
	void remove(unsigned id);
	
};

#endif
