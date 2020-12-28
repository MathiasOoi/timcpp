#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

double calculate_pi(const int n){
    srand(time(NULL));
    int count = 0;
    for (int i = 0; i < n; ++i){
        double x = rand()*1.0/RAND_MAX, y = rand()*1.0/RAND_MAX;
        if (sqrt(x*x + y*y) < 1) {
            count++;
        }
    }
    cout << count << endl;
    return 4*(count * 1.0 / n);
}

int main(){
    cout << calculate_pi(50000000) << endl;
}