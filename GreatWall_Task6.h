//
// Created by Smith on 15/12/2022.
//

#ifndef INC_2A_ASE_GREATWALL_TASK6_H
#define INC_2A_ASE_GREATWALL_TASK6_H


#include <iostream>
#include <list>
using namespace std;

class GreatWall_Task6 {
public:
    list<pair<string,string>> tapeA; //sort tape A alphabetically by the second components of the pair
    list<pair<string,string>> tapeB; //sort tape B alphabetically by the first components.
    list<pair<string,string>> tapeC;
    list<pair<string,int>> tapeP;
    list<pair<string,int>> tapeF;

    GreatWall_Task6(string file);

    list<string> resultsList;

    void makeTapeP();

    void calculateDistance();

private:

    string filePath;

    static void secondSort(list<pair<string, string>> &tapeA);

    void usingDistance();
    int count =0;
    int pairPos;
    int distance=2;

    bool sortBySecond(const pair<string, int> &a, const pair<string, int> &b);

    static void firstSort(list<pair<string, string>> &tapeA);

    static void secondSort(list<pair<string, int>> &tape);

    void firstSort(pair<basic_string<char>, int> tape);

    static void firstSort(list<pair<string, int>> &tape);

};


#endif //INC_2A_ASE_GREATWALL_TASK6_H
