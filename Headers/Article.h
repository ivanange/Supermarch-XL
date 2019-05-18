#ifndef DEF_ARTICLE
#define DEF_ARTICLE

#include<string>
#include<vector>
#include <functional>
#include <algorithm>

#include "json.hpp"
#include "utility.h"


class Client;
class CommandDB;
class ClientDB;



class Article {
	
	public:
		
	Article();
	Article(nlohmann::json info);
	Article(nlohmann::json info, ClientDB* clients, CommandDB* commandes );
	unsigned ref() const;
	std::string label() const;
	void label( std::string label);
	float prix() const;
	void prix( float prix);
	unsigned quantite() const;
	void quantite( unsigned quantite);	
	unsigned seuil() const;
	void seuil( unsigned seuil);
	std::vector<Client> getClients();
	void toJson(nlohmann::json &JSON) const;
	
	
	private:
		
	unsigned _ref, _quantite, _seuil;
	std::string _label;
	float _prix;
	ClientDB*  _clients;
	CommandDB* _commandes;
	void _init(nlohmann::json info);
	 

};

void to_json(nlohmann::json &j,  const Article &article );
void from_json(const nlohmann::json &j, Article &article);
typedef std::vector<Article>::iterator ArticleIt ; // Article Iterator

#endif
