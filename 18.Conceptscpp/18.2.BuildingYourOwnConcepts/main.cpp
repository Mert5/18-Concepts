#include <iostream>
#include <type_traits>
#include <concepts>

// Reference => https://www.youtube.com/watch?v=8jLOx1hD3_o
// (freeCodeCamp.org)

// Syntax1
/*
template <typename T>
concept MyIntegral = std::is_integral_v<T>;

MyIntegral auto add(MyIntegral auto a, MyIntegral auto b){
    return a+b;
}
*/

template <typename T>   // we have the concept
concept Multipliable = requires(T a, T b){
    a*b; // Just makes sure the syntax is valid
};

template <typename T>
concept Incrementable = requires(T a){
    a+=1;
    ++a;
    a++;
};


template <typename T>   // and we have the function template that is going to use this concept
requires Incrementable<T> 
T add(T a, T b){
    return a+b;
}

int main(){

    int x{14};      
    int y{21};

    add(x,y);

    double d1{15};  // double type does not satisfy the integral concept
    double d2{22};  

    //std::string str1{"Hello"};
    //std::string str2{"World"};

    add(d1,d2);     

    std::cout << "Program done!" << std::endl;

    return 0;
}