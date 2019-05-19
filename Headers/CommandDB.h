#ifndef DEF_CommandDB
#define DEF_CommandDB

#include<string>
#include<vector>

#include "Database.h"
#include "json.hpp"
#include "utility.h"

class Command;


class CommandDB : public Database {
	public:
	CommandDB();
	CommandDB(std::string nom, std::string fichier, std::string cle );
	void add(nlohmann::json info );
	void add(const Command &command );
	
};

#endif
