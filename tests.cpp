#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decryption.h"
// add your tests here

TEST_CASE("TASK B"){
    //testing dictionary entry
    std::string original = "A set of words that is complete in itself, typically containing a subject and predicate, conveying a statement, question, exclamation, or command, and consisting of a main clause and sometimes one or more subordinate clauses";
    std::string test = encryptCaesar(original,4);
    CHECK(solve(test) == original);


    //testings all shifts
    for(int i = 0; i < 25; i++){
        original = "A balloon was filled up with gas and released, flying into the air";
        test = encryptCaesar(original, i);
        CHECK(solve(test) == original);
    }

}