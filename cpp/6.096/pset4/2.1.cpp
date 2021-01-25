#include <iostream>

template<typename T>
T min(T x, T y){
    return x < y ? x : y;
}

int main(){
    std::cout << min(5, 3) << std::endl;
    std::cout << min(2.7, 3.2) << std::endl;
}