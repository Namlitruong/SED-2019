#pragma once
#include "Term.h"

class Linear : public Term
{
public:
	Linear();
	~Linear();
	Linear(int a);
	void diff();
};

