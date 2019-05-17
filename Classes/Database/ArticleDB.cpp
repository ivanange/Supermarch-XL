#include "../../Headers/ArticleDB.h"
#include "../../Headers/Article.h"

using namespace std;
using json = nlohmann::json;

ArticleDB::ArticleDB(){}
ArticleDB::ArticleDB(std::string nom, std::string fichier, std::string cle ) : Database(nom, fichier, cle) {
}

void ArticleDB::add(nlohmann::json info ) {
	info["ref"] = _JSON["index"].get<unsigned>();
	_JSON["index"] = _JSON["index"].get<unsigned>() +1;
	Article articles = Article(info);
	_JSON[_nom].push_back(articles);
	save();
}

