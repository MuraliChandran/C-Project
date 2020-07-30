#pragma once
#include<stdio.h>
#include "Names.h"
#include "HotDog.h"

struct ONode
{
	ONode *next;
	ONode *prev;
	HotDog hotdog;
};


class Order
{
public:

	Order();
	Order(Name n);

	void Add(HotDog hotdog);

	Name IN;
	ONode *n = nullptr;

	~Order();
	
};