#pragma once
#include "pch.h"
#include "Nonlinear.h"

// --------- use for sin cos equation

class Trigonometric:public Nonlinear
{
public: 
	Trigonometric();
	~Trigonometric();
	Trigonometric(int a, int b);
	void diff();
};

