#include <iostream>
#include <concepts>

// Reference => https://www.youtube.com/watch?v=8jLOx1hD3_o
// (freeCodeCamp.org)

// This syntax constraints the auto parameters you pass in
// to comply with the std::integral concept
std::integral auto add(std::integral auto a, std::integral auto b){    // we only support integral types
    return a+b;                                                         // in this function here.
}

int main(){

    //add(8.7,9.3);   // will give you error because they are not integral type.

    std::integral auto x = add(6,4);
    
    std::floating_point auto y = add(6.5,7.8);   // will give you error because you defined as integral type

    //std::floating_point auto z = 7;           //also will give you error, because 7 is an integral type

    return 0;
}