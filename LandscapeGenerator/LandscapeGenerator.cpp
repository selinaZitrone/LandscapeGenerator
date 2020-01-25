// LandscapeGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;

int main()
{
    // read a json file
    ifstream landscapeDataJson("landscapeObjectsData.json");
    json landscapeData;
    landscapeDataJson >> landscapeData;

   // cout << landscapeData[0]["age"] << endl;

   

    /*for (auto& element : landscapeData.items()) {
        cout << element.key() << " " << element.value()["type"] << endl;
    }*/
    
    cout << landscapeData["vascular"][0]["name"] << endl;
    cout << landscapeData["vascular"][1] << endl;
}
