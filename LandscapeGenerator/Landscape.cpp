#include "Landscape.h"

double Landscape::calculateInfiltration()
{
	return 0.0;
}

double Landscape::calcualteRoughness()
{
	return 0.0;
}

// get a specific soil map based on type
mapStruct Landscape::getSoilMap(string soilType)
{
	if (soilMaps.find(soilType) != soilMaps.end()) {
		return soilMaps[soilType];
	}
	else {
		return mapStruct();
	}
}

map<string, mapStruct> Landscape::getAllSoilMaps()
{
	return soilMaps;
}

mapStruct Landscape::getCrustMap(string crustType)
{
	if (crustMaps.find(crustType) != crustMaps.end()) {
		return crustMaps[crustType];
	}
	else {
		return mapStruct();
	}
}

map<string, mapStruct> Landscape::getAllCrustMaps()
{
	return crustMaps;
}

mapStruct Landscape::getVascularMap(string vascularType)
{
	if (vascularMaps.find(vascularType) != vascularMaps.end()) {
		return vascularMaps[vascularType];
	}
	else {
		return mapStruct();
	}
}

map<string, mapStruct> Landscape::getAllVascularMaps()
{
	return vascularMaps;
}

