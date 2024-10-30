#include <iostream>
#include <concepts>

// Reference => https://www.youtube.com/watch?v=8jLOx1hD3_o
// (freeCodeCamp.org)

template <typename T>
concept TinyType = requires(T a){
    sizeof(T) <= 4;             // Simple requirement
    requires sizeof(T) <= 4;    // Nested requirement
};

template <typename T>
//requires std::integral<T> || std::floating_point<T>     // OR operator
requires std::integral<T> && TinyType<T>
T add(T a, T b){
    return a+b;
}

int main(){

    long long int x{14};    // this type will give you error
    long long int y{16};

    std::cout << "sizeof(add(x,y)) : " << sizeof(add(x,y)) << std::endl;
    add(x,y);   
    
    return 0;
}