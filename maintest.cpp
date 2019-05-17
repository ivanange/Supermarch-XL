#include "./Headers/XL.h"

#include<iostream>

using namespace std;
using json = nlohmann::json;


int main() {

	try {
		
		XL marche;
		marche.Clients.add({  { "nom", "Bouh"}, {"prenom", "Ivan"}, {"dateDeNaissance", "05/04/2000"}, {"genre", "M"} } );
		Clients.find(5);

		
		
		
	}
	catch(char const* const& err) {
		string error = err;
		cout<<error;
	}
	
	
}
