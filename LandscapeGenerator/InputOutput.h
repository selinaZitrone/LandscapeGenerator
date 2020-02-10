#pragma once
#include "json.hpp"
using namespace std;
#include <string>
#include "LandGenDataStructures.h"

using json = nlohmann::json;

class InputOutput
{
public:
	static nlohmann::json readLandscapeUserInput(string fileName);
	static void checkSoilPercentage(json inputToTest);
	static void checkPlantAndCrustPercentage(json inputToTest);
	static void writeMapToFile(mapStruct map);
	static void writeMapsToFile(map<string, mapStruct> maps);
};

