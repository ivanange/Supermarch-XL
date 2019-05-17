#include "./Headers/XL.h"

#include<iostream>

using namespace std;
using json = nlohmann::json;


int main() {

	try {
		
		XL marche;
		marche.Clients.add({  { "nom", "Bouh"}, {"prenom", "Ivan"}, {"dateDeNaissance", "05/04/2000"}, {"genre", "M"} } );
		Client client = marche.Clients.find(0).get<Client>();
		//json test = client;
		//cout<<test;

		
		
		
	}
	catch(char const* const& err) {
		string error = err;
		cout<<error;
	}
	
	
}
