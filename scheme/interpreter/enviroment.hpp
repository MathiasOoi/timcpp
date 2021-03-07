#pragma once

#include <string>
#include <unordered_map>
#include "sval.hpp"

class Environment{
    public:
        Environment(Environment* parent = nullptr);
        void add(const std::string &symbol, SVal value);
        SVal get(const std::string &symbol);
    protected:
        std::unordered_map<std::string, SVal> env;
};