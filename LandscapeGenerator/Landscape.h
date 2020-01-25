#pragma once
#include <vector>
#include "json.hpp"

using namespace std;

class Landscape
{
protected:
	int size;

	vector<vector<bool>> soilMaps;
	vector<vector<double>> crustMaps;
	vector<vector<double>> vascularMaps;

	vector<double> infiltrationMap;
	vector<double> roughnessMap;

public:
	virtual void generateLandscape(nlohmann::json landscapeElements) = 0;
	double calculateInfiltration();
	double calcualteRoughness();

};

