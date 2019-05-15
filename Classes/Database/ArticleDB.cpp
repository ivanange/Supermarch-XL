#include "../../Headers/ArticleDB.h"
#include "../../Headers/Article.h"

using namespace std;
using json = nlohmann::json;

ArticleDB::ArticleDB(){}
ArticleDB::ArticleDB(std::string nom, std::string fichier, std::string cle ):Database(nom, fichier, cle) {}

void ArticleDB::add(nlohmann::json info ) {
	info["ref"] = _JSON["index"].get<int>();
	_JSON["index"] = _JSON["index"].get<int>() +1;
	Article articles = Article(info);
	_JSON[_nom].push_back(articles);
	save();
}

void ArticleDB::remove(unsigned id) {
	vector<Article> articles = _JSON[_nom].get<vector<Article>>();
	for( ArticleIt it = articles.begin(); it != articles.end(); it++ ) {
		if( (*it).ref() == id ) { articles.erase(it); break;	}
	}
	_JSON[_nom] = articles;
	save();
}
