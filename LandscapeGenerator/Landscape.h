#pragma once
#include <vector>
#include <utility>
#include "json.hpp"
#include <variant>
#include <map>
#include "LandGenDataStructures.h"


using namespace std;

class Landscape
{
protected:
	int size;
	map<string, mapStruct> soilMaps;
	map<string, mapStruct> crustMaps;
	map<string, mapStruct> vascularMaps;
	vector<double> infiltrationMap;
	vector<double> roughnessMap;

public:
	Landscape(){
		this->size = 10;
	}
	Landscape(int sideSize) {
		this->size = sideSize;
	}

	virtual void generateLandscape(nlohmann::json landscapeElements) = 0;

	int getSize() { return this->size; }

	mapStruct getSoilMap(string soilType);
	map<string, mapStruct> getAllSoilMaps();
	mapStruct getCrustMap(string crustType);
	map<string, mapStruct> getAllCrustMaps();
	mapStruct getVascularMap(string vascularType);
	map<string, mapStruct> getAllVascularMaps();

	double calculateInfiltration();
	double calcualteRoughness();

};

