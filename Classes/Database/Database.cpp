#include "../../Headers/Database.h"

using namespace std;
using json = nlohmann::json;


Database::Database(std::string nom, std::string fichier, std::string cle ) {
	_nom = nom;
	_fichier = fichier;
	_cle = cle;
	std::ifstream flux(_fichier.c_str());
	if(flux) {
		flux>>_JSON;
	}
	else {
		throw ("Cannot open file");
	}
	
	stream = std::ofstream(_fichier.c_str());
	if( !(stream)) { throw ("Could not write to file");	}
	
}

nlohmann::json* Database::findref(std::string key, std::string value) const {
	for( JSONIt it = _JSON[_nom].begin(); it!=_JSON[_nom].end(); it++ ) {
		if( *it[key] = value) { return it; }
	}	
}


nlohmann::json Database::find(unsigned id) const {
	return *(findref(_cle, id));
}

void Database::update(unsigned id, nlohmann::json info ) {
	json target = findref(_cle, id);

	for( JSONIt it = info.begin(); it != info.end(); it++ ) {
		*target[it.key()] = it.value();
	}
	save();	
}

nlohmann::json Database::findBY(std::string key, std::string value) const {
	json result = {};
	for( JSONIt it = _JSON[_nom].begin(); it!=_JSON[_nom].end(); it++ ) {
		if( *it[key] = value) { result.push_back(*it); }
	}
}

nlohmann::json Database::findBY(std::string key, unsigned value) const {
	json result = {};
	for( JSONIt it = _JSON[_nom].begin(); it!=_JSON[_nom].end(); it++ ) {
		if( *it[key] = value) { result.push_back(*it); }
	}	
}

nlohmann::json Database::findAll() const {
	return _JSON[_nom];
}

nlohmann::json Database::findIf( bool (*filter)(nlohmann::json)) const {
	json result = {};
	for( JSONIt it = _JSON[_nom].begin(); it!=_JSON[_nom].end(); it++ ) {
		if( filter(*it)) { result.push_back(*it); }
	}
	return result;
}

void Database::save() {
	_stream<<_JSON;
}









