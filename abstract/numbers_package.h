#include "../io.h"
#include <typeinfo>

//base number class
//defined as a single value or an ordered pair
class number {

	private:

		double a, b;

	public:

		double x, y;
		number(double a): x(a) {}
		number(double a, double b) : x(a), y(b) {}

};

//integer class
//defined as an ordered pair
class integer: public number {

	public:

		integer(double a, double b) : number(a, b) {}

		int get_value(){
			return x - y;
		}

		bool is_unit(){
			return (get_value() == 1) || (get_value() == -1);
		}

		void zero() {

			x = 0;
			y = 0;

		}

		void print() {
			std::cout << x << " - " << y << '\n';
		}

};

//rational number class
//defined as an ordered pair
class rational: public number {

	public:

		rational(double a, double b) : number(a, b) {}

		double get_value(){

			if (y != 0){
				return x/y;
			}

		}

		bool is_unit(){
			return get_value() != 0;
		}

		void zero() {

			x = 0;
			y = 1;

		}

		void print() {
			std::cout << x << " / " << y << '\n';
		}

};

//real number class
//defined as a single value or an ordered pair
class real: public number {

	public:

		real(double a) : number(a) {}
		real(double a, double b) : number(a, b) {}

		double get_value() {
			return x;
		}

		bool is_unit(){
			return get_value() != 0;
		}

		void zero() {
			x = 0;
		}

		void print() {
			std::cout << x << '\n';
		}

};

//complex number class
//defined as an ordered pair
class complex: public number {

	public:

		complex(double a, double b) : number(a, b) {}

		double get_value() {}

		bool is_unit(){
			return (x != 0) && (y!=0);
		}

		void zero() {

			x = 0;
			y = 0;

		}

		void print() {

			if (y < 0) {
				std::cout << x << " - i" << -y << '\n';
			}
			else {
				std::cout << x << " + i" << y << '\n';
			}

		}

};
