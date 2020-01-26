#pragma once
#include "Landscape.h"
#include "json.hpp"
using json = nlohmann::json;

class RandomLandscape :
	public Landscape
{
public:
	void generateLandscape(json landscapeElements) override;
	RandomLandscape(int sideSize) {
		this->size = sideSize;
	}

private:
	void CreateSoilMaps(json landscapeElements);
	map<string, double> getIndexOfCategory(json landscapeElements, string categoryName, int cells);
};

