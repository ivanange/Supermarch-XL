#include "../../Headers/ClientDB.h"

#include "../../Headers/Client.h"

using namespace std;
using json = nlohmann::json;

ClientDB::ClientDB() : Database(){}
ClientDB::ClientDB(std::string nom, std::string fichier, std::string cle ): Database(nom, fichier, cle) {
}

void ClientDB::add(nlohmann::json info ) {
	string id = to_string(_JSON["index"].get<unsigned>() );
	info["numero"] = _JSON["index"].get<unsigned>();
	_JSON["index"] = _JSON["index"].get<unsigned>() +1;
	Client clients(info);
	json client = clients;
	_JSON[_nom][id] = client;
	save();
}

