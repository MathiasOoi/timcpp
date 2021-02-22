#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "SVal.hpp"

using namespace std;

string SVal::repr(){
    ostringstream oss;

    if (this->is_nil()) oss << "()";
    else if (this->is_number()) oss << number;
    else if (this->is_symbol()) oss << symbol;
    else if (this->is_cons()) oss << "(" << left->repr() << " " << right->repr() << ")" ;

    return oss.str();
}
