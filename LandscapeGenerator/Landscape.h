#pragma once
#include <vector>

using namespace std;

class Landscape
{
private:
	int size;

	vector<vector<bool>> soilMaps;
	vector<vector<double>> crustMaps;
	vector<vector<double>> vascularMaps;

	vector<double> infiltrationMap;
	vector<double> roughnessMap;

public:
	virtual void generateLandscape() = 0;
	double calculateInfiltration();
	double calcualteRoughness();

};

