#include "InputOutput.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

/********************************************//**
 *  Check if json file landscapeUserInput.json exists
 * and read it, check soil percentage and plant percantage
 ***********************************************/
nlohmann::json InputOutput::readLandscapeUserInput(string fileName)
{
	ifstream userInput(fileName);
	if (userInput.fail()) {
		throw runtime_error("Error: File " + fileName + " could not be opened, please check if it exists");
	}
	nlohmann::json landscapeData;
	userInput >> landscapeData;
	// check if soil percentage is 100%
	checkSoilPercentage(landscapeData);
	checkPlantAndCrustPercentage(landscapeData);
	cout << "File " + fileName + " has been loaded." << endl << endl;
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
		cerr << "WARNING: Sum of percentage of soil coverage has to be 100%" << percentageSum << " instead" << endl;
		cerr << "Your output might not make sense!" << endl;
	}
}

void InputOutput::checkPlantAndCrustPercentage(json inputToTest)
{
	int vascularPercentage = 0;
	int crustPercentage = 0;
	for (auto& element : inputToTest["LandscapeElements"]) {
		if (element["category"] == "vascular") {
			vascularPercentage += element["coverPercentage"];
		}
		if (element["category"] == "crust") {
			crustPercentage += element["coverPercentage"];
		}
	}
	// give a warning if percentages are too high
	if (vascularPercentage + crustPercentage > 100) {
		cerr << "WARNING: Percentage sum of crust and vascular cannot exceed 100%" << vascularPercentage + crustPercentage << " instead" << 
			"(crustcover: " << crustPercentage << "%, vascular cover: "<< vascularPercentage << ")" << endl;
		cerr << "Your output might not make sense!" << endl;
	}
	if (vascularPercentage + crustPercentage > 100) {
		cout << "Total crust cover: " << crustPercentage << "%, total vascular cover: " << vascularPercentage << "%" << endl;
	}

}

void InputOutput::writeMapToFile()
{
}
