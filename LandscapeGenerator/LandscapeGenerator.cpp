// LandscapeGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "InputOutput.h"
using namespace std;

int main()
{
    
    
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
