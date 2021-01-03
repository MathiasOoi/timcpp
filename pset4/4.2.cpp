#include <iostream>
#include <vector>

using namespace std;

template<class T> class Stack;

template<class T> 
Stack<T> operator+(Stack<T> &a, Stack<T> &b){
    Stack<T> new_stack = a;
    for (int i = 0; i < b.v.size(); ++i){
        new_stack.push(b.v[i]);
    }
    return new_stack;
};

template<class T>
class Stack{
    private:
        friend Stack<T> operator+<>(Stack<T> &a, Stack<T> &b);
    public:
        vector<T> v;
        bool empty() const {return v.empty();}
        void push(const T &item) {v.push_back(item);}
        T &top() {return v[v.size() - 1];}
        void pop() {v.pop_back();}
};


int main(){
    Stack<int> stack;
    stack.push(1);
    // cout << stack.top() << endl;
    stack.push(2);
    // cout << stack.top() << endl;
    stack.pop();
    // cout << stack.top() << endl;
    stack.push(2);

    Stack<int> stack2;
    stack2.push(3);
    stack2.push(4);

    Stack<int> stack_sum = stack + stack2;
    cout << stack_sum.v.size() << endl;
    for (int i = 0; i < stack_sum.v.size(); ++i)
        cout << stack_sum.v[i] << " ";
    cout << endl;
}