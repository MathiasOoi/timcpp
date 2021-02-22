#include <iostream>
#include <string>
#include <sstream>

#include "SVal.hpp"

using namespace std;

int main(){
    SVal v(SVal(SVal(SVal(1), SVal(3)), SVal(2)), SVal(4));
    cout << v.which << endl;
    cout << v.is_nil() << v.is_number() << v.is_symbol() << v.is_cons() << endl;
    cout << v.to_string() << endl;
}