#pragma once
#include "Term.h"

// CHILD CLASS
class Constant : public Term
{
public:
	Constant();
	~Constant();
	Constant(int a);
	void diff();
};

