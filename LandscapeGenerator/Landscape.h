#pragma once
#include <vector>
#include <utility>
#include "json.hpp"
#include <variant>
#include <map>


using namespace std;

class Landscape
{
protected:
	int size;

	struct mapStruct {
		string name;
		vector<variant<double, bool>> valuesVector;
	};

	map<string, mapStruct> soilMaps;
	map<string, mapStruct> crustMaps;
	map<string, mapStruct> vascularMaps;
	vector<double> infiltrationMap;
	vector<double> roughnessMap;

public:
	virtual void generateLandscape(nlohmann::json landscapeElements) = 0;
	double calculateInfiltration();
	double calcualteRoughness();

};

