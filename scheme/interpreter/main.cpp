#include <iostream>
#include <string>
#include <vector>

#include "sval.hpp"
#include "parser.hpp"
#include "environment.hpp"

using namespace std;

int main(){
    global = init();

    // REPL
    string input;
    while (true){
        getline(cin, input);
        cout << "-> " << to_string(eval(&global, parse(input))) << endl;
    }
}
    