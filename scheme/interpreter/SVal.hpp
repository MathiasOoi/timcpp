#pragma once
#include <string>
#include <vector>

struct SVal {
    int number;
    std::string symbol;
    SVal *left, *right;
    int which; // 0 for nil, 1 for number, 2 for symbol, 3 for cons

    SVal() {which = 0;}
    SVal(int n) {number = n; which = 1;}
    SVal(std::string s) {symbol = s; which = 2;}
    SVal(SVal a, SVal b) {left = &a; right = &b; which = 3;}

    bool is_nil() {return which == 0 ? true : false;}
    bool is_number() {return which == 1 ? true : false;}
    bool is_symbol() {return which == 2 ? true : false;}
    bool is_cons() {return which == 3 ? true : false;}

    SVal car() {return *left;}
    SVal cdr() {return *right;}
    int get_number() {return number;}
    std::string get_symbol() {return symbol;}

    std::string to_string() {return "Value: " + this->repr();}

    private:
        std::string repr();
};