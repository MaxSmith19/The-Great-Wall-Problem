#include <iostream>
#include <fstream>
#include <string>
#include "GreatWallBestAverage.h"
#include <chrono>
using namespace std;
using namespace chrono;
int main(int argc, char* argv[]) {
        std::string filePath = argv[1];
        GreatWallBestAverage wall = *new GreatWallBestAverage(filePath);
        wall.openFile();
        wall.secondHalf();
        wall.firstHalf();

        ofstream resultsFile("results.txt");
        for(auto i: wall.sortedBricks){
            resultsFile << i <<"\n";
        }

    for(auto x:wall.sortedBricks){
        cout << x << endl;
    }

}