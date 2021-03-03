#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <assert.h>


#include "sval.hpp"

using namespace std;

// SVal initialziers
SVal::SVal(){
    value = Nil();
}
SVal::SVal(int n){
    value = n;
}
SVal::SVal(const string &s){
    value = s;
}
SVal::SVal(SVal a, SVal b){
    value = new std::pair<SVal, SVal>(a, b);
}

SVal SVal::error(){
    SVal s;
    s.value = Err();
    return s;
}

// SVal Getters
SVal car(SVal s) {return std::get<std::pair<SVal, SVal>*>(s.value)->first;}
SVal cdr(SVal s) {return std::get<std::pair<SVal, SVal>*>(s.value)->second;}
int get_number(SVal s) {return std::get<int>(s.value);}
std::string get_symbol(SVal s) {return std::get<string>(s.value);}

// SVal type checker
bool is_nil(SVal s) {return std::holds_alternative<Nil>(s.value);}
bool is_number(SVal s) {return std::holds_alternative<int>(s.value);}
bool is_symbol(SVal s) {return std::holds_alternative<string>(s.value);}
bool is_cons(SVal s) {return std::holds_alternative<pair<SVal, SVal>*>(s.value);}
bool is_error(SVal s) {return std::holds_alternative<Err>(s.value);}
bool is_list(SVal s) {
    if (is_number(s) || is_symbol(s)) return false;
    if (is_nil(s)) return true;
    return is_list(cdr(s));
}

// Create SVal
SVal symbol(const string &s) {return SVal(s);}
SVal number(int num) {return SVal(num);}
SVal nil() {return SVal();}
SVal cons(SVal a, SVal b) {return SVal(a, b);}

// SVal -> String
string to_string(SVal s){
    ostringstream oss;
    
    if (is_list(s)) {
        oss << "(";
        string sep = "";
        while (is_cons(s)) {
            oss << sep + to_string(car(s));
            s = cdr(s);
            sep = " ";
        }
        oss << ")";
    }
    else if (is_nil(s)) oss << "()";
    else if (is_number(s)) oss << get_number(s);
    else if (is_symbol(s)) oss << get_symbol(s);
    else if (is_cons(s)) oss << "(" << to_string(car(s)) << "." << to_string(cdr(s)) << ")";
    else if(is_error(s)) oss << "error";

    return oss.str();
}