#ifndef DEF_DONNES
#define DEF_DONNES

#include<string>
#include<vector>
#include<map>
#include <functional>
#include<fstream>


#include "json.hpp"
#include "utility.h"

class Database {
	
	protected:
		nlohmann::json  _JSON;
		std::string _nom, _fichier, _cle;
		
	private:
		std::ofstream _stream;
		JSONIt findref(std::string key, std::string value);
		bool _isEmpty() const;

	public:
		Database();
		Database(std::string nom, std::string fichier, std::string cle );
		nlohmann::json find(unsigned id) ;
		nlohmann::json find(std::string id) ;
		void update(unsigned id, nlohmann::json info );
		void update(std::string id, nlohmann::json info );
		nlohmann::json findBY(std::string key, std::string value) ;
		nlohmann::json findBY(std::string key, unsigned value);
		nlohmann::json findAll() const;
		nlohmann::json findIf( std::function<bool(nlohmann::json)>filter) ;
		void save();
		void init(std::string nom, std::string fichier, std::string cle );
		nlohmann::json toVector( nlohmann::json jsonmap ) const;
		void remove(unsigned id);
		void remove(std::string id); 
		
	
};

#endif
