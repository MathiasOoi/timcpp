#include <iostream>

using namespace std;

int main(){
    const char *s = "Hello World!";
    int n, x;
    cout << "How many times do you want to print \"Hello World\"?" << "\n";
    cin >> n;
    for (int i = 0; i < n; ++i){
        cout << s << "\n";
    }
    x = n;
    cout << "\n";
    while (x-- > 0){
        cout << s << "\n";
    }
    x = n;
    cout << "\n";
    do{
        cout << s << "\n";
    }
    while (--x > 0);

}