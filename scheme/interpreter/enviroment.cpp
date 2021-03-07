#include <unordered_map>
#include <string>
#include <iostream>

#include "enviroment.hpp"
#include "sval.hpp"

using namespace std;

Environment::Environment(Environment* parent){
    if (parent) env = parent->env;
}

void Environment::add(const std::string &symbol, SVal value){
    env[symbol] = value;
}

SVal Environment::get(const std::string &symbol){
    return env.find(symbol) != env.end() ? env[symbol] : SVal::error();
}