#include <iostream>

using namespace std;

void printArray(const int n[], const int len){
    for (int i = 0; i < len-1; ++i) cout << n[i] << ",";
    cout << n[len-1] << endl;
}

void reverse(int n[], const int len){
    int temp[len];
    for (int i = 0; i < len; ++i){
        temp[len-i-1] = n[i];
    }
    for (int i = 0; i < len; ++i){
        n[i] = temp[i];
    }
}

int main(){
    int n[6] = {1, 2, 3, 4, 5, 6};
    reverse(n, 6);
    printArray(n, 6);
}