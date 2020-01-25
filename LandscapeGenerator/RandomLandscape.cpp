#include "RandomLandscape.h"

void RandomLandscape::generateLandscape(json landscapeElements)
{
	// 1. generate soil maps:
	for (auto& element : landscapeElements["LandscapeElements"]) {
		if (element["category"] == "soil") {

		}
	}
}
