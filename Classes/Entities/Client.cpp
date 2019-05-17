#include "../../Headers/Client.h"

#include "../../Headers/Article.h"
#include "../../Headers/Command.h"
#include "../../Headers/ArticleDB.h"
#include "../../Headers/CommandDB.h"
#include<iostream>


using namespace std;
using json = nlohmann::json;


Client::Client(){}
Client::Client(nlohmann::json info) {
	_init(info);
}

Client::Client(nlohmann::json info, ArticleDB* articles, CommandDB* commandes ) {
	_init(info);
	_articles = articles;
	_commandes = commandes;
}

unsigned Client::numero() const {
	return _numero;
}

string Client::nom() const {
	return _nom;
}

void Client::nom(std::string nom) {
	_nom = nom ;
}

string Client::prenom() const {
	return _prenom;
}

void Client::prenom( std::string prenom) {
	_prenom = prenom;
}

string Client::date() const {
	return _dateDeNaissance.toString();
}

gender Client::genre() const {
	return _genre;
}

void Client::genre( gender genre) {
	_genre = genre;
}

vector<Article> Client::getArticles() {
	vector<Article> articles;
	json result = _commandes->findBY("numClient", _numero);
	for( JSONIt it = result.begin(); it!= result.end(); it++ ) {
		articles.push_back( _articles->find( (unsigned)(*it)["refArticle"] ).get<Article>() );
	}
	return articles;	
	
}

vector<Command> Client::getOngoingCommands() {
	unsigned id = _numero;
	std::function<bool(json)> filter = [id](const json object) -> bool {  return ( object["numClient"] == id  && object["etat"] == "en cours"); };
	return _commandes->findIf(filter).get<vector<Command>>();	
}

void Client::toJson(nlohmann::json &JSON) const {
	JSON = { {"numero", _numero},
	{"nom", _nom},
	{"prenom", _prenom},
	{"dateDeNaissance", _dateDeNaissance.toString() },
	{"genre", _genre==M ? "M":"F"  } };

}
void Client::_init(nlohmann::json info) {
	try {
	_numero  = (unsigned)info["numero"].get<unsigned>() ;
	_nom  = info["nom"].get<std::string>();
	_prenom  =  info["prenom"].get<std::string>();
	_dateDeNaissance  = Date( info["dateDeNaissance"].get<std::string>() );
	_genre = (info["genre"].get<std::string>() =="M" )? M:F;
	}
	catch(char const* const& err) {
		throw err;
	}
	catch(...) {
		throw("Invalid  or Missing  property  value for Client");
	}
	
}


void to_json(json &j,  const Client &client ) {
	client.toJson(j);
}

void from_json(const json &j, Client &client) {
	client = Client(j);
}






