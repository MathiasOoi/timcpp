#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Stack{
    private:
        vector<T> v;
    public:
        bool empty() const {return v.empty();}
        void push(const T &item) {v.push_back(item);}
        T &top() {return v[v.size() - 1];}
        void pop() {v.pop_back();}
};


int main(){
    Stack<int> stack;
    stack.push(1);
    cout << stack.top() << endl;
    stack.push(2);
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
}