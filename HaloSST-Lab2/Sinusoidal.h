#pragma once
#include "pch.h"
#include "Trigonometric.h"

class Sinusoidal:public Trigonometric
{
public:
	Sinusoidal();
	~Sinusoidal();
	Sinusoidal(int a, int b);
	void diff();
};

