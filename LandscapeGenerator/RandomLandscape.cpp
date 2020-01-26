#include "RandomLandscape.h"
#include <algorithm>

void RandomLandscape::generateLandscape(json landscapeElements)
{
	std::map<string, int> soilTypes;
	// 1. generate soil maps:
	for (auto& element : landscapeElements["LandscapeElements"]) {
		if (element["category"] == "soil") {
			// check how many different
			if (soilTypes.find(element["name"]) == soilTypes.end()) {
				soilTypes[element["name"]] = (int)element["coverPercentage"];
			}
			else {
				soilTypes[element["name"]] += (int)element["coverPercentage"];
			}

		}
	}

	


	// TO DO: transform prozent in number of cells
	// the int by SOILTYPES are actual cells!!!
	int cells = 100;

	vector<string> spreadVector;

	// create the structs
	for (pair<string,int> t : soilTypes) {
		mapStruct newMap;
		newMap.name = t.first;
		this->soilMaps[t.first] = newMap;
		spreadVector.insert(spreadVector.begin(), t.second, t.first);
	}

	// TO DO: shuffle spreadVector
	// create 3 "false" vectors size cells
	// for string s in spreadVector
	// soilMaps[s][i] = true;

	




	// populate their vectors
}
