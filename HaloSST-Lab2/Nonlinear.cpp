#include "Nonlinear.h"

Nonlinear::Nonlinear() {}
Nonlinear::~Nonlinear() {}
Nonlinear::Nonlinear(int a, int b) : Term(a) {
	this->b = b;
}
void Nonlinear::diff() {}