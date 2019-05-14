#include "../../Headers/Livraison.h"

using namespace std;
using json = nlohmann::json;


Livraison::Livraison(){}

Livraison::Livraison(nlohmann::json info) {
	_init(info);
}

unsigned Livraison::ref() const {
	return _ref;
}
	
unsigned Livraison::numCommand() const {
	return _numCommand
}
	
void Livraison::numCommand(int numCommand) {
	_numCommand = numCommand;
}
	
unsigned Livraison::quantite() const {
	return quantite;
}

void Livraison::quantite( int quantite) {
	_quantite = quantite;
}
	
unsigned Livraison::numClient() const {
	return _numClient;
}
	
void Livraison::numClient(int numClient) {
	_numClient = numClient;
}

void Livraison::toJson(nlohmann::json &JSON) {
	JSON = { {"ref", _ref},
	{"numCommand", _numCommand},
	{"quantite", _quantite},
	{"numClient", _numClient } };	
}


	
void Livraison::_init(nlohmann::json info) {
	try {
		_numCommand  = (unsigned)info["numCommand"].get<int>();
		_ref  = (unsigned)info["ref"].get<int>();
		_numClient  = (unsigned)info["numClient"].get<int>();
		_quantite  = (unsigned)info["quantite"].get<int>();
	}
	catch() {
		throw("Invalid property value");
	}		
}
	
void to_json(json &j,  const Livraison &livraison ) {
	livraison.toJson(j);
}

void from_json(const json &j, Livraison &livraison) {
	livraison = Livraison(j);
}

	
	