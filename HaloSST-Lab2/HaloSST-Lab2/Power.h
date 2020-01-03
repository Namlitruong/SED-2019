#pragma once
#include "Nonlinear.h"

class Power : public Nonlinear
{
public:
	Power();
	~Power();
	Power(int a, int b);
	void differentiate();
};

