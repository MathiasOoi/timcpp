#include <iostream>

using namespace std;

void printArray(const int n[], const int len){
    for (int i = 0; i < len-1; ++i) cout << n[i] << ",";
    cout << n[len-1] << endl;
}

int main(){
    int n[5] = {1, 2, 3, 4, 5};
    printArray(n, 5);
}