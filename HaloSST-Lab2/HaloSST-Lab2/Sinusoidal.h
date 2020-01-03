#pragma once
#include "Trigonometric.h"

class Sinusoidal:public Trigonometric
{
public:
	Sinusoidal();
	~Sinusoidal();
	Sinusoidal(int a, int b);
	void diff();
};

