#include <iostream>

using namespace std;

int len(const char *s){
    int total = 0, i = 0;
    while (*(s + i) != '\0'){
        total++;
        i++;
    }
    return total;
}

int main(){
    const char *s = "Hello world";
    cout << len(s) << endl;
}