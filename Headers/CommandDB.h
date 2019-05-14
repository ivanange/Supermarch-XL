#ifndef DEF_CommandDB
#define DEF_CommandDB

#include<string>
#include<vector>

#include "Database.h"
#include "json.hpp"
#include "utility.h"


class CommandDB : public Database {
	public:
	CommandDB();
	CommandDB(std::string nom, std::string fichier, std::string cle );
	void add(nlohmann::json info );
	void remove(unsigned id);
	
};

#endif
