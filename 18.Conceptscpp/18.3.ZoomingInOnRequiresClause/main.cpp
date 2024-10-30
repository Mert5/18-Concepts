#include <iostream>
#include <concepts>

// Reference => https://www.youtube.com/watch?v=8jLOx1hD3_o
// (freeCodeCamp.org)

// Nested Requirements
template <typename T>
concept TinyTipe = requires (T var){
    sizeof(T) <= 4;  // Simple requirement : Only enforces syntax
    requires sizeof(T) <= 4;    // Nested requirements
                                // you should add this line in order to return error bigger than 4 bits
};


// Compound Requirements
template <typename T>
concept Addable = requires(T a, T b){
    //noexcept is optional
    {a+b} noexcept -> std::convertible_to<int>; // Compound requirement
    //Check if a + b is valid syntax, doesn't throw expetions(optional), and the result
    //is convertible to int(optional)
};


Addable auto add(Addable auto a, Addable auto b){
    return a + b;
}


int main(){

    char c1{37};
    char c2{45};
    
    double d1{56};
    double d2{87};

    //std::string w1{"Hello"};    // adding these two words is not convertible to int
    //std::string w2{"World"};    // that's why this will give error.

    //auto w = w1+w2;

    std::cout << "sizeof(add(d1+d2)) : " << sizeof(add(d1,d2)) << std::endl;

    std::cout << "result: " << add(d1,d2) << " Done!" << std::endl;

    return 0;
}