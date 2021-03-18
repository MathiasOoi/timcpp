#include <iostream>
#include <string>
#include <vector>

#include "sval.hpp"
#include "parser.hpp"
#include "environment.hpp"

using namespace std;

int main(){
    // vector<string> tests = {"13", "x", "()", "(())", "(+ 3 4)", "(a (b c) d)"};
    // for (string test : tests){
    //     auto x = tokenize(test);
    //     cout << test << " -> " << to_string(parse(x)) << endl;
    // }
    // Environment env1;
    // env1.add("x", SVal(1));
    // env1.add("y", SVal("foo"));
    // cout << to_string(env1.get("x")) << " " << to_string(env1.get("y")) << endl;

    // Environment env2(&env1);
    // cout << to_string(env2.get("x")) << " " << to_string(env2.get("y")) << endl;
    // auto x = tokenize("(a (b c) d)");
    // env1.add("z", parse(x));
    // cout << to_string(env1.get("z")) << endl;
    // cout << to_string(env2.get("z")) << endl;
    // env2.add("z", SVal(13));
    // cout << to_string(env2.get("z")) << endl;

    // Environment env3;
    // cout << to_string(env3.get("z")) << endl;
    global = init();
    cout << to_string(global.get("x")) << endl;




    // REPL
    string input;
    while (true){
        getline(cin, input);
        cout << "-> " << to_string(eval(&global, parse(input))) << endl;
    }
}
    