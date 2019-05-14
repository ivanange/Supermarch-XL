#include "../../Headers/CommandDB.h"

using namespace std;
using json = nlohmann::json;

CommandDB::CommandDB(){}
CommandDB::CommandDB(std::string nom, std::string fichier, std::string cle ):Database(nom, fichier, cle) {}

void CommandDB::add(nlohmann::json info ) {
	info["numCommand"] = JSON["index"]++;
	Command commandes = Command(info);
	_JSON[_nom].push_back(commandes);
	save();
}

void CommandDB::remove(unsigned id) {
	vector<Command> commandes = _JSON[_nom].get<vector<Command>>();
	for( CommandIt it = commandes.begin(); it != commandes.end(); it++ ) {
		if( *it.numCommand() == id ) { commandes.erase(it); break;	}
	}
	_JSON[_nom] = commandes;
	save();
}
