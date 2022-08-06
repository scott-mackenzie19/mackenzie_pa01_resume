//
// Created by dalla on 9/9/2021.
//

#ifndef MACKENZIE_PA01_SENTIMENT_H
#define MACKENZIE_PA01_SENTIMENT_H

#include "DSString.h"


class sentiment {
    //sentiment class essentially is an object that formats the tweets in a way that will make access easier
    //included is a count (could be used for sentiment), tweet, status, and ID

private:
    int* count = nullptr;
    DSString* id = nullptr ;
    DSString * tweet = nullptr ;
    DSString * status = nullptr;
public:
    sentiment();
    ~sentiment();
    sentiment( const sentiment &string);
    void incrementcount();
    void decrementcount();
    int getcount();
    DSString getId();
    DSString getTweet();
    DSString getStatus();  //setters and getters
    void setTweet(DSString& string);
    void setID(DSString& string);
    void setCount(int num);
    void setStatus(DSString& string);
    bool search(const DSString& query); //search function uses string substring search function from DSString
    sentiment& operator= (const sentiment& arg); //overloaded assignment operator
    bool operator== (const sentiment& arg);


};




#endif //MACKENZIE_PA01_SENTIMENT_H
