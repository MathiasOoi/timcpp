#include <string>
#include <cmath>
#include "calc.h"

// RPN calc
void Calc::insert(const string token){
    if (store_var){
        store(token);
        store_var = false;
    }
    else if (set_var){
        set(token);
        set_var = false;
    }
    else if (token == "store"){
        store_var = true;
    }
    else if (token == "set"){
        set_var = true;
    }
    else if (functions.find(token) == functions.end()){
        stack.push(std::stod(token));
    } 
    else{
        stack.push(functions[token](&stack));
    }
}

void Calc::register_fn(string name, function<double(Stack*)> new_fn){
    functions[name] = new_fn;
}

void Calc::store(string var_name){
    double a = stack.top(); stack.pop();
    variables[var_name] = a;
}

void Calc::set(string var_name){
    stack.push(variables[var_name]);
}

double add_f(Stack *stk){
    const double a = stk->top(); stk->pop();
    const double b = stk->top(); stk->pop();
    return b + a;
}

double minus_f(Stack *stk){
    const double a = stk->top(); stk->pop();
    const double b = stk->top(); stk->pop();
    return b - a;
}

double multiply_f(Stack *stk){
    const double a = stk->top(); stk->pop();
    const double b = stk->top(); stk->pop();
    return b * a;
}

double divide_f(Stack *stk){
    const double a = stk->top(); stk->pop();
    const double b = stk->top(); stk->pop();
    return b / a;
}

double factorial_f(Stack *stk){
    double a = stk->top(); stk->pop();
    double ans = 1;
    for (; a > 0; ans *= a--);
    return ans;

}

double power_f(Stack *stk){
    const double a = stk->top(); stk->pop();
    const double b = stk->top(); stk->pop();
    return pow(b, a);
}

double sqrt_f(Stack *stk){
    const double a = stk->top(); stk->pop();
    return sqrt(a);
}


