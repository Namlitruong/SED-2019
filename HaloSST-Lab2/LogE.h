#pragma once
#include "pch.h"
#include "Log.h"

class LogE:public Log
{
public:
	LogE();
	~LogE();
	LogE(int a, int b);
	void diff();
};

