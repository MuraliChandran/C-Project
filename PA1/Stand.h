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
	void Remove(Name name);
	char* ReturnEnumValue(Condiments Cond);
	char* ReturnEnumName(Name name);
	void FindNumOrders();
	void Intitiate();


	SNode *n = nullptr;
	int count = 0;
	int currentOrder = 0;
	int peakOrder = 0;

	
	
};