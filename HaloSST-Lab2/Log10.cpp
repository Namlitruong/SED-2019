#include "pch.h"
#include "Log10.h"

Log10::Log10(){}
Log10::~Log10(){}
Log10::Log10(int a, int b):Log(a,b){}
void Log10::diff() {
	if (b == 0) {
		a = 0;
	}
	result = to_string(a) + "/(x*ln(10))";
}