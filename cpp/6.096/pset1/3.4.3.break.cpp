#include <iostream>

using namespace std;

int main(){
    int n;
    while (true){
        cin>>n;
        if (n % 5 == 0){
            cout << n/5 << "\n";
            break;
        }
        else if (n < 0){
            cout << "Goodbye!" << "\n";
            break;
        }
        else{
            continue;
        }
    }
}