#include "RandomLandscape.h"
#include <algorithm>
#include <random>
#include <chrono>

#include <stdio.h>
#include <stdlib.h>
#include <ctime>

#include <iostream>

using namespace std;

/********************************************//**
 *  generate the maps for soil, crust and vascular
 *	with the specified user in put and populate the landscapte
 *	with one map for each type of soil, crust and vascular
 ***********************************************/
void RandomLandscape::generateLandscape(json landscapeElements)
{
	CreateSoilMaps(landscapeElements);

	// calculate number of cells
	int cells = this->size * this->size;

	// get index of all types in category and their distribution
	map<string, double> crustTypes = getIndexOfCategory(landscapeElements, "crust", cells);
	map<string, double> vascularTypes = getIndexOfCategory(landscapeElements, "vascular", cells);

	// popuplate the mapStruct for crusts (with 0)

	for (pair<string, double> t : crustTypes) {
		mapStruct newMap;
		newMap.size = this->size;
		// assign the name in the struct
		newMap.name = t.first;
		// put the struct in the map, with key = name
		this->crustMaps[t.first] = newMap;
		this->crustMaps[t.first].valuesVector.insert(
			this->crustMaps[t.first].valuesVector.begin(), cells, 0
		);
	}


	// popuplate the mapStruct for vascular vegetation (with 0)

	for (pair<string, double> t : vascularTypes) {
		mapStruct newMap;
		newMap.size = this->size;
		// assign the name in the struct
		newMap.name = t.first;
		// put the struct in the map, with key = name
		this->vascularMaps[t.first] = newMap;
		this->vascularMaps[t.first].valuesVector.insert(
			this->vascularMaps[t.first].valuesVector.begin(), cells, 0
		);
		
	}

	// this will be used to check the total coverage
	vector<double> coverageOverview;
	coverageOverview.insert(
		coverageOverview.begin(), cells, 0
	);

	vector<size_t> indexesLowerThanOne;
	for (int i = 0; i < coverageOverview.size(); i++) {
		indexesLowerThanOne.push_back(i);
	}

	// populate the crust maps with random cover values

	for (pair<string, double> t : crustTypes) {
		while (t.second > 0 && indexesLowerThanOne.size() > 0) {	// while there is still cover to distribute and the coverage is not full
			double toDistribute = (double)rand() / RAND_MAX;		// between 0 and 1
			int randomIndex = rand() % indexesLowerThanOne.size();
			if (coverageOverview[indexesLowerThanOne[randomIndex]] < 1) { // if there is still space in the cell that can be populated
				double toAdd = std::min(toDistribute, std::min(1 - coverageOverview[indexesLowerThanOne[randomIndex]], t.second));
				t.second -= toAdd;
				coverageOverview[indexesLowerThanOne[randomIndex]] += toAdd;
				this->crustMaps[t.first].valuesVector[indexesLowerThanOne[randomIndex]] += toAdd;
				if (coverageOverview[indexesLowerThanOne[randomIndex]] >= 1) {
					indexesLowerThanOne.erase(indexesLowerThanOne.begin() + randomIndex);
				}
			}
		}
	}

	// do the same with the vascular plant types (TODO: extract function for cover distribution)

	for (pair<string, double> t : vascularTypes) {
		while (t.second > 0 && indexesLowerThanOne.size() > 0) { 
			double toDistribute = (double)rand() / RAND_MAX;
			int randomIndex = rand() % indexesLowerThanOne.size();
			if (coverageOverview[indexesLowerThanOne[randomIndex]] < 1) {
				double toAdd = std::min(toDistribute, std::min(1 - coverageOverview[indexesLowerThanOne[randomIndex]], t.second));
				t.second -= toAdd;
				coverageOverview[indexesLowerThanOne[randomIndex]] += toAdd;
				this->vascularMaps[t.first].valuesVector[indexesLowerThanOne[randomIndex]] += toAdd;
				if (coverageOverview[indexesLowerThanOne[randomIndex]] >= 1) {
					indexesLowerThanOne.erase(indexesLowerThanOne.begin() + randomIndex);
				}
			}
		}
	}
}


/********************************************//**
 *  generate the soil maps:
 *	1. get entries for soil from the user input
 *	2. for each soil type create a mapStruct and put it in soilMaps
 *	3. generate a spreadVector with same size as cells in the landscape
 *	and enter each soil type as often as it occurs
 *	4. shuffle the spread vector to get a random landscape configuration
 *	5. assign the shuffeled position of the cells for each soiltype to
 *  values vector in the respective soilMap entry
 ***********************************************/

void RandomLandscape::CreateSoilMaps(json landscapeElements) {
	
	// calculate number of cells
	int cells = this->size * this->size;

	// get index of all the different soil types and their distribution
	map<string, double> soilTypes = getIndexOfCategory(landscapeElements, "soil", cells);

	vector<string> spreadVector;

	// create the structs
	for (pair<string, double> t : soilTypes) {
		mapStruct newMap;
		newMap.size = this->size;
		// assign the name in the struct
		newMap.name = t.first;
		cout << t.first << " percentage: " << t.second <<  endl;
		// put the struct in the soilMaps map, with key = name
		this->soilMaps[t.first] = newMap;
		spreadVector.insert(spreadVector.begin(), t.second, t.first);
	}

	// get a time-based seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	// randomly shuffle the vector
	std::shuffle(spreadVector.begin(), spreadVector.end(), std::default_random_engine(seed));

	// populate the vectors with value 0
	for (pair<string, double> t : soilTypes) {
		this->soilMaps[t.first].valuesVector.insert(
			this->soilMaps[t.first].valuesVector.begin(), cells, 0
		);
	}

	// change values to "1" in the corresponding tables
	for (int i = 0; i < spreadVector.size(); i++) {
		this->soilMaps[spreadVector[i]].valuesVector[i] = 1;
	}
}


/********************************************//**
 *  searches input json for a given category and returns
 *	a map with an entry for each type with the respective cover
 *	if a type occurs more than once in the user input then
 *	its percentages are added
 ***********************************************/

map<string, double> RandomLandscape::getIndexOfCategory(json landscapeElements, string categoryName, int cells) {
	map<string, double> toReturn;
	for (auto& element : landscapeElements["LandscapeElements"]) {
		if (element["category"] == categoryName) {
			if (toReturn.find(element["name"]) == toReturn.end()) {
				toReturn[element["name"]] = element["coverPercentage"] * (double(cells) / 100);
			}
			else {
				toReturn[element["name"]] += element["coverPercentage"] * (double(cells) / 100);
				}

		}
	}
	return toReturn;
}




