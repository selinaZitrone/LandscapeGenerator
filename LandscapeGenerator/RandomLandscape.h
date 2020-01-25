#pragma once
#include "Landscape.h"
#include "json.hpp"
using json = nlohmann::json;

class RandomLandscape :
	public Landscape
{
public:
	void generateLandscape(json landscapeElements) override;
};

