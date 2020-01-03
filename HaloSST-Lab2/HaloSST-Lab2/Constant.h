#pragma once
#include "Term.h"

class Constant : public Term
{
public:
	Constant();
	~Constant();
	Constant(int a);
	void differentiate();
};

