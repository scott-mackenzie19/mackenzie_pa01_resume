//
// Created by dalla on 9/7/2021.
//

#include "catch.hpp"
#include <cstring>
#include "DSString.h"

TEST_CASE("String Class", "[DSString]")
{
    SECTION("equality operators" ) {
        REQUIRE("Hello" == "Hello");
        REQUIRE("This is a long string" == "This is a long string");

        DSString * dsString1 = new DSString();
        DSString * dsString2 = new DSString("hello");
        DSString * dsString3 = new DSString(*dsString2);
        *dsString1 = "hello";
        if(*dsString1 == *dsString2 && *dsString1 == *dsString3 && *dsString2 == *dsString3){
            std::cout << "Equal" << std::endl;
        }else{
            std::cout << "Not Equal" << std:: endl;
        }
    }
}
