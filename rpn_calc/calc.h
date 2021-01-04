#include <vector>
#include <string>
#include <iterator>
#include <stdlib.h>
#include <unordered_set>

using namespace std;

// Stack
class Stack{
    private:
        vector<double> v;
    public:
        bool empty() const {return v.empty();}
        void push(const double &item) {v.push_back(item);}
        double &top() {return v[v.size() - 1];}
        void pop() {v.pop_back();}
        void print(){
            cout << "[";
            if (!v.empty()){
                for (int i = 0; i < v.size() - 1; ++i){
                    cout << v[i] << ", ";
                }
                cout << v[v.size() - 1] << "]" << endl;
            }
        }
};

class Calc{
    private:
        Stack stack;
        unordered_set<string> operators = {"+", "-", "/", "*"};
    public:
        void insert(const string token);
        void print() {stack.print();};
        string get() {return to_string(stack.top());}
};