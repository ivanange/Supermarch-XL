#include "./Headers/XL.h"

#include<iostream>

using namespace std;
using json = nlohmann::json;


int main() {

	try {
		
		
		
		XL marche;
		json j = marche.Clients._JSON;
		Date date("05/04/2000");
		Client client( { { "numero", 3}, { "nom", "Bouh"}, {"prenom", "Ivan"}, {"dateDeNaissance", "05/04/2000"}, {"genre", "M"}});
		cout<<client.nom()<<"\t"<<date.toString()<<"\t"<<j;
		
		
		
	}
	catch(char const* const& err) {
		string error = err;
		cout<<error;
	}
	
	
}
