#include "../../Headers/CommandDB.h"
#include "../../Headers/Command.h"

using namespace std;
using json = nlohmann::json;

CommandDB::CommandDB(){}
CommandDB::CommandDB(std::string nom, std::string fichier, std::string cle ) : Database(nom, fichier, cle) {}

void CommandDB::add(nlohmann::json info ) {
	string id = to_string(_JSON["index"].get<unsigned>() );
	info["numCommand"] = _JSON["index"].get<unsigned>();
	_JSON["index"] = _JSON["index"].get<unsigned>() +1;
	Command commandes = Command(info);
	_JSON[_nom][id] = commandes;
	save();
}

