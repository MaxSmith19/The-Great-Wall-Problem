//
// Created by Smith on 15/12/2022.
//

#include "GreatWall_Task6.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

GreatWall_Task6::GreatWall_Task6(string file){
    filePath=file;

    std::string text;
    try
    {
        std::ifstream myFile("../../Great_Wall_Problem-test_data/" + file);
        while (getline(myFile, text, '\n')) { //o(n^2)
            //open file, seperating by new line (unecessary but helpful for reading)
            size_t pos = text.find(','); // o(1)
            string key = text.substr(0, pos); // o(n)
            //seperate the key and value using the index of the comma

            string value = text.substr(pos + 1); // o(n)

            std::pair<string,string> item={key,value};

            tapeA.push_back(item);
            tapeB.push_back(item);
            count++;
            //assign to tapeAIterator->map the first item and the second item as key and value pairs.
        }
    }catch(exception e){
        cout << e.what() <<endl;
    }
    secondSort(tapeA);
    firstSort(tapeB);
}

void GreatWall_Task6::calculateDistance(){
    while(distance < count) {
        //Overwrite tapes A and B with copies of tape C.
        tapeA=tapeC;
        tapeB=tapeC;
        //Erase tape C.
        tapeC.clear();
        //Sort tape A alphabetically by the second components of the pairs, and sort tape B alphabetically by the first components.
        secondSort(tapeA);
        firstSort(tapeB);
        //4
        usingDistance();
        //Sort tape F alphabetically by its first components;
        firstSort(tapeF);
        //Merge the contents of tape F into tape P (preserving alphabetical ordering of first components);
        tapeP.merge(tapeF);
        //Erase tape F.
        tapeF.clear();
        //Increase d to 2d.
        distance = distance *2;
    }
    //sort tape P numerically by its second components
    secondSort(tapeP);
    for(auto p: tapeP){
        resultsList.push_back(p.first);
    }
}
void GreatWall_Task6::makeTapeP(){

    pairPos=0;
    auto tapeAIterator=tapeA.begin();
    auto tapeBIterator=tapeB.begin();
    while(tapeAIterator!=tapeA.end()){
            if(tapeAIterator->second==tapeBIterator->first){
                pair<string,string> values= {tapeAIterator->first,tapeBIterator->second};
                tapeC.push_back(values);
                tapeAIterator++;
                tapeBIterator++;
            }else if(tapeAIterator->second <tapeBIterator->first)
            {
                pair<string,int> values = {tapeAIterator->first,pairPos-1};
                pair<string,int> values2 = {tapeAIterator->second,pairPos};
                tapeP.push_back(values);
                tapeP.push_back(values2);
                tapeAIterator++;
            }else if(tapeAIterator->second > tapeBIterator->first){
                tapeBIterator++;
            }
            pairPos++;
    }
    secondSort(tapeP);


}
void GreatWall_Task6::usingDistance(){
    auto tapeAIterator=tapeA.begin();
    auto tapeBIterator=tapeB.begin();
    auto tapePIterator=tapeP.begin();
    bool pFlag =false;
    bool bFlag = false;

    while (tapeAIterator != tapeA.end()) {
        if (tapePIterator == tapeP.end()) {
            tapePIterator--;
            pFlag = true;
        }
        if (tapeBIterator == tapeB.end()) {
            tapeBIterator--;
            bFlag = true;
        }
        if (tapeAIterator->second == tapeBIterator->first) { //a2 == b1
            pair<string, string> values = {tapeAIterator->first, tapeBIterator->second}; //append a1,b2
            tapeC.push_back(values);
            tapeAIterator++;
            tapeBIterator++;
        } else if (tapeAIterator->second == tapePIterator->first) { //a2 == p1
            pair<string, int> values = {tapeAIterator->first, tapePIterator->second - distance};
            tapeF.push_back(values);
            tapeAIterator++;
            tapePIterator++;
        } else if (tapeAIterator->second > tapePIterator->first && !pFlag) { //a2>p1
            tapePIterator++; //otherwise the iterator increases when it has nowhere to go past .end(), causing a segmentation fault.
        } else if (tapeAIterator->second > tapeBIterator->first && !bFlag) { //a2 >b1
            tapeBIterator++;
            //"Hmmm," said the Royal Software Engineer, "that's very clever. But you'll have to be careful to
            // check that you haven't reached the end of tapes B or P in those if-conditions, otherwise you might make an out-of-bounds access."
        }else {
            tapeAIterator++; //added otherwise the tapeA never advances.
        }
    }
}

void GreatWall_Task6::secondSort(std::list<pair<string,string>> &tape){ //Lambda function from https://stackoverflow.com/questions/60034357/how-to-sort-a-list-of-pairs-based-on-second-element-in-decreasing-order-in-c
    tape.sort([](const pair<string,string>& pair1,
            const pair<string,string>& pair2){
        return pair1.second <pair2.second;
    });
};
void GreatWall_Task6::secondSort(std::list<pair<string,int>> &tape){ //Lambda function from https://stackoverflow.com/questions/60034357/how-to-sort-a-list-of-pairs-based-on-second-element-in-decreasing-order-in-c
    tape.sort([](const pair<string,int>& pair1,
                 pair<string, int>& pair2){
        return pair1.second <pair2.second;
    });
};
void GreatWall_Task6::firstSort(list<pair<string,string>> &tape){ //Lambda function adapted from https://stackoverflow.com/questions/60034357/how-to-sort-a-list-of-pairs-based-on-second-element-in-decreasing-order-in-c
    tape.sort([](const pair<string,string>& pair1,
                  const pair<string,string>& pair2){
        return pair1.first <pair2.first;
    });
}
void GreatWall_Task6::firstSort(list<pair<string,int>> &tape){ //Lambda function adapted from https://stackoverflow.com/questions/60034357/how-to-sort-a-list-of-pairs-based-on-second-element-in-decreasing-order-in-c
    tape.sort([](pair<string, int> &pair1,
                 const pair<string,int>& pair2){
        return pair1.first <pair2.first;
    });
}
