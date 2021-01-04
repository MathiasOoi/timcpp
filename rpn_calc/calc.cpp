#include <string>
#include "calc.h"

// RPN calc
void Calc::insert(string token){
    if (operators.find(token) == operators.end()){
        stack.push(std::stod(token));
    } 
    else{
        double &a = stack.top(); stack.pop();
        double &b = stack.top(); stack.pop();
        if (token == "+"){stack.push(b + a);} 
        else if (token == "-"){stack.push(b - a);}
        else if (token == "*"){stack.push(b * a);}
        else if (token == "/"){stack.push(b / a);}
    }
}


