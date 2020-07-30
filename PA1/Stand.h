#pragma once
#include<stdio.h>
#include "Order.h"

struct SNode 
{
	SNode *next;
	SNode *prev;
	Order order;
};

class Stand 
{

public:

	Stand();

	void Add(Order order);
	void Print();

	SNode *n = nullptr;
};