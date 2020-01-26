#pragma once
using namespace std;
#include <string>
#include <vector>


string printTable(vector<double> toPrint, int sideSize) {
	int side = sideSize;
	int rowCounter = 0;
	string toReturn = "";
	for (int i = 0; i < toPrint.size(); i++) {
		toReturn += " " + to_string(toPrint[i]);
		rowCounter++;
		if (rowCounter == side) {
			toReturn += "\n";
			rowCounter = 0;
		}
	}
	return toReturn;

}

void printMaps(map<string, mapStruct> mapToPrint, string title) {
	cout << endl << endl;
	cout << title << endl << endl;
	cout << "---" << endl;
	for (pair<string, mapStruct> t : mapToPrint) {
		cout << "type: " << t.second.name << endl;
		cout << "---" << endl;
		cout << printTable(t.second.valuesVector, t.second.size) << endl;
		cout << "---" << endl << endl;
	}
}

