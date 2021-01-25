#include <iostream>

using namespace std;

int main(){
    char * oddOrEven = "Never odd or even";
    // 1.
    char *nthCharPtr = &oddOrEven[5];
    // 2.
    nthCharPtr -= 2;
    // 3.
    cout << *nthCharPtr << endl;
    // 4.
    char **pointerPtr = &nthCharPtr;
    // 5.
    cout << pointerPtr << endl;
    // 6.
    cout << **pointerPtr << endl;
    // 7.
    nthCharPtr++;
    // 8.
    cout << nthCharPtr - oddOrEven;

}