#ifndef DEF_LivraisonDB
#define DEF_LivraisonDB

#include<string>
#include<vector>

#include "Database.h"
#include "json.hpp"
#include "utility.h"

class Livraison;


class LivraisonDB : public Database{
	public:
	LivraisonDB();
	LivraisonDB(std::string nom, std::string fichier, std::string cle );
	void add(nlohmann::json info );
	void add(const Livraison &livraison );
	
};

#endif
