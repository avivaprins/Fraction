/** @file Fraction.h
 *  @brief stores numbers as fractions
 *  @author Aviva Prins
 *  @date 12/27/2018
 * 
 *  The fractions are stored in reduced form.
 *  TODO: consider converting to and from double
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
		if(f.bottom == 1) {
			out << f.top;
		}
		else {
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

	//TODO: make this more robust for type conflicts (type casting, error messages)
	template<typename T>
	Fraction<F>(T numerator); //numerator/1

	template<typename T, typename B>
	Fraction<F>(T numerator, B denominator); // numerator/denominator

	// Basic math
	Fraction& operator+=(const Fraction& value); // Adds value to lhs and returns lhs
	Fraction& operator-=(const Fraction& value); // Subtracts value from lhs and returns lhs
	Fraction& operator*=(const Fraction& value); // Multiplies value to lhs and returns lhs
	Fraction& operator/=(const Fraction& value); // Divides value from lhs and returns lhs

private:
	void reduce();

	F top;
	F bottom;

};

#endif

/** Default constructor of Fraction class
 */
template<typename F>
inline Fraction<F>::Fraction() : top(0), bottom(1) {}

/** Constructor with one parameter
 *  @param numerator is the numerator of the fraction (denominator defaults to 1)
 *  TODO: make this more robust for type conflicts (type casting, error messages)
 */
template<typename F>
template<typename T>
inline Fraction<F>::Fraction(T numerator) : top(numerator), bottom(1) {}

/** Constructor with two parameters
 *  @param numerator is the top of the fraction
 *  @param denominator is the bottom of the fraction
 *  TODO: make this more robust for type conflicts (type casting, error messages)
 */
template<typename F>
template<typename T, typename B>
inline Fraction<F>::Fraction(T numerator, B denominator) : top(numerator), bottom(denominator) {
	reduce();
}

/** Adds value to lhs
 *  @param value is the value being added to lhs
 *  @return reference to lhs
 */
template<typename F>
Fraction<F>& Fraction<F>::operator+=(const Fraction& value){
	(top *= value.bottom) += value.top*bottom;
	bottom *= value.bottom;
	reduce();
	return *this;
}

/** Subtracts value from lhs
 *  @param value is the value being subtracted from lhs
 *  @return reference to lhs
 */
template<typename F>
Fraction<F>& Fraction<F>::operator-=(const Fraction& value){
	(top *= value.bottom) -= value.top*bottom;
	bottom *= value.bottom;
	reduce();
	return *this;
}

/** Multiplies value to lhs
 *  @param value is the value being multiplied
 *  @return reference to lhs
 */
template<typename F>
Fraction<F>& Fraction<F>::operator*=(const Fraction& value){
	top *= value.top;
	bottom *= value.bottom;
	reduce();
	return *this;
}

/** Divides value from lhs
 *  @param value is the value being divided
 *  @return reference to lhs
 */
template<typename F>
Fraction<F>& Fraction<F>::operator/=(const Fraction& value) {
	top *= value.bottom;
	bottom *= value.top;
	reduce();
	return *this;
}

/** Greatest Common Divisor
 *  @param a first value
 *  @param b second value
 *  @return the greatest common divisor between a and b
 *  This function utilizes the Euclidean algorithm for finding the gcd.
 */
template<typename T>
T gcd(T a, T b) {
	if(a==b) {
		return a;
	}
	else if(a>b) {
		return gcd(a-b, b);
	}
	else {
		return gcd(a, b-a);
	}
}

/** Reduces the fraction
 *  Gives warnings for t/0 and 0/0
 */
template<typename F>
void Fraction<F>::reduce() { // 0/5 -> 0/1
	if(top == 0 && bottom != 0) {
		bottom = 1;
	}
	else if(top == 0 && bottom == 0) { // 0/0 -> warning
		std::cout << "Warning: " << *this << std::endl;
	}
	else if(bottom == 0) { // 5/0 -> warning
		std::cout << "Warning: " << *this << std::endl;
	}
	else { // 5/5 -> 1/1
		F divisor = gcd(std::abs(top), std::abs(bottom));
		top /= divisor;
		bottom /= divisor;

		// if -t/b or t/b, done.
		// if t/-b or -t/-b:
		if(bottom < 0) {
			top = -top;
			bottom = -bottom;
		}
	}
}