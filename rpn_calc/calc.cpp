#include <vector>
#include <string>
#include <unordered_set>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include "calc.h"

// RPN calc
void Calc::insert(string token){
    if (operators.find(token) == operators.end()){
        stack.push(std::stod(token));
    } 
    else{
        double &a = stack.top(); stack.pop();
        double &b = stack.top(); stack.pop();
        if (token == "+"){stack.push(a + b);} 
        else if (token == "-"){stack.push(a - b);}
        else if (token == "*"){stack.push(a * b);}
        else if (token == "/"){stack.push(a / b);}
    }
}


