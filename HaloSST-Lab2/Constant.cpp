#include "pch.h"
#include "Constant.h"


Constant::Constant() { }
Constant::~Constant() { }
Constant::Constant(int a): Term(a){}
void Constant::diff() {
	a = 0;
	result = "0";
}