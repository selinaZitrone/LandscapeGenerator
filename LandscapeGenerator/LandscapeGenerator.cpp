// LandscapeGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "InputOutput.h"
using namespace std;

int main()
{
    // read a json file
    nlohmann::json test;
    try {
        test = InputOutput::readLandscapeUserInput();
    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;;
        return -1;
    }
    
    
    // cout << landscapeData[0]["age"] << endl;

   

   /* for (auto& element : test.items()) {
        cout << element.key() << " " << element.value() << endl;
    }*/
    
   

}
