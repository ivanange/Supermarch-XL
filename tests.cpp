#include "../json.hpp"
#include<iostream>
#include<fstream>
#include<string>
#include<map>

using  json = nlohmann::json;
using namespace std;

class tete {
	public:
		int g;
	tete() {
		this->g=9;
	}
};

class testeur : public tete {
	public:
	int f;
};

enum  gender { F, M};
	
string genre(const gender g ) {
	return  g==F ? "F" : ( g==M ? "M" : throw("Gender not recognized") ) ;
}

gender genre(const string &g ) {
	return  g=="F" ? F : ( g=="M" ? M : throw("Gender not recognized") ) ;
}

int main() {
	



	gender sexe = genre("N");

	map<string, int> dico;
	dico["a"] = 1;
	dico["b"] = 2;
	
	json dic;
	dic["mondico"] =dico;
	cout<<"\t"<<to_string(dic["mondico"]["b"].get<int>())<<"\t";
	ofstream file("test.txt");
	file<<dic;
	//dic["mondico"].erase("a");
	//dic["mondico"].erase("b");
	cout<<(dic["mondico"].empty());
	json::iterator jit = dic["mondico"].begin();
	cout<<endl<<endl<<*jit<<endl<<endl;
	cout<<dic<<endl;
	testeur T;
	cout<<T.f<<T.g;
	
	enum genre {M, F};
	cout<<"livre"<<"\n";
	
	json j1 = { {"name", 1}, { "j2", 2} };
	json j2 = { {"name2", 5}, { "j2", 8} };
	unsigned n = j1["name"].get<unsigned>();
	std::cout<<j1<<"\n";
	j1["j2"] = j2;
	cout<<j1<<"\n";
	
for (json::iterator it = j1["j2"].begin(); it != j1["j2"].end(); ++it) {
  		std::cout<<1 << *it << '\n';
}

	
}
