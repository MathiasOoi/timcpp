#include <iostream>

using namespace std;

int sum(const int n[], const int len){
    if (len == 0) return 0;
    return n[len-1] + sum(n, len-1);
}

int main(){
    int n[5] = {1, 2, 3, 4, 5};
    cout << sum(n, 5) << endl;
}