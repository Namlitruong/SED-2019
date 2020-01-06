#pragma once
#include "pch.h"
#include "Nonlinear.h"

class Log : public Nonlinear
{
public:
	Log();
	~Log();
	Log(int a, int b);
	void diff();
};

