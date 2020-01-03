#pragma once
#include"Term.h"

class Nonlinear : public Term
{
protected:
	int b;
public:
	Nonlinear();
	~Nonlinear();
	Nonlinear(int a, int b);
	void differentiate();
};

