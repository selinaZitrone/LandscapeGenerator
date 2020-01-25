#pragma once
#include "json.hpp"

using json = nlohmann::json;

class InputOutput
{
public:
	static nlohmann::json readLandscapeUserInput();
	static void checkSoilPercentage(json inputToTest);
	static void checkPlantAndCrustPercentage(json inputToTest);
	static void writeMapToFile();

};
