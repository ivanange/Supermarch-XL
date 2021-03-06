#ifndef DEF_LIVRAISON
#define DEF_LIVRAISON

#include<string>
#include<vector>

#include "json.hpp"
#include "utility.h"

class Livraison {
	
	public:
		
	Livraison();
	Livraison(nlohmann::json info);
	unsigned ref() const;
	unsigned numCommand() const;
	void numCommand(unsigned numCommand);
	unsigned quantite() const;
	void quantite( unsigned quantite);
	unsigned numClient() const;
	void numClient(unsigned numClient);
	void toJson(nlohmann::json &JSON) const;

		
	
	private:

	unsigned _ref, _numCommand, _quantite, _numClient;
	void _init(nlohmann::json info);

};

void to_json(nlohmann::json &j,  const Livraison &livraison );
void from_json(const nlohmann::json &j, Livraison &livraison);
typedef std::vector<Livraison>::iterator LivraisonIt ; // Livraison Iterator

#endif
