#include <iostream>
#include "calc.cpp"

using namespace std;

int main(){
    Calc calc;
    string token;

    while(cin >> token){
        cout << "Token: " << token << endl;
        if (token.empty()) break;
        calc.insert(token);
        calc.print();
    }
}