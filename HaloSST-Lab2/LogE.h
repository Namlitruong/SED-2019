#pragma once
#include "Log.h"

class LogE:public Log
{
public:
	LogE();
	~LogE();
	LogE(int a, int b);
	void diff();
};

