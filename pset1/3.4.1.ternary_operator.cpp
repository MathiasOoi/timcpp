#include <iostream>

using namespace std;

int main(){
    int n;
    while (true){
        cin >> n;
        cout << ((n % 5 == 0 && n >=0) ? n/5 : -1) << "\n";
    }
}