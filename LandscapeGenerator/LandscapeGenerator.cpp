// LandscapeGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "InputOutput.h"
#include "RandomLandscape.h"
#include "LandGenDataStructures.h"
#include "LandGenUtilities.h"

using namespace std;

#include <filesystem>
namespace fs = std::filesystem;



int main()
{
	char path[120];
	cout << "Please insert the path of the folder containing the data in json format: " << endl;
	cin.getline(path, sizeof(path));
	cout << " " << endl;

	try {
		cout << "Found following files:" << endl;
		cout << " " << endl;
		for (const auto & entry : fs::directory_iterator(path)) {
			
			if (entry.path().extension() == ".json") {
				std::cout << entry.path().filename() << std::endl;
			}
		}
	}
	catch (const runtime_error& e) {
		cout << " " << endl;
		cerr << e.what() << endl;;
		cout << " " << endl;
		return -1;
	}

	cout << "Please choose the name of the file you would like to open (without extension): " << endl;
	char nameOfJson[100];
	cin.getline(nameOfJson, sizeof(nameOfJson));



    // read a json file
    nlohmann::json landscapeElements;

	string a(path);
	string b(nameOfJson);
	string toLoad = a + "\\" + b + ".json";

    try {
        landscapeElements = InputOutput::readLandscapeUserInput(toLoad);
    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;;
        return -1;
    }

	cout << endl << "Please define the dimension of the surface (one integer to define the size of one side of the square area)" << endl;
   
	int areaSize;
	cin >> areaSize;
	cout << endl;

	RandomLandscape firstRandom(areaSize);
	firstRandom.generateLandscape(landscapeElements);

	map<string, mapStruct> soilMaps = firstRandom.getAllSoilMaps();
	map<string, mapStruct> crustMaps = firstRandom.getAllCrustMaps();
	map<string, mapStruct> vascularMaps = firstRandom.getAllVascularMaps();

	printMaps(soilMaps, "SOIL MAPS");
	printMaps(crustMaps, "CRUST MAPS");
	printMaps(vascularMaps, "VASCULAR MAPS");


	//cout << printTable(firstRandom.getSoilMap("sS").valuesVector, firstRandom.getSize());
	//cout << " - - - " << endl;
	//cout << printTable(firstRandom.getSoilMap("lS").valuesVector, firstRandom.getSize());
	//cout << " - - - " << endl;
	//cout << printTable(firstRandom.getSoilMap("kA").valuesVector, firstRandom.getSize());
	//cout << " - - - " << endl;
	//cout << "my size: " << firstRandom.getSize() << endl;
	//cout << " - - - " << endl;
	//cout << printTable(firstRandom.getCrustMap("moss").valuesVector, firstRandom.getSize()) << endl;
	//cout << " - - - " << endl;
	//cout << printTable(firstRandom.getCrustMap("lichen").valuesVector, firstRandom.getSize()) << endl;
	//cout << " - - - " << endl;
	//cout << printTable(firstRandom.getVascularMap("shrub").valuesVector, firstRandom.getSize()) << endl;
	//cout << " - - - " << endl;
	//cout << printTable(firstRandom.getVascularMap("alessio").valuesVector, firstRandom.getSize()) << endl;
	//cout << " - - - " << endl;
}
