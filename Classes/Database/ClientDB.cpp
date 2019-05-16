#include "../../Headers/ClientDB.h"

#include "../../Headers/Client.h"

#include<iostream>

using namespace std;
using json = nlohmann::json;

ClientDB::ClientDB(){}
ClientDB::ClientDB(std::string nom, std::string fichier, std::string cle ) : Database(nom, fichier, cle) {  }

void ClientDB::add(nlohmann::json info ) {
	cout<<"_JSON : "<<(Database::_nom)<<endl;
}

void ClientDB::remove(unsigned id) {
	vector<Client> clients = _JSON[_nom].get<vector<Client>>();
	for( ClientIt it = clients.begin(); it != clients.end(); it++ ) {
		if( (*it).numero() == id ) { clients.erase(it); break;	}
	}
	_JSON[_nom] = clients;
	save();
}
