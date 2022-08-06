//
// Created by dalla on 9/10/2021.
//

#ifndef MACKENZIE_PA01_RWFILE_H
#define MACKENZIE_PA01_RWFILE_H

#include "sentiment.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>


class rwFile {
private:
    std::vector<sentiment> *Vlist;
    std::vector<sentiment> *posVec;
    std::vector<sentiment> *negVec;
    std::vector<sentiment> *posTweets;
    std::vector<sentiment> *negTweets;
public:
    rwFile();
    rwFile(const rwFile &object); //rule of 3 for wrapper function
    ~rwFile();
    rwFile& operator = (const rwFile& arg);


    void loadFile1( DSString& filename);
    void loadFile2( DSString& filename);
    void loadFile3( DSString& filename); //load functions per file
    std::vector<sentiment> getVector();
    void sortWords(); //search function returns a vector of sentiment objects
    std::vector<sentiment> returnPosVec();
    std::vector<sentiment> returnNegVec();
    std::vector<sentiment> returnVlist();
    void setPos(std::vector<sentiment> pos);
    void setNeg(std::vector<sentiment> neg);
    void incrementTweets();
    void printToFile(DSString& destination, std::vector<sentiment> noSent);



};



#endif //MACKENZIE_PA01_RWFILE_H
