#include "../../Headers/Database.h"

#include<iostream>

using namespace std;
using json = nlohmann::json;

Database::Database(){}
Database::Database(std::string nom, std::string fichier, std::string cle ) {
	init( nom,  fichier,  cle);	
}


JSONIt Database::findref(std::string key, std::string value)  {
	for( JSONIt it = _JSON[_nom].begin(); it!=_JSON[_nom].end(); it++ ) {
		if( (*it)[key] == value) { return it; }
	}	
}

JSONIt Database::findref(std::string key, unsigned value)  {
	for( JSONIt it = _JSON[_nom].begin(); it!=_JSON[_nom].end(); it++ ) {
		if( (*it)[key] == value) { return it; }
	}	
}



nlohmann::json Database::find(unsigned id)  {
	return *(findref(_cle, id));
}

void Database::update(unsigned id, nlohmann::json info ) {
	JSONIt target = findref(_cle, id);

	for( JSONIt it = info.begin(); it != info.end(); it++ ) {
		(*target)[it.key()] = it.value();
	}
	save();	
}

nlohmann::json Database::findBY(std::string key, std::string value)  {
	json result = {};
	for( JSONIt it = _JSON[_nom].begin(); it!=_JSON[_nom].end(); it++ ) {
		if( (*it)[key] == value) { result.push_back(*it); }
	}
}

nlohmann::json Database::findBY(std::string key, unsigned value)  {
	json result = {};
	for( JSONIt it = (_JSON[_nom]).begin(); it!=_JSON[_nom].end(); it++ ) {
		if( (*it)[key] == value) { result.push_back(*it); }
	}	
}

nlohmann::json Database::findAll() const {
	return _JSON[_nom];
}

nlohmann::json Database::findIf( std::function<bool(nlohmann::json)>filter)  {
	json result = {};
	for( JSONIt it = _JSON[_nom].begin(); it!=_JSON[_nom].end(); it++ ) {
		if( filter(*it)) { result.push_back(*it); }
	}
	return result;
}

void Database::save() {
	_stream.open(_fichier.c_str());
	_stream<<_JSON;
	_stream.close();
}


bool Database::_isEmpty() const {
	ifstream file(_fichier.c_str());
	string test;
    file.seekg(0,ios::end);
    size_t size = file.tellg();
    file.close();
    return size==0 ? true : false;
}

void Database::init(std::string nom, std::string fichier, std::string cle ) {
	_nom = nom;
	_fichier = fichier;
	_cle = cle;
	
	
	
	if(_isEmpty()){ 
		vector<json> v;
		_JSON = {	{_nom, v },  {"index", 0} }; 
	}
	else {
		std::ifstream flux(_fichier.c_str());
		if(flux) {
			flux>>_JSON;
			flux.close();

		}
		else {
			throw ("Cannot open file");
		}
	}

}







