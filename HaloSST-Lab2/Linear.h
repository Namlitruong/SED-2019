#pragma once
#include "pch.h"
#include "Term.h"

// CHILD CLASS
class Linear : public Term
{
public:
	Linear();
	~Linear();
	Linear(int a);
	void diff();
};

