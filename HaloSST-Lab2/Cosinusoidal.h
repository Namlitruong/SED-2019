#pragma once
#include "Trigonometric.h"
class Cosinusoidal: public Trigonometric
{
public:
	Cosinusoidal();
	~Cosinusoidal();
	Cosinusoidal(int a, int b);
	void diff();
};

