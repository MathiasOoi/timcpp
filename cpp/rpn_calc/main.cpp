#include <iostream>
#include <functional>
#include "calc.cpp"

using namespace std;

int main(){
    Calc calc;
    function<double(Stack*)> add_fn = add_f;
    function<double(Stack*)> minus_fn = minus_f;
    function<double(Stack*)> multiply_fn = multiply_f;
    function<double(Stack*)> divide_fn = divide_f;
    function<double(Stack*)> power_fn = power_f;
    function<double(Stack*)> sqrt_fn = sqrt_f;
    function<double(Stack*)> factorial_fn = factorial_f;
    calc.register_fn("+", add_fn);
    calc.register_fn("-", minus_fn);
    calc.register_fn("*", multiply_fn);
    calc.register_fn("/", divide_fn);
    calc.register_fn("^", power_fn);
    calc.register_fn("sqrt", sqrt_fn);
    calc.register_fn("!", factorial_fn);

    string token;

    while(cin >> token){
        cout << "Token: " << token << endl;
        if (token.empty()) break;
        calc.insert(token);
        cout << calc.repr();
    }
}