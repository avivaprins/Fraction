/** @file main.cpp
 *  @brief Gives examples of the use of the Fraction class 
 *  @author Aviva Prins
 *  @date 12/27/2018
*/

#include <iostream>
#include "Fraction.h"
#include "Integer.h"

int main(){
    Fraction<int> a(1,2);
    Fraction<int> b(3,2);
    std::cout << a+b << std::endl;
    std::cout << a-b << std::endl;
    std::cout << a*b << std::endl;
    std::cout << a/b << std::endl;
    std::cout << (a>b) << std::endl;
    std::cout << (a<b) << std::endl;

    Integer x = 1;
    Integer y = 2;
    Integer z = 3;

    // Fraction<Integer> c(x,y);
    // Fraction<Integer> d(z,y);
    // a = c;
    // b = d;
    // std::cout << a+b << std::endl;
    // std::cout << a-b << std::endl;
    // std::cout << a*b << std::endl;
    // std::cout << a/b << std::endl;
    // std::cout << (a>b) << std::endl;
    // std::cout << (a<b) << std::endl;
    return 0;
}