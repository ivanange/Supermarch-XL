#ifndef DEF_COMMANDE
#define DEF_COMMANDE

#include<string>
#include<vector>

#include "json.hpp"
#include "utility.h"

enum state { livrer, en_cours};

class Command {
	
	public:
		
	Command();
	Command(nlohmann::json info);
	unsigned numCommand() const;
	unsigned numClient() const;
	void numClient(int numClient);
	state etat() const;
	void etat( state etat);
	unsigned refArticle() const;
	void refArticle(int refArticle);
	unsigned quantite() const;
	void quantite( int quantite);
	void fromJson( const nlohmann::json &JSON);
	void toJson(nlohmann::json &JSON);
		
	
	private:

	unsigned _numCommand, _numClient, _refArticle, _quantite;
	state _etat;
	void _init(nlohmann::json info);

};

void to_json(nlohmann::json &j,  const Command &commande );
void from_json(const nlohmann::json &j, Command &commande);
typedef std::vector<Command>::iterator CommandIt ; // Command Iterator

#endif
