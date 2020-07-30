#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Condiments.h"
#include <iostream>
using namespace std;

struct Node
{
	Node* next;
	Node* prev;
	Condiments CondV;
};

class HotDog
{

public:
	void Add(Condiments Cond);
	void Minus(Condiments Cond);
	
	void InsertNode(Condiments Cond);
	
	
	Node* n =  nullptr;
	
	
};
