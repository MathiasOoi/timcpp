#include <iostream>

using namespace std;

int main(){
    short number;
    cout << "Enter a number: ";
    cin >> number;

    cout << "The factorial of " << number << " is ";
    unsigned long long accumulator = 1;
    for (; number > 0; accumulator *= number --);
    cout << accumulator << ".\n";
}