#pragma once
#include "json.hpp"

using json = nlohmann::json;

class InputOutput
{
public:
	static nlohmann::json readLandscapeUserInput();
	static void writeMapToFile();
};

