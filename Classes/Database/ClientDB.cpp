#include "../../Headers/ClientDB.h"

#include "../../Headers/Client.h"

using namespace std;
using json = nlohmann::json;

ClientDB::ClientDB(){}
ClientDB::ClientDB(std::string nom, std::string fichier, std::string cle ):Database(nom, fichier, cle) {}

void ClientDB::add(nlohmann::json info ) {
	info["numero"] = _JSON["index"].get<int>();
	_JSON["index"] = _JSON["index"].get<int>() +1;
	Client clients = Client(info);
	_JSON[_nom].push_back(clients);
	save();
}

void ClientDB::remove(unsigned id) {
	vector<Client> clients = _JSON[_nom].get<vector<Client>>();
	for( ClientIt it = clients.begin(); it != clients.end(); it++ ) {
		if( (*it).numero() == id ) { clients.erase(it); break;	}
	}
	_JSON[_nom] = clients;
	save();
}
