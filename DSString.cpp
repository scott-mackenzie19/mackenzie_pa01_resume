//
// Created by dalla on 9/2/2021.
//

#include "DSString.h"
#include <sstream>
#include <iostream>
using namespace std;

DSString::DSString() {
    str = new char[1];
    str[0] = '\0';
//if passed no argument, overallocates space for string and fills with null.
}

DSString::DSString(const char* s) {
    if (s == nullptr) {
        str = new char[1];
        str[0] = '\0'; //if statement if passed a nullptr, will allocate space for empty string;
    }
    else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
        //if passed an actual 'string', will initialize normal copy
    }
}

DSString::DSString(const DSString & arg) {
    str = new char[strlen(arg.str)+ 1];
    strcpy(str, arg.str);

}
DSString::~DSString() {
    delete[] str;
}

DSString &DSString::operator=(const DSString & arg) {
    if (this == &arg) {
        return *this; //if they are already equal, no copying or reallocation
        // is necessary
    }
    delete[] str;
    str = new char[strlen(arg.str) + 1];
    strcpy(str, arg.str); //string copied after allocating space above
    return *this;
}

DSString &DSString::operator=(const char * s) {
    if (strcmp(this->str, s) == 0) {
        return *this;
    } //if already equal, returns as is
    delete[] str;
    str = new char[strlen(s) + 1];
    strcpy(str, s); //string copied after allocating space if not equal.
    return *this;


}

DSString DSString::operator+(const DSString & arg) {
    int length = strlen(arg.str) + strlen(this->str);

    char* buff = new char[length + 1]; //buff created of 1 more than the 2 words added together.

    // Copy each string to buff
    strcpy(buff, arg.str);
    strcat(buff, this->str);

    // new string created on stack equal to that of buff (on heap)
    DSString temp = buff ;

    // delete the buff[]
    delete[] buff;

    // temp = concatenated string
    return temp;
}

bool DSString::operator==(const char * s) {
    if (strcmp(s, this->str) == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool DSString::operator==(const DSString &arg) {
    if (strcmp(arg.str, this->str) == 0) {
        return true;
    }
    else {
        return false;
    } //i feel like these two functions dont rlly need explanation...
}

char &DSString::operator[](const int num) {
    if (num > strlen(this->str)) {
        std::cout << "Num out of bounds" << std::endl;
        return (char &) " ";
    }
    else {
        return this->str[num]; //essentially functions as array so I access index like any array
    }
    //I know you said not to reinvent the wheel but im stupid and keep trying to reinvent on accident. it takes forever
}

int DSString::getLength() {
    return strlen(this->str); //dis one easy
}

DSString DSString::substring(int start, int numChars) {
    char *s = new char[numChars + 1];
    for (int i = 0; i < numChars; i++) {
        s[i] = str[start + i];
    } //for loop adds contents of string requested to temp placeholder
    s[numChars] = '\0';
    DSString temp = s;
    delete[] s;
    return temp; //returns new substring
}

char *DSString::c_str() {
    return this->str; //i beilieve this would just return the actual cstring part of the object, effectively converting forms
}

std::ostream &operator<<(std::ostream & os, const DSString & arg) {
    os << arg.str; //loads the string into an output string stream, printing
    return os;
}

std::istream &operator>>(std::istream &is, DSString &arg) {
    char buff[1000]; //create hella space for tweets.
    is.get(buff, 1000, '\n');
    arg = DSString (buff);
    return is; //uses input streams to read in objects. will be useful for parsing
}

bool DSString::search(const DSString& query) { //bool search function returns true if word is found
    stringstream ss;
    ss.str(this->str); //string loaded into stringstream
    DSString word;
    while (ss.good()) { //parsing tweet via the magic of string streams
        ss >> word;
        if (word == query) {
            return true;                 //ends
        }

    }
    return false;



}

















