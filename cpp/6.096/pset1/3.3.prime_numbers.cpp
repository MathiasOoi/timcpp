#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 2; n > 0; ++i){
        bool prime = true;
        for (int k = 2; k < sqrt(i); ++k){
            if (i % k == 0){
                prime = false;
                break;
            }
        }
        if (prime){
            cout << i << "\n";
            n--;
        }
    }

}