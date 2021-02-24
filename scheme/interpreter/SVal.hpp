#pragma once

#include <utility>
#include <string>

struct SVal{
    SVal();
    SVal(int n);
    SVal(const std::string &s);
    SVal(SVal a, SVal b);

    // Create an SVal that stores an error code, nothing else.
    static SVal error();

    int which = 0;
    int number = 0;
    std::string symbol = "";
    using Cons = std::pair<SVal, SVal>;
    Cons *cons = nullptr;
};

SVal car(SVal s);
SVal cdr(SVal s);
int get_number(SVal s);
std::string get_symbol(SVal s);

bool is_nil(SVal s);
bool is_cons(SVal s);
bool is_number(SVal s);
bool is_symbol(SVal s);
bool is_error(SVal s);
bool is_list(SVal s);

SVal symbol(const std::string &s);
SVal number(int num);
SVal nil();
SVal cons(SVal a, SVal b);

std::string to_string(SVal s);