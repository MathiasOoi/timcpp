#include <iostream>

using namespace std;

int main(){
    int total = 0, n, x, highest = INT_MIN, lowest= INT_MAX;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> x;
        if (x > highest){
            highest = x;
        }
        else if (x < lowest){
            lowest = x;
        }
        total += x;
    }
    cout << "Mean: " << total/n << "\n";
    cout << "Max: " << highest << "\n";
    cout << "Min: " << lowest << "\n";
    cout << "Range: " << highest-lowest << "\n";
}