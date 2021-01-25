#include <iostream>

using namespace std;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    int x = 3, y = 2;
    swap(x, y);
    cout << x << y;
}