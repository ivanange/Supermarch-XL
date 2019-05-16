#include "../json.hpp"
#include<iostream>
#include<string>

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
	


int main() {

	testeur T;
	cout<<T.f<<T.g;
	
	enum genre {M, F};
	cout<<"livre"<<"\n";
	
	json j1 = { {"name", 1}, { "j2", 2} };
	json j2 = { {"name2", 5}, { "j2", 8} };
	int n = j1["name"].get<unsigned>();
	std::cout<<j1<<"\n";
	j1["j2"] = j2;
	cout<<j1<<"\n";
	
for (json::iterator it = j1["j2"].begin(); it != j1["j2"].end(); ++it) {
  std::cout << *it << '\n';
}

	
}
