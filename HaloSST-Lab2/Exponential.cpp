#include "Exponential.h"

Exponential::Exponential() {}
Exponential::~Exponential() {}
Exponential::Exponential(int a, int b) : Nonlinear(a, b) {}
void Exponential::diff() {
	a = a * b;
	result = to_string(a) + "*e^(" + to_string(b) + "x)";
}
