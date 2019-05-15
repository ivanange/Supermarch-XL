#ifndef DEF_DONNES
#define DEF_DONNES

#include<string>
#include<vector>
#include <functional>
#include<fstream>


#include "json.hpp"
#include "utility.h"

class Database {
	
	private:
		std::ofstream _stream;
		JSONIt findref(std::string key, std::string value);
		JSONIt findref(std::string key, unsigned value);

	public:
		nlohmann::json _JSON;
		std::string _nom, _fichier, _cle;
		Database();
		Database(std::string nom, std::string fichier, std::string cle );
		nlohmann::json find(unsigned id) ;
		void update(unsigned id, nlohmann::json info );
		nlohmann::json findBY(std::string key, std::string value) ;
		nlohmann::json findBY(std::string key, unsigned value);
		nlohmann::json findAll() const;
		nlohmann::json findIf( std::function<bool(nlohmann::json)>filter) ;
		void save();
		
	
	
};

#endif
