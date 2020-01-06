#include "pch.h"
#include "Linear.h"

Linear::Linear(){}
Linear::~Linear(){}
Linear::Linear(int a) : Term(a) {}
void Linear::diff() {
	result = to_string(a);
}