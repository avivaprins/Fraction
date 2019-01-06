/** @file main.cpp
 *  @brief Gives examples of the use of the Fraction class 
 *  @author Aviva Prins
 *  @date 12/27/2018
*/

#include <iostream>
#include "Fraction.h"
//#include "Fraction.cpp"

int main(){
    Fraction<int> a;
    Fraction<int> b(2);
    Fraction<int> c(3, 4);
    std::cout<<"Hello World"<<std::endl;
    std::cout<<a <<std::endl <<b <<std::endl << c <<std::endl;
    Fraction<int> f;
    std::cin >> f;
    std::cout<<f;
    return 0;
}