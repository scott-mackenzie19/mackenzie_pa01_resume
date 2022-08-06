//
// Created by dalla on 9/9/2021.
//

#include "sentiment.h"
#include "DSString.h"
#include <istream>

sentiment::sentiment(const sentiment &string) { //copy constructor
    delete count;
    delete id;
    delete tweet;
    delete status;
    count = new int;
    id = new DSString;
    tweet = new DSString;
    status = new DSString;
    *count = *string.count;
    *id = *string.id;
    *tweet = *string.tweet;
    *status = *string.status;

}


sentiment::~sentiment() { //destructor
    delete count;
    delete id;
    delete tweet;
    delete status;
}

sentiment::sentiment() { //default constructor
    count = new int(0);
    //*count = 0;
    id = new DSString;
    tweet = new DSString;
    status = new DSString;


}

void sentiment::incrementcount() {
    ++*count;

}

int sentiment::getcount() {
    return *this->count;
}

DSString sentiment::getId() {
    return *this->id;
}

DSString sentiment::getTweet() {
    return *this->tweet;
}
                                                 //setters/getters as well as increment count function
void sentiment::setTweet(DSString &string) {
    tweet = new DSString(string);

}

void sentiment::setID(DSString& string) {
    id = new DSString(string);
}

bool sentiment::search(const DSString& query) {
    if (this->tweet->search(query)) { //if boolean statement evaluates to true
        incrementcount();
        return true;
    }
    else {
        return false;
    }


}

DSString sentiment::getStatus() {
    return *this->status;
}

void sentiment::setStatus(DSString& string) {
    status = new DSString(string);

}

sentiment &sentiment::operator=(const sentiment &arg) {
    if (this->id == arg.id) {
        return *this; //if already equal, no extra steps necessary
    }
    delete id;
    delete tweet;
    delete count;
    delete status;
    id = new DSString;
    *id = *arg.id;
    tweet = new DSString;
    *tweet = *arg.tweet;
    count = new int;
    *count = 0;
    status = new DSString;
    *status = *arg.status;
    return *this;
}

bool sentiment::operator==(const sentiment &arg) {
    if (this->tweet == arg.tweet)
        return true;
    else {
        return false;
    }
}

void sentiment::decrementcount() {
    --*count;

}

void sentiment::setCount(int num) {
    *count = num;

}



