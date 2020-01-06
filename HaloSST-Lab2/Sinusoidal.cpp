#include "Sinusoidal.h"

Sinusoidal::Sinusoidal() {}
Sinusoidal::~Sinusoidal() {}
Sinusoidal::Sinusoidal(int a, int b) : Trigonometric(a, b) {}
void Sinusoidal::diff() {
	a = a * b;
	result = to_string(a) + "*cos(" + to_string(b) + "*x)";
}