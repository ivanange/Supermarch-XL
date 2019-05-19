#include "../../Headers/ArticleDB.h"
#include "../../Headers/Article.h"

using namespace std;
using json = nlohmann::json;

ArticleDB::ArticleDB(){}
ArticleDB::ArticleDB(std::string nom, std::string fichier, std::string cle ) : Database(nom, fichier, cle) {
}

void ArticleDB::add(nlohmann::json info ) {
	string id = to_string(_JSON["index"].get<unsigned>() );
	info["ref"] = _JSON["index"].get<unsigned>();
	_JSON["index"] = _JSON["index"].get<unsigned>() +1;
	Article articles = Article(info);
	_JSON[_nom][id] = articles;
	save();
}

void ArticleDB::add(const Article &article ) {
	json jarticle = article;
	ArticleDB::add(jarticle);
}

