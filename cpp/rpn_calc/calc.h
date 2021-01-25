#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <sstream>

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
        string repr(){
            ostringstream oss;
            oss << "[";
            if (!v.empty()){
                for (int i = 0; i < v.size() - 1; ++i){
                    oss << v[i] << ", ";
                }
                oss << v[v.size() - 1] << "]" << endl;
            }
            return oss.str();
        }
};

class Calc{
    private:
        Stack stack;
        unordered_map<string, function<double(Stack*)> > functions;
        unordered_map<string, double> variables;
        bool store_var = false, set_var = false;
    public:
        void insert(const string token);
        string repr() {return stack.repr();}
        string get() {return to_string(stack.top());}
        void register_fn(string name, function<double(Stack*)> new_fn);
        void store (string var_name);
        void set(string var_name);
};