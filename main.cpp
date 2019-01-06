/** @file main.cpp
 *  @brief Gives examples of the use of the Fraction class 
 *  @author Aviva Prins
 *  @date 12/27/2018
*/

#include <iostream>
#include "Fraction.h"

int main(){
    Fraction<int> a(1,2);
    Fraction<int> b(3,2);
    a/=b;
    std::cout << a << std::endl;
    return 0;
}