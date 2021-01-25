#include <iostream>
#include <string>

using namespace std;
const string vowels = "uioae";

string pigLatinify(string s){
    if (s[0] == 'q' && s[1] == 'u'){
        return s.substr(2, s.size() - 2) + "-" + "quay";
    }
    else if (vowels.find(s[0]) != string::npos){
        return s + "way";
    }
    else {
        return s.substr(1, s.size() - 1) + "-" + s[0] + "ay";
    }
}

int main(){
    string s;
    while (true) {
        cin >> s;
        cout << pigLatinify(s) << endl;
    }
}