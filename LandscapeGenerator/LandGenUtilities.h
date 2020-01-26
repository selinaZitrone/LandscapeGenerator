#pragma once

using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "InputOutput.h"
#include "RandomLandscape.h"
#include "LandGenDataStructures.h"

#include <filesystem>
namespace fs = std::filesystem;

string askForPath() {
	char path[120];

	cout << "Please insert the path of the folder containing the data in json format: " << endl;
	cin.getline(path, sizeof(path));
	cout << " " << endl;

	try {
		for (const auto & entry : fs::directory_iterator(path)) {

			if (entry.path().extension() == ".json") {
				string jsonPath(path);
				if (jsonPath != "") {
					jsonPath += "\\";
				}
				return jsonPath;
			}
		}
		cout << "no json file found, please try with another path" << endl;
		return askForPath();
	}
	catch (const runtime_error& e) {
		cout << " " << endl;
		cerr << e.what() << endl << endl;
		cout << " " << endl;
		return askForPath();
	}
}

nlohmann::json askForJsonName(string jsonPath) {
	cout << "Found following files:" << endl;
	cout << " " << endl;
	for (const auto & entry : fs::directory_iterator(jsonPath)) {

		if (entry.path().extension() == ".json") {
			std::cout << entry.path().filename() << std::endl;
		}
	}
	cout << endl << "Please choose the name of the file you would like to open (without extension): " << endl;

	char nameOfJson[120];

	cin.getline(nameOfJson, sizeof(nameOfJson));

	nlohmann::json landscapeElements;

	string b(nameOfJson);
	string toLoad = jsonPath + b + ".json";

	try {
		landscapeElements = InputOutput::readLandscapeUserInput(toLoad);
		return landscapeElements;
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl << endl;
		return askForJsonName(jsonPath);
	}
}

unsigned int askForAreaSize() {
	unsigned int areaSize;
	cout << endl << "Please define the dimension of the surface (one integer to define the size of one side of the square area)" << endl;
	cin >> areaSize;
	if (cin.good()) {
		return areaSize;
	}
	else {
		cout << endl;
		cout << "Invalid entry, it has to be a positive integer." << endl << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		return askForAreaSize();
	}
}

string printTable(vector<double> toPrint, int sideSize) {
	int side = sideSize;
	int rowCounter = 0;
	string toReturn = "";
	for (int i = 0; i < toPrint.size(); i++) {
		toReturn += " " + to_string(toPrint[i]);
		rowCounter++;
		if (rowCounter == side) {
			toReturn += "\n";
			rowCounter = 0;
		}
	}
	return toReturn;

}

void printMaps(map<string, mapStruct> mapToPrint, string title) {
	cout << endl << endl;
	cout << title << endl << endl;
	cout << "---" << endl;
	for (pair<string, mapStruct> t : mapToPrint) {
		cout << "type: " << t.second.name << endl;
		cout << "---" << endl;
		cout << printTable(t.second.valuesVector, t.second.size) << endl;
		cout << "---" << endl << endl;
	}
}

