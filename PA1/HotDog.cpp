#include "HotDog.h"
Node* header = nullptr;

void HotDog::Add(Condiments Cond)
{
	//For Everything
	if (Condiments::Everything == Cond)
	{
		for (Condiments fooInt = Condiments::Yellow_Mustard; fooInt != Cond; ((int&)fooInt) *= 2)
		{
			InsertNode(fooInt);
		}
	}
	//Not for Everything
	else
	{

		InsertNode(Cond);
	}
}

void HotDog::Minus(Condiments Cond)
{
	Node* del = n;
	while (del != nullptr)
	{
		if (del->CondV == Cond)
		{
			
			del->prev->next = del->next;
			del->next->prev = del->prev;

			del = nullptr;

			break;
			
		}
		del = del->next;
	}

}



void HotDog::InsertNode(Condiments Cond)
{
	if (n == nullptr)
	{
		n = new Node();
		n->next = nullptr;
		n->prev = nullptr;
		n->CondV = Cond;

		header = n;

	}
	else
	{
		Node *n1 = new Node();

		header->next = n1;
		n1->prev = header;
		n1->next = nullptr;

		n1->CondV = Cond;

		header = header->next;
	}
}






