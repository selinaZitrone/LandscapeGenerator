// LandscapeGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "InputOutput.h"
using namespace std;

int main()
{
    
    int size;
    cout << "How large should your landscape be? Enter an integer number n, the generated landscape will be a square of n x n cells" << endl;
    cin >> size;
    // read a json file
    nlohmann::json landscapeElements;
    try {
        landscapeElements = InputOutput::readLandscapeUserInput();
    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;;
        return -1;
    }
   // cout << landscapeElements["LandscapeElements"][0]["category"]<<endl;

    
    
   

}
