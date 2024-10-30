#include <iostream>
#include <concepts>     // to use concepts, you should first include the library

// Reference(s) => https://www.youtube.com/watch?v=8jLOx1hD3_o
// (freeCodeCamp.org)
// https://en.cppreference.com/w/cpp/concepts/floating_point

/* template <typename T>    // This was the old version we learned

T add(T a, T b){
    return a+b;
}*/


// Now, the syntax1
/*
template <typename T>
requires std::integral<T>   // this concept enforce the template functions we use to be integral type
T add(T a, T b){
    return a + b;
}
*/


// Syntax2
/*
template <std::integral T>
T add(T a, T b){
    return a + b;
}
*/


// Syntax3
/*
auto add(std::integral auto a, std::integral auto b){
    return a + b;
}
*/


// Syntax4
template <typename T>
T add(T a, T b) requires std::integral<T>{
    return a + b;
}


// An example ( as you see, we are trying Syntax2 here )
template <std::floating_point R>
R subtract(R a, R b){
    return a - b;
}


int main(){
    
    char a1{10};    // know that char is also integral type
    char a2{20};
    auto result1 = add(a1, a2);
    std::cout << "result1 is : "  << static_cast<int>(result1) << std::endl;
    
    int b1{15};
    int b2{23};
    auto result2 = add(b1, b2);
    std::cout << "result2 is : " << result2 << std::endl;    
    
    
    double c1{9.9};
    double c2{1.2};
    auto result3 = add(c1, c2); 
    std::cout << "result3 is : " << result3 << std::endl;   // when you run the code first time, it will give compiler error
                                                            // because we made a constraint that arguments should be integral type
                                                            // but in here, it is double type. You can take here into comment


    // Example
    /*
    std::cout << std::endl;
    double ex1{23.5};
    double ex2{34.3};
    auto ex_result = subtract(ex1, ex2);    // now, we made a reverse constraint of above.
                                            // we said that the arguments should be floating point numbers.
                                            // if you try to pass int numbers, you will get compiler error.
    std::cout << "ex_result : " << ex_result << std::endl;
    */

    return 0;
}