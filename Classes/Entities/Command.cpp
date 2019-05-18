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
	
void Command::numClient(unsigned numClient) {
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
	
void Command::refArticle(unsigned refArticle) {
	_refArticle = refArticle;
}

unsigned Command::quantite() const {
	return _quantite;
	
}
	
void Command::quantite( unsigned quantite) {
	_quantite = quantite;
}
	
void Command::_init(nlohmann::json info) {
	try {
	_numCommand  = (unsigned)info["numCommand"].get<unsigned>();
	_refArticle  = (unsigned)info["refArticle"].get<unsigned>();
	_numClient  = (unsigned)info["numClient"].get<unsigned>();
	_quantite  = (unsigned)info["quantite"].get<unsigned>();
	_etat = etats(info["etat"].get<std::string>());
	}
	catch(...) {
		throw("Invalid  or Missing  property  value for Command");
	}
	
}

state Command::etats( string etat ) const {
	return etat == "livrer" ? livrer : ( etat == "en cours" ? en_cours : throw("Delivery state unrecognized") ) ;
}

string Command::etats( state etat ) const {
	return etat == livrer ? "livrer" : ( etat == en_cours ? "en cours" : throw("Delivery state unrecognized") ) ;
}

void Command::toJson(nlohmann::json &JSON) const {
	JSON = { {"numCommand", _numCommand},
	{"numClient", _numClient},
	{"refArticle", _refArticle},
	{"quantite", _quantite },
	{"etat", etats(_etat) } };
	
}

void to_json(json &j,  const Command &commande ) {
	commande.toJson(j);
}

void from_json(const json &j, Command &commande) {
	commande = Command(j);
}

state etat( string etat ) {
	return etat == "livrer" ? livrer : ( etat == "en cours" ? en_cours : throw("Delivery state unrecognized") ) ;
}

string etat( state etat ) {
	return etat == livrer ? "livrer" : ( etat == en_cours ? "en cours" : throw("Delivery state unrecognized") ) ;
}	
	
