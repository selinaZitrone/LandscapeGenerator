#include "InputOutput.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

/********************************************//**
 *  Check if json file landscapeUserInput.json exists
 * and read it, check soil percentage and plant percantage
 ***********************************************/
nlohmann::json InputOutput::readLandscapeUserInput()
{
	ifstream userInput("landscapeUserInput.json");
	if (userInput.fail()) {
		throw runtime_error("Error: File landscapeUserInput.json could not be opened, please check if it exists");
	}
	nlohmann::json landscapeData;
	userInput >> landscapeData;
	// check if soil percentage is 100%
	checkSoilPercentage(landscapeData);
	return landscapeData;
}

/********************************************//**
 * check if sum of soil percentage = 100, sum of plant and crust < = 100,
 * if not give warning message
 ***********************************************/
void InputOutput::checkSoilPercentage(json inputToTest)
{
	int percentageSum = 0;
	for (auto& element : inputToTest["LandscapeElements"]) {
		if (element["category"] == "soil") {
			percentageSum += element["coverPercentage"];
		}
	}
	// give a warning if percentages are too high
	if (percentageSum != 100) {
		cerr << "WARNING: Sum of percentage of soil coverage should be 100% but is 90% " << percentageSum << " instead" << endl;
		cerr << "Your output might not make sense!" << endl;
	}
}

void InputOutput::writeMapToFile()
{
}
