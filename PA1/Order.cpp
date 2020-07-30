#include "Order.h"
ONode *header = nullptr;

Order::Order()
{
}

Order::Order(Name n)
{
	IN = n;
}

void Order::Add(HotDog hotdog)
{

	if (n == nullptr)
	{
		n = new ONode();
		n->next = nullptr;
		n->prev = nullptr;
		
		n->hotdog = hotdog;

		header = n;
	}
	else
	{
		ONode *n1 = new ONode();

		header->next = n1;
		n1->prev = header;
		n1->next = nullptr;

		n1->hotdog = hotdog;

		header = header->next;
	}
}

Order::~Order()
{
}



