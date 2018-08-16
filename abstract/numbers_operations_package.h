#include "numbers_package.h"

//sum of two numbers
template <class set>
set add(set a, set b) {

	if (typeid(set).name() == typeid(integer).name()) {
		
		set ans((a.x + b.x), (a.y + b.y));
		
		return ans;

	}
	else if (typeid(set).name() == typeid(rational).name()) {
		
		set ans((a.x * b.y + b.x * a.y), (a.y * b.y));
		
		return ans;

	}
	else if (typeid(set).name() == typeid(complex).name()) {
		
		set ans((a.x + b.x), (a.y + b.y));
		
		return ans;

	}
	else if (typeid(set).name() == typeid(real).name()) {
		
		set ans(a.get_value() + b.get_value(), 0);
		
		return ans;

	}

}

//difference between two numbers
template <class set>
set subtract(set a, set b) {
	
	if (typeid(set).name() == typeid(integer).name()) {
		
		set ans((a.x - b.x), (a.y - b.y));
		
		return ans;

	}
	else if (typeid(set).name() == typeid(rational).name()) {
		
		set ans((a.x * b.y - b.x * a.y), (a.y * b.y));
		
		return ans;

	}
	else if (typeid(set).name() == typeid(complex).name()) {
		
		set ans((a.x - b.x), (a.y - b.y));
		
		return ans;

	}
	else if (typeid(set).name() == typeid(real).name()) {
		
		set ans(a.get_value() - b.get_value(), 0);
		
		return ans;

	}

}

//multiply two numbers
template <class set>
set multiply(set a, set b) {

	if (typeid(set).name() == typeid(integer).name()) {
		
		set ans((a.x * b.x + a.y * b.y), (a.x * b.y + b.x * a.y));
		
		return ans;

	}
	else if (typeid(set).name() == typeid(rational).name()) {
		
		set ans((a.x * b.x), (a.y * b.y));
		
		return ans;

	}
	else if (typeid(set).name() == typeid(complex).name()) {
		
		set ans((a.x * b.x - a.y * b.y), (a.x * b.y + a.y * b.x));
		
		return ans;

	}
	else if (typeid(set).name() == typeid(real).name()) {
		
		set ans(a.get_value() * b.get_value(), 0);
		
		return ans;

	}

}

//divide two numbers
template <class set>
set divide(set a, set b) {

	if (typeid(set).name() == typeid(integer).name()) {

		if (logging) {
			output("Warning: Division not defined for integers.");
		}
		
		set ans(0, 0);
		
		return ans;

	}
	else if (typeid(set).name() == typeid(rational).name()) {
		
		set ans((a.x * b.y), (a.y * b.x));
		
		return ans;

	}
	else if (typeid(set).name() == typeid(complex).name()) {
		
		set ans(((a.x * b.x + a.y * b.y)/(b.x * b.x + b.y * b.y)), ((a.y * b.x - a.x * b.y)/(b.x * b.x + b.y * b.y)));
		
		return ans;

	}
	else if (typeid(set).name() == typeid(real).name()) {
		
		set ans(a.get_value() / b.get_value(), 0);
		
		return ans;

	}

}


//return number as real number
template <class set>
real as_real(set a) {

	real ans(0);

	if (typeid(set).name() == typeid(complex).name()) {

		if (a.y == 0) {
			ans.x = a.x;
		}
		else {

			if (logging) {
				output("Entry in as_real is not a real number.");
			}
			
			return ans;
		}

	}

	else if (typeid(set).name() != typeid(double).name()) {
		
		ans.x = a.get_value();
	
	}

	return ans;

}

//return values in vector as real numbers
template <class set>
std::vector<real> as_real_vector(const std::vector<set> a) {

	std::vector<real> ans;

	for (int i = 0; i < a.size(); ++i) {
		ans.push_back(as_real(a[i]));
	}

	return ans;

}

//return entry as complex number
template <class set>
complex as_complex(set a) {

	complex ans(0,0);

	if (typeid(set).name() == typeid(complex).name()) {

		ans.x = a.x;
		ans.y = a.y;

	}

	else {

		ans.x = a.get_value();
		ans.y = 0;

	}

	return ans;

}

//return vector of numbers as complex vector
template <class set>
std::vector<complex> as_complex_vector(const std::vector<set> a) {

	std::vector<complex> ans;

	for (int i = 0; i < a.size(); ++i) {
		ans.push_back(as_complex(a[i]));
	}

	return ans;

}

//find complex conjugate of entry
complex conjugate(const complex a) {
	
	complex ans(0, 0);
	
	if (a.y == 0) {
		
		ans.x = a.x;
		ans.y = 0;

	}
	else {
		
		ans.x = a.x;
		ans.y = -a.y;

	}
	
	return ans;

}

//compute modulus of complex number
real modulus(const complex a) {

	real ans = as_real(multiply(a, conjugate(a)));
	return ans;

}