#include "UserInteraction.h"
#include <iostream>
using namespace std;
int UserInteraction::askForLandscapeSize()
{
	int size;
	cout << "How large should your landscape be? Enter an integer number n, the generated landscape will be a square of n x n cells" << endl;
	cin >> size;
	return size;
}
