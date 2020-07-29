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



char* HotDog::ReturnEnumValue(Condiments c)
{
	if (c == Condiments::Plain)
		return "Plain";
	else if (c == Condiments::Ketchup)
		return "Ketchup";
	else if (c == Condiments::Yellow_Mustard)
		return "Yellow_Mustard";
	else if (c == Condiments::Green_Relish)
		return "Green_Relish";
	else if (c == Condiments::Chopped_Onions)
		return "Chopped_Onions";
	else if (c == Condiments::Tomato_Wedge)
		return "Tomato_Wedge";
	else if (c == Condiments::Pickle_Spear)
		return "Pickle_Spear";
	else if (c == Condiments::Sport_Peppers)
		return "Sport_Peppers";
	else if (c == Condiments::Celery_Salt)
		return "Celery_Salt";
	else
		return "null";

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






