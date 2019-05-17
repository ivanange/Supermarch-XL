#include "../../Headers/Database.h"


using namespace std;
using json = nlohmann::json;

Database::Database(){}
Database::Database(std::string nom, std::string fichier, std::string cle ) {
	init( nom,  fichier,  cle);	
}


void Database::init(std::string nom, std::string fichier, std::string cle ) {
	_nom = nom;
	_fichier = fichier;
	_cle = cle;

	if(_isEmpty()){ json _JSON; _JSON["index"]=0; } 
	else {
		std::ifstream flux(_fichier.c_str());
		if(flux) {	flux>>_JSON;	}
		else {	throw ("Cannot open file");	}
	}

}


nlohmann::json Database::find(unsigned id)  {
	return find(to_string(id));
}

nlohmann::json Database::find(std::string id)  {
	return _JSON[_nom][id];
}

void Database::update(std::string id, nlohmann::json info ) {
	for( JSONIt it = info.begin(); it != info.end(); it++ ) {
		_JSON[_nom][id][it.key()] = it.value();
	}
	save();	
}

void Database::update( unsigned id, nlohmann::json info ) {
	update(to_string(id), info);
}

void Database::remove(std::string id) {
	_JSON[_nom].erase(id);
}

void Database::remove(unsigned id) {
	remove(to_string(id));
}


nlohmann::json Database::findBY(std::string key, std::string value)  {
	json result;
	for( JSONIt it = _JSON[_nom].begin(); it!=_JSON[_nom].end(); it++ ) {
		if( (*it)[key] == value) { result.push_back(*it); }
	}
	return result;
}

nlohmann::json Database::findBY(std::string key, unsigned value)  {
	json result;
	for( JSONIt it = (_JSON[_nom]).begin(); it!=_JSON[_nom].end(); it++ ) {
		if( (*it)[key].get<unsigned>() == value) { result.push_back(*it); }
	}
	return result;	
}



nlohmann::json Database::findAll() const {
	return toVector(_JSON[_nom]);
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

nlohmann::json Database::toVector( nlohmann::json jsonmap ) const{
	std::vector<json> values;
	map<string, json> jmap = jsonmap.get<map<string, json>>();
	std::transform(
    	jmap.begin(),
    	jmap.end(),
    	std::back_inserter(values),
    	[](const std::pair<string, json> cell ){return cell.second;});
    	
    json result = values;
    return result;
}







