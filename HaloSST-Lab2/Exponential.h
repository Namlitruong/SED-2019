#pragma once
#include "pch.h"
#include "Nonlinear.h"

class Exponential:public Nonlinear
{
public:
	Exponential();
	~Exponential();
	Exponential(int a, int b);
	void diff();
};

