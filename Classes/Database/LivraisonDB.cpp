#include "../../Headers/LivraisonDB.h"
#include "../../Headers/Livraison.h"

using namespace std;
using json = nlohmann::json;

LivraisonDB::LivraisonDB(){}
LivraisonDB::LivraisonDB(std::string nom, std::string fichier, std::string cle ) : Database(nom, fichier, cle) {}

void LivraisonDB::add(nlohmann::json info ) {
	info["ref"] = _JSON["index"].get<unsigned>();
	_JSON["index"] = _JSON["index"].get<unsigned>() +1;
	Livraison livraison = Livraison(info);
	_JSON[_nom].push_back(livraison);
	save();
}

