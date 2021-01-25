#include <iostream>

using namespace std;

int sum(const int n[], const int len){
    int total = 0;
    for (int i = 0; i < len; ++i){
        total += n[i];
    }
    return total;
}

int main(){
    int n[4] = {1, 2, 3, 4};
    cout << sum(n, 4) << endl;
}