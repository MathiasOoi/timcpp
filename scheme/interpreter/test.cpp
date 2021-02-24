#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    int x = d.front();
    cout << x;
    d.pop_front();
    cout << x;
}