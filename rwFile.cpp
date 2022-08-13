//
// Created by dalla on 9/10/2021.
//

#include "rwFile.h"
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

rwFile::rwFile() {
    Vlist = new std::vector<sentiment>;
    posVec = new std::vector<sentiment>;
    negVec = new std::vector<sentiment>;
    negTweets = new std::vector<sentiment>;
    posTweets = new std::vector<sentiment>;
}


rwFile::rwFile(const rwFile &object) {
    Vlist = new std::vector<sentiment>;
    posVec = new std::vector<sentiment>;
    negVec = new std::vector<sentiment>;
    posTweets = new std::vector<sentiment>;
    negTweets = new std::vector<sentiment>;
    *Vlist = *object.Vlist;
    *negVec = *object.negVec;
    *posVec = *object.posVec;
    *posTweets = *object.posTweets;
    *negTweets = *object.negTweets;

}

void rwFile::loadFile1( DSString& filename) {
    char headers[80];
    char line[500];
    std::ifstream file;
    std::cout << filename.c_str() << std::endl;
    file.open(filename.c_str());
  //  if(file.is_open()){
    //    std:: cout << "FILE 1 OPEN" << std::endl;
  //  }
    file.getline(headers, 1000);
    //std::cout << headers << std::endl; //stores headers of each file
    int j = 0;
    while (file.good()) {
        sentiment tweet;
        file.getline(line, 1000);
        std::stringstream ss(line); //string stream created from line
        int i = 0;
        while (ss.good()) {
            DSString tempWord;
            char word[550];
            ss.getline(word, 500, ',');
            tempWord = word;
            if (i == 0) {
                tweet.setStatus(tempWord);
              //  std::cout << tempWord << std::endl;
            }
            else if (i == 1) {
                tweet.setID(tempWord);
               // std::cout << tempWord << std::endl;
            }
            else if (i == 5) {
                tweet.setTweet(tempWord);
              //  std::cout << tempWord << std::endl;
            }
            i++;
        }
        Vlist->push_back(tweet); //i didnt do rule of 3 correctly for ONE CLASS and spent like 4 hours debugging here
    }
  //  std::cout << this->Vlist << std::endl;
    file.close();
}

std::vector<sentiment> rwFile::getVector() {
    return *this->Vlist;
}

rwFile::~rwFile() {
    delete Vlist;
    delete posVec;
    delete negVec;
    delete posTweets;
    delete negTweets;

}

rwFile &rwFile::operator=(const rwFile& arg) {
    if (this->Vlist == arg.Vlist) {
        return *this;
    }
    delete[] Vlist;
    Vlist = new std::vector<sentiment>;
    posVec = new std::vector<sentiment>;
    negVec = new std::vector<sentiment>;
    *Vlist = *arg.Vlist;
    *posVec = *arg.posVec;
    *negVec = *arg.negVec;
    return *this;
}

void rwFile::loadFile2(DSString &filename) {
    char headers[80];
    char line[500];
    std::ifstream file;
    file.open(filename.c_str());
    file.getline(headers, 1000);
    //std::cout << headers << std::endl; //stores headers of each file
    int j = 0;
    while (file.good()) {
        sentiment tweet;
        file.getline(line, 1000);
        std::stringstream ss(line); //string stream created from line
        int i = 0;
        while (ss.good()) {
            DSString tempWord;
            char word[550];
            ss.getline(word, 500, ',');
            tempWord = word;
            if (i == 0) {
                tweet.setID(tempWord);
            }
            else if (i == 4) {
                tweet.setTweet(tempWord);
            }
            i++;
        }
        Vlist->push_back(tweet); //i didnt do rule of 3 correctly for ONE CLASS and spent like 4 hours debugging here
    }
}

void rwFile::loadFile3(DSString &filename) {
    char headers[80];
    char line[500];
    std::ifstream file;
    file.open(filename.c_str());
    file.getline(headers, 1000);
   // std::cout << headers << std::endl; //stores headers of each file
    int j = 0;
    while (file.good()) {
        sentiment tweet;

        file.getline(line, 1000);
        std::stringstream ss(line); //string stream created from line
        int i = 0;
        while (ss.good()) {
            DSString tempWord;
            char word[550];
            ss.getline(word, 500, ',');
            tempWord = word;
            if (i == 0) {
                tweet.setStatus(tempWord);
              //  std::cout << tempWord << std::endl;
            }
            else  {
                tweet.setID(tempWord);
                //std::cout << tempWord << std::endl;
            }
            i++;
        }

        Vlist->push_back(tweet); //added to list
    }
}

//below function gets both the positive and negative word list of the first 15 tweets in a given file

void rwFile::sortWords() { //NOTE TO SELF: only works on datasets with tweets
    std::vector<sentiment> wordList = {}; //vector temporarily holds individual words
    int count = 0;
    std::vector<sentiment> ye;
    for (int i = 0; i < 15; i++) {
        std::cout << "Tweet #: " << i + 1 << " parsed." << std::endl;
        std::stringstream ss(Vlist->at(i).getTweet().c_str()); //created string stream from tweet
        while (ss.good()) {
            int count2 = 0;
            char word[4000];
            sentiment word1;
            DSString word2;
            ss.getline(word, 4000, ' '); //parses by word in tweet until reaches end
            word2 = word;
            word1.setTweet(word2); //sentiment object assigned, functions as a string wrapper with a sentiment counter
            //std::cout << word << std::endl;
            for (auto &x : wordList) {
                if (x.getTweet() == word1.getTweet()) {
                    count2 = 1;                           //here i insure that each word is added to new list only once
                }
            }
            if (count2 == 0) {
                wordList.push_back(word1);
            }
        }
        count++;

        for (auto &z : getVector()) {
              z.setCount(0);
              std::string paragraph = z.getTweet().c_str();
            for (auto &h : wordList) {
                std::string word2 = h.getTweet().c_str();
                if ((z.getStatus() == "4" ) && paragraph.find(word2))  {  //count per word incremented if pos
                    h.incrementcount();
                }
                if ((z.getStatus() == "0") && paragraph.find(word2)) {  //count decremented if negative
                    h.decrementcount();
                }
            }
        }
         //above chunk of code is intended to increment count of each word (should be optimized)

    }
    for (auto& h : wordList) {
        if (h.getcount() < 320) {
            this->negVec->push_back(h);
        }
        else {
            this->posVec->push_back(h);   //if negative, added to pos, if negative added to neg
        }
    }
    std::cout << "List size: " << wordList.size() << std::endl;
    std::cout << "Positive words: " << posVec->size() << std::endl;
    std::cout << "Negative words: " << negVec->size() << std::endl;
}

std::vector<sentiment> rwFile::returnPosVec() {
    return *posVec;
}

std::vector<sentiment> rwFile::returnNegVec() {
    return *negVec;
}

std::vector<sentiment> rwFile::returnVlist() {
    return *Vlist;
}

void rwFile::setNeg(std::vector<sentiment> neg) {
    *negVec = neg;

}

void rwFile::setPos(std::vector<sentiment> pos) {
    *posVec = pos;

}

void rwFile::incrementTweets() {
    std::vector<sentiment> tempVector;
    for (auto& fs: returnVlist()) {
        fs.setCount(0);
        std::string word = fs.getTweet().c_str();
        for (auto& fd : *posVec) {
            std::string word1 = fd.getTweet().c_str();
            if (word.find(word1)) {
                fs.incrementcount();

            }
        }
        std::string word2 = fs.getTweet().c_str();
        for (auto& fd : *negVec) {
            std::string word3 = fd.getTweet().c_str();
            if (word2.find(word3)) {
                fs.decrementcount();

            }
        }
        DSString pos = "4";
        DSString neg = "0";
        //std::cout << fs.getcount() << std::endl;
        if (fs.getcount() >= -50) {
            fs.setStatus(pos);
            tempVector.push_back(fs);
        }
        else {
            fs.setStatus(neg);
            tempVector.push_back(fs);
        }
    }
    *Vlist = tempVector;
}

void rwFile::printToFile(DSString &destination, std::vector<sentiment> noSent) {
    std::ofstream ofs; //created filestream
    std::vector<sentiment> tempVector;
    int count = 0;
    ofs.open(destination.c_str());
    ofs.clear();
    for (int i = 0; i < getVector().size() - 1; i++) {
        if (getVector().at(i).getStatus() == noSent.at(i).getStatus()) {
            count++;
        }
        else {
            tempVector.push_back(getVector().at(i));
        }
    }
    ofs << count << "/" << getVector().size() << std::endl; //
    for (int i = 0; i < tempVector.size(); i++) {
        ofs << "ID: " << tempVector.at(i).getId() << std::endl;
    }
    ofs.close();
}
//nested loops traverse file and increments/decrement count for tweets





