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
	
	unsigned id = _numero;
	std::function<bool(json)> filter = [id](const json object) -> bool {  return ( object["numClient"] == id  && object["etat"] == "livrer"); };
	vector<Article> articles;
	vector<unsigned> refs;
	
	json result = _commandes->findIf(filter);
	
	for( JSONIt it = result.begin(); it!= result.end(); it++ ) {
		unsigned ref = (*it)["refArticle"] ;
		if( find(refs.begin(), refs.end(), ref ) == refs.end() ) {
			refs.push_back(ref);
			articles.push_back( _articles->find( ref ).get<Article>() );
		}
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
	{"genre", genres(_genre) } };

}
void Client::_init(nlohmann::json info) {
	try {
	_numero  = info["numero"].get<unsigned>() ;
	_nom  = info["nom"].get<std::string>();
	_prenom  =  info["prenom"].get<std::string>();
	_dateDeNaissance  = Date( info["dateDeNaissance"].get<std::string>() );
	_genre = genres(info["genre"].get<std::string>());
	}
	catch(char const* const& err) {
		throw err;
	}
	catch(...) {
		throw("Invalid  or Missing  property  value for Client");
	}
	
}

string Client::genres(gender g )  const {
	return  g==F ? "F" : ( g==M ? "M" : throw("Unrecognized Gender") ) ;
}

gender Client::genres(string g ) const {
	return  g=="F" ? F : ( g=="M" ? M : throw("Unrecognized Gender") ) ;
} 

void to_json(json &j,  const Client &client ) {
	client.toJson(j);
}

void from_json(const json &j, Client &client) {
	client = Client(j);
}

string genre(const gender g ) {
	return  g==F ? "F" : ( g==M ? "M" : throw("Unrecognized Gender") ) ;
}

gender genre(const string g ) {
	return  g=="F" ? F : ( g=="M" ? M : throw("Unrecognized Gender") ) ;
} 







