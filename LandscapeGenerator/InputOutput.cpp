#include "InputOutput.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

/********************************************//**
 *  Check if json file landscapeUserInput.json exists
 * and read it
 ***********************************************/
nlohmann::json InputOutput::readLandscapeUserInput()
{
	ifstream userInput("landscapeUserInput.json");
	if (userInput.fail()) {
		throw runtime_error("File landscapeUserInput.json could not be opened, please check if it exists");
	}
	nlohmann::json landscapeData;
	userInput >> landscapeData;
	return landscapeData;
}

void InputOutput::writeMapToFile()
{
}
