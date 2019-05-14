#include "../../Headers/Article.h"
#include "../../Headers/Client.h"
#include "../../Headers/CommandDB.h"
#include "../../Headers/ClientDB.h"

using namespace std;
using json = nlohmann::json;

Article::Article(){}

Article::Article(nlohmann::json info) {	
	init(info); 
}

Article::Article(nlohmann::json info, CLientDB* clients, CommandDB* commandes ) {
	init(info);
	_clients = clients;
	_commandes = commandes;
}

unsigned Article::ref() const {	
	return _ref; 
}

std::string Article::label() const { 
	return _label;
}

void Article::label( std:string label) { 
	_label = label; 
}

float Article::prix() const { 
	return _prix; 
}

void Article::prix( float prix) { 
	_prix = prix; 
}

unsigned Article::quantite() const { 
	return prix; 
}

void Article::quantite( int quantite) {
	_quantite = quantite;
}
	
unsigned Article::seuil() const {
	return _seuil;
}

void Article::seuil( int seuil) {
	_seuil = seuil;
}

vector<Client> Article::getClients() {
	
	vector<Client> clients;
	json result = _commandes->findBY("refArticle", _ref);
	for( JSONIt it = result.begin(); it!= result.end(); it++ ) {
		clients.push_back( _clients->find( *it["numero"]).get<Client>() );
	}
	return clients;
	
}

void Article::toJson(nlohmann::json &JSON) {
	JSON = { {"ref", _ref},
	{"quantite", _quantite},
	{"seuil", _seuil},
	{"label", _label},
	{"prix", _prix} };
	
}

void Article::_init(nlohmann::json info) {
	try {
	_ref  = (unsigned)info["ref"].get<int>() ;
	_quantite  = (unsigned)info["quantite"].get<int>();
	_seuil  = (unsigned)info["seuil"].get<int>();
	_label  = info["label"].get<std::string>();
	_prix = info["prix"].get<float>();
	}
	catch{
		throw("Invalid property value");
	}
}

void to_json(json &j,  const Article &article ) {
	article.toJson(j);
}

void from_json(const json &j, Article &article) {
	article = Article(j);
}



