#include <iostream>
#include <string>
#include <vector>

#include "sval.hpp"
#include "parser.hpp"

using namespace std;

int main(){
    vector<string> tests = {"13", "x", "()", "(())", "(+ 3 4)", "(a (b c) d)"};
    for (string test : tests){
        auto x = tokenize(test);
        cout << test << " -> " << to_string(parse(x)) << endl;
    }
}