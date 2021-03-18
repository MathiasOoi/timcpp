#include <unordered_map>
#include <string>
#include <iostream>

#include "environment.hpp"
#include "sval.hpp"

using namespace std;

Environment global;

Environment::Environment(Environment* p){
    parent = p;
}

void Environment::add(const std::string &symbol, SVal value){
    env[symbol] = value;
}

SVal Environment::get(const std::string &symbol){
    return env.find(symbol) != env.end() ? env[symbol] : parent ? parent->get(symbol) : SVal::error();
}

Environment init(){
    Environment env;
    env.add("test", SVal(3));
    env.add("+", SVal(add));
    env.add("-", SVal(subtract));
    env.add("*", SVal(multiply));
    env.add("/", SVal(divide));
    return env;
}