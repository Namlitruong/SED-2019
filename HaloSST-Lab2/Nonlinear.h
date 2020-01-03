#pragma once
#include"Term.h"

//CHILD CLASS

class Nonlinear : public Term
{
protected:
	int b;
public:
	Nonlinear();
	~Nonlinear();
	Nonlinear(int a, int b);
	void diff();
};

