#pragma once
#include <vector>
#include <utility>
#include "json.hpp"

using namespace std;

class Landscape
{
protected:
	int size;

	vector< pair <string, vector<bool>> > soilMaps;
	vector<pair <string, vector<double>>> crustMaps;
	vector<pair <string, vector<double>>> vascularMaps;

	vector<double> infiltrationMap;
	vector<double> roughnessMap;

public:
	virtual void generateLandscape(nlohmann::json landscapeElements) = 0;
	double calculateInfiltration();
	double calcualteRoughness();

};

