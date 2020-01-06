#pragma once
#include "pch.h"
#include "Log.h"

class Log10: public Log
{
public:
	Log10();
	~Log10();
	Log10(int a, int b);
	void diff();
};

