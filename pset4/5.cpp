#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stdexcept>

using namespace std;

void print_vector(const vector<int> &v){
    for (int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}

class Graph{
    private:
        map<int, vector<int> > graph;
        set<int> nodes;
    public:
        Graph(const vector<int> &start, const vector<int> &end){
            if (start.size() != end.size()) {throw invalid_argument("Vectors must be of equal size");}
            for (int i = 0; i < start.size(); ++i) {graph[start[i]].push_back(end[i]); nodes.insert(start[i]); nodes.insert(end[i]);}
        }
        int numOutgoing(const int nodeID){
            if (nodes.find(nodeID) == nodes.end()) {throw invalid_argument("No such nodeID");}
            return graph[nodeID].size();
        }
        const vector<int> &adjacent(const int nodeID){
            if (nodes.find(nodeID) == nodes.end()) {throw invalid_argument("No such nodeID");}
            return graph[nodeID];
        }
};

int main(){
    vector<int> v1, v2;
    v1.push_back(1); v1.push_back(1); v1.push_back(2); v1.push_back(2);
    v2.push_back(3); v2.push_back(4); v2.push_back(3); v2.push_back(4);
    Graph g(v1, v2);
    cout << g.numOutgoing(1) << endl;
    // g.adjacent(5); // throws error
    cout << g.numOutgoing(2) << endl;
    print_vector(g.adjacent(1));
    print_vector(g.adjacent(2));
}