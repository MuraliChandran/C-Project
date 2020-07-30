#include "Stand.h"
#include "Order.h"

SNode *header = nullptr;

Stand::Stand()
{
}

void Stand::Add(Order order)
{
	(void)order;
	if (n == nullptr)
	{
		n = new SNode();

		n->next = nullptr;
		n->prev = nullptr;

		n->order = order;

		header = n;
	}
	else
	{
		SNode *n1 = new SNode();
		
		header->next = n1;
		n1->prev = header;
		n1->next = nullptr;

		n1->order = order;

		header = header->next;

	}

}

void Stand::Print()
{
}
