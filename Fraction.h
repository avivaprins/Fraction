/** @file Fraction.h
 *  @brief stores numbers as fractions
 *  @author Aviva Prins
 *  @date 12/27/2018
 */

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

template<typename F>
class Fraction {
public:

	/** Output operator <<
	 *  @param out alows std::cout, etc output types
	 *  @param f is the fraction to be printed
	 *  @return out so that << can be called consecutively
	 */
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f) {
		if(f.bottom == 1){
			out << f.top;
		}
		else{
			out << f.top << "/" << f.bottom;
		}
		return out;
	}

	/** Input operator >>
	 *  @param in allows std::cin, etc input types
	 *  @param f is the fraction to be stored
	 *  @return in so that >> can be called consecutively
	 * 
	 *  Note: this implementation assumes that top and bottom have the same type as the templated fraction class.
	 */
	friend std::istream& operator>>(std::istream& in, Fraction<F>& f) {
		F numerator;
		F denominator;
		in >> numerator;
		in >> denominator;
		f = Fraction(numerator, denominator);
		return in;
	}

    // Constructors
	Fraction();		 // Defaults to 0/1

	//TODO: make this more robust for type conflicts (type casting)
	template<typename T>
	Fraction<F>(T numerator); //numerator/1

	template<typename T, typename B>
	Fraction<F>(T numerator, B denominator); // numerator/denominator

private:
	F top;
	F bottom;

};

#endif

/** Default constructor of Fraction class
 */
template<typename F>
inline Fraction<F>::Fraction() : top(0), bottom(1) {std::cout<< "Default Constructor" << std::endl; };

/** Constructor with one parameter
 *  @numerator is the numerator of the fraction (denominator defaults to 1)
 *  TODO: make this more robust for type conflicts (type casting, error messages)
 */
template<typename F>
template<typename T>
inline Fraction<F>::Fraction(T numerator) : top(numerator), bottom(1) {std::cout<< "with one param" << std::endl; };

/** Constructor with two parameters
 *  @numerator is the top of the fraction
 *  @denominator is the bottom of the fraction
 *  TODO: make this more robust for type conflicts (type casting, error messages)
 */
template<typename F>
template<typename T, typename B>
inline Fraction<F>::Fraction(T numerator, B denominator) : top(numerator), bottom(denominator) {std::cout << "two params" << std::endl; }