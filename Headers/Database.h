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
		std::string _nom, _fichier, _cle;
		std::ofstream _stream;
		nlohmann::json _JSON;
		nlohmann::json* findref(unsigned id) const;

	public:
		Database(std::string nom, std::string fichier, std::string cle );
		nlohmann::json find(unsigned id) const;
		void update(unsigned id, nlohmann::json info );
		nlohmann::json findBY(std::string key, std::string value) const;
		nlohmann::json findBY(std::string key, unsigned value) const;
		nlohmann::json findAll() const;
		nlohmann::json findIf( std::function<bool(nlohmann::json)>filter) const;
		void save();
		
	
	
};

#endif
