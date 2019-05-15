#include "../../Headers/Command.h"

using namespace std;
using json = nlohmann::json;


Command::Command() {}
Command::Command(nlohmann::json info) {
	_init(info);
}

unsigned Command::numCommand() const {
	return _numCommand; 
}
	
unsigned Command::numClient() const {
	return _numClient; 
}
	
void Command::numClient(int numClient) {
	_numClient = numClient;
}
	
state Command::etat() const {
	return _etat;
	
}
	
void Command::etat( state etat) {
	_etat = etat;
}
	
unsigned Command::refArticle() const {
	return _refArticle;
}
	
void Command::refArticle(int refArticle) {
	_refArticle = refArticle;
}

unsigned Command::quantite() const {
	return _quantite;
	
}
	
void Command::quantite( int quantite) {
	_quantite = quantite;
}
	
void Command::_init(nlohmann::json info) {
	try {
	_numCommand  = (unsigned)info["numCommand"].get<int>();
	_refArticle  = (unsigned)info["refArticle"].get<int>();
	_numClient  = (unsigned)info["numClient"].get<int>();
	_quantite  = (unsigned)info["quantite"].get<int>();
	_etat = info["etat"].get<std::string>()=="livrer" ? livrer:en_cours;
	}
	catch(...) {
		throw("Invalid property value");
	}
	
}

void Command::toJson(nlohmann::json &JSON) const {
	JSON = { {"numCommand", _numCommand},
	{"numClient", _numClient},
	{"refArticle", _refArticle},
	{"quantite", _quantite },
	{"etat", _etat==livrer ? "livrer": "en cours" } };
	
}

void to_json(json &j,  const Command &commande ) {
	commande.toJson(j);
}

void from_json(const json &j, Command &commande) {
	commande = Command(j);
}

	
	
	
