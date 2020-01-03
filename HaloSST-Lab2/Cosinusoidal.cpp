#include "Cosinusoidal.h"

Cosinusoidal::Cosinusoidal() {}
Cosinusoidal::~Cosinusoidal() {}
Cosinusoidal::Cosinusoidal(int a, int b) :Trigonometric(a, b) {}
void Cosinusoidal::diff() {
	a = -(a * b);
	result = to_string(a) + "*sin(" + to_string(b) + "*x)";
}