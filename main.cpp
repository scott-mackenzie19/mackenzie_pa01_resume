#include <iostream>
#include "DSString.h"
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "rwFile.h"
using namespace std;
#include "sentiment.h"
int main(int argc, char** argv ) {
    DSString traindata ;
    DSString testdata;
    DSString testsentiment;
    DSString output;
     if (argc > 1) {

         traindata = argv[1];
         cout << traindata.c_str() << endl;
         testdata = argv[2];
         testsentiment = argv[3];
         output = argv[4];
     }
     else {
         cout << "Please enter proper amount of command line arguments. " << endl;
     }
     rwFile file1;
     file1.loadFile1(traindata);
     rwFile file2;
     file2.loadFile2(testdata);
     rwFile file3;
     file3.loadFile3(testsentiment);
     rwFile fileO;
    cout << file1.getVector().size() << endl;
    cout << file2.getVector().size() << endl;
    cout << file3.getVector().size() << endl;
    file1.sortWords();
    file2.setNeg(file1.returnNegVec());
    file2.setPos(file1.returnPosVec());
    file2.incrementTweets();
    file3.printToFile(output, file2.getVector());
    return 0;
}
