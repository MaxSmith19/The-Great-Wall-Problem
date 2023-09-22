//
// Created by Smith on 16/12/2022.
//
#include "GreatWall_Task6.h"
#include <chrono>
using namespace std;
using namespace chrono;
//
// Created by Smith on 15/12/2022.
//
int main(int argc, char* argv[]) {
        std::string filePath = argv[1];

        GreatWall_Task6 tape = GreatWall_Task6(filePath);
        tape.makeTapeP();
        tape.calculateDistance();

        for(auto p: tape.resultsList) {
            cout << p << endl;
        }
}
