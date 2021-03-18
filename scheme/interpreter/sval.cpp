#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <assert.h>
#include <iostream>

class Environment;

#include "sval.hpp"
#include "environment.hpp"

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
    value = new pair<SVal, SVal>(a, b);
}
SVal::SVal(function<SVal(SVal)> func){
    value = func;
}

SVal SVal::error(){
    SVal s;
    s.value = Err();
    return s;
}

// SVal Getters
SVal car(SVal s) {return get<pair<SVal, SVal>*>(s.value)->first;}
SVal cdr(SVal s) {return get<pair<SVal, SVal>*>(s.value)->second;}
int get_number(SVal s) {return get<int>(s.value);}
string get_symbol(SVal s) {return get<string>(s.value);}
function<SVal(SVal)> get_func(SVal s) {return get<function<SVal(SVal)>>(s.value);}


// SVal type checker
bool is_nil(SVal s) {return holds_alternative<Nil>(s.value);}
bool is_number(SVal s) {return holds_alternative<int>(s.value);}
bool is_symbol(SVal s) {return holds_alternative<string>(s.value);}
bool is_cons(SVal s) {return holds_alternative<pair<SVal, SVal>*>(s.value);}
bool is_error(SVal s) {return holds_alternative<Err>(s.value);}
bool is_list(SVal s) {
    if (is_number(s) || is_symbol(s) || is_error(s)) return false;
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

// Evaluate SVal
SVal eval(Environment *env, SVal expr){
    if (is_number(expr) || is_nil(expr)) return expr;
    else if (is_symbol(expr)) return env->get(get_symbol(expr));
    else if (is_list(expr)){
        SVal op = car(expr); 
        SVal operands = cdr(expr);
        if (is_symbol(op)){ // special forms
            string sym = get_symbol(op);
            if (sym == "if"){
                // (if conditional then else)
                expr = cdr(expr);
                SVal sconditional = car(expr); expr = cdr(expr);
                SVal sthen = car(expr); expr = cdr(expr);
                SVal selse = car(expr); expr = cdr(expr);
                return is_nil(eval(&global, sconditional)) ? eval(&global, selse) : eval(&global, sthen);
            }
            else if (sym == "define"){
                // (define var expr)
                env->add(get_symbol(car(operands)), eval(env, car(cdr(operands))));
                return SVal();
            }
            else{
                function<SVal(SVal)> func = get_func(env->get(sym));
                return func(operands);
            }
        }
    }
    return SVal();
}

// Builtin Functions
SVal add(SVal s){
    int sum = 0;
    while (!is_nil(s)){
        sum += get_number(eval(&global, car(s)));
        s = cdr(s);
    }
    return sum;
};
SVal subtract(SVal s){
    int diff = get_number(eval(&global, car(s)));
    s = cdr(s);
    while (!is_nil(s)){
        diff -= get_number(eval(&global, car(s)));
        s = cdr(s);
    }
    return diff;

}
SVal multiply(SVal s){
    int prod = 1;
    while (!is_nil(s)){
        prod *= get_number(eval(&global, car(s)));
        s = cdr(s);
    }
    return prod;
}
SVal divide(SVal s){
    int div = get_number(eval(&global, car(s)));
    s = cdr(s);
    while (!is_nil(s)){
        div /= get_number(eval(&global, car(s)));
        s = cdr(s);
    }
    return div;
}