#ifndef DEF_CLIENT
#define DEF_CLIENT

#include<string>
#include<vector>
#include <functional>

#include "Date.h"
#include "json.hpp"
#include "utility.h"

/*
class Command;
class ArticleDB;
class CommandDB;
*/
class Article;



enum gender { F, M};

class Client {
	
	public:
		
	Client();
	Client(nlohmann::json info);
	Client(nlohmann::json info, ArticleDB* articles, CommandDB* commandes );
	unsigned numero() const;
	std::string nom() const;
	void nom( std::string nom);
	std::string prenom() const;
	void prenom( std::string prenom);
	std::string date() const;
	void date( std::string dateDeNaissance);	
	gender genre() const;
	void genre( gender genre);
	std::vector<Article> getArticles();
	std::vector<Command> getOngoingCommands();
	void fromJson( const nlohmann::json &JSON);
	void toJson(nlohmann::json &JSON);
	
	
	private:
		
	unsigned _numero;
	std::string _nom, _prenom;
	Date _dateDeNaissance;
	gender _genre;
	ArticleDB* _articles;
	CommandDB* _commandes;
	void _init(nlohmann::json info);

};

typedef std::vector<Client>::iterator ClientIt ; // Client Iterator

#endif
