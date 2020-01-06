#include "pch.h"
#include "LogE.h"

LogE::LogE(){}
LogE::~LogE(){}
LogE::LogE(int a, int b) : Log(a, b) {}
void LogE::diff() {
	if (b == 0) {
		a = 0;
	}
	result = to_string(a) + "/x";
}
