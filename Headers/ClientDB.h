#ifndef DEF_ClientDB
#define DEF_ClientDB 

#include<string>
#include<vector>

#include "Database.h"
#include "json.hpp"
#include "utility.h"


class ClientDB : public Database {
	public:
	ClientDB();
	ClientDB(std::string nom, std::string fichier, std::string cle );
	void add(nlohmann::json info );
};

#endif
