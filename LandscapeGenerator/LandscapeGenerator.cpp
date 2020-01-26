// LandscapeGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "InputOutput.h"
#include "RandomLandscape.h"
#include "LandGenDataStructures.h"
#include "LandGenUtilities.h"

using namespace std;

int main()
{
	string jsonPath = askForPath();

	nlohmann::json landscapeElements = askForJsonName(jsonPath);
	
	unsigned int areaSize = askForAreaSize();
	
	RandomLandscape firstRandom(areaSize);

	firstRandom.generateLandscape(landscapeElements);

	map<string, mapStruct> soilMaps = firstRandom.getAllSoilMaps();
	map<string, mapStruct> crustMaps = firstRandom.getAllCrustMaps();
	map<string, mapStruct> vascularMaps = firstRandom.getAllVascularMaps();

	printMaps(soilMaps, "SOIL MAPS");
	printMaps(crustMaps, "CRUST MAPS");
	printMaps(vascularMaps, "VASCULAR MAPS");
}
