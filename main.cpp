/** @file main.cpp
 *  @brief Gives examples of the use of the Fraction class 
 *  @author Aviva Prins
 *  @date 12/27/2018
*/

#include <iostream>
#include "Fraction.h"

int main(){
    Fraction<int> a;
    Fraction<int> b(3,2);
    Fraction<int> c(2, 4);
    std::cout<<a <<std::endl <<b <<std::endl << c <<std::endl;
    b/=c;
    std::cout<<b;
    return 0;
}