#include <string>
#include <sstream>
#include <iostream>
#include <vector>


#include "sval.hpp"

using namespace std;

// SVal initialziers
SVal::SVal(){}
SVal::SVal(int n){
    number = n;
    which = 1;
}
SVal::SVal(const string &s){
    symbol = s;
    which = 2;
}
SVal::SVal(SVal a, SVal b){
    pair<SVal, SVal>* ptr = new pair<SVal, SVal>;
    ptr->first = a; ptr->second = b;
    cons = ptr;
    which = 3;
}

// SVal Getters
SVal car(SVal s) {return s.cons->first;}
SVal cdr(SVal s) {return s.cons->second;}
int get_number(SVal s) {return s.number;}
std::string get_symbol(SVal s) {return s.symbol;}

// SVal type checker
bool is_nil(SVal s) {return s.which == 0 ? true : false;}
bool is_number(SVal s) {return s.which == 1 ? true : false;}
bool is_symbol(SVal s) {return s.which == 2 ? true : false;}
bool is_cons(SVal s) {return s.which == 3 ? true : false;}
bool is_error(SVal s);
bool is_list(SVal s);

// Create SVal
SVal symbol(const string &s) {return SVal(s);}
SVal number(int num) {return SVal(num);}
SVal nil() {return SVal();}
SVal cons(SVal a, SVal b) {return SVal(a, b);}

// SVal -> String
string to_string(SVal s){
    ostringstream oss;
    
    if (is_nil(s)) oss << "()";
    else if (is_number(s)) oss << get_number(s);
    else if (is_symbol(s)) oss << get_symbol(s);
    else if (is_cons(s)) oss << "(" << to_string(car(s)) << "." << to_string(cdr(s)) << ")";

    return oss.str();
}
