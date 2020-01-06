#include "pch.h"
#include "Power.h"

Power::Power(){}
Power::~Power(){}
Power::Power(int a, int b): Nonlinear(a,b){}
void Power::diff() {
	a = a * b;
	b = b - 1;
	if (b == 1) {
		result = to_string(a) + "*x";
	}
	else if (b > 1) {
		result = to_string(a) + "*x^" + to_string(b);
	}
	else if (b < 1 && b < 0) {
		result = to_string(a) + "*x^(" + to_string(b) + ")";
	}
	else {
		result = to_string(a);
	}
}