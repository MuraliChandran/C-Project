#include "Stand.h"
#include "Order.h"

SNode* header = nullptr;
bool once = false;

Stand::Stand()
{
	printf("\n\n");
	printf("-------------------------------------------------\n\n");
	Intitiate();
}

void Stand::Add(Order order)
{

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
		SNode* n1 = new SNode();

		header->next = n1;
		n1->prev = header;
		n1->next = nullptr;

		n1->order = order;

		header = header->next;

	}

}

void Stand::Print()
{
	SNode* t = n;

	FindNumOrders();

	printf("Stand: currNumOrders:%d  peakNumOrders:%d\n\n", currentOrder, peakOrder);

	while (t != nullptr)
	{
		printf("Order: %s\n", ReturnEnumName(t->order.IN));

		ONode* c = t->order.n;

		while (c != nullptr)
		{

			Node* l = c->hotdog.n;

			printf("\tHotDog:%d\n", ++count);

			/*Hot Dog*/
			while (l != nullptr)
			{
				printf("\t\t\t%s\n", ReturnEnumValue(l->CondV));
				l = l->next;
			}

			c = c->next;
		}

		count = 0;
		t = t->next;

	}


}

void Stand::Remove(Name name)
{
	printf("-------------------------------------------------\n\n");
	
	SNode* del = n;
	
	while (del != nullptr)
	{
		if (del->order.IN == name)
		{

			printf("Remove->Order(%s)\n\n",ReturnEnumName(name));

			if (del->next == nullptr)
			{
				if (del->next == nullptr && del->prev == nullptr)
				{
					del->next = nullptr;
					del->prev = nullptr;
					
					del = nullptr;

					n = del;

				}
				else
				{
					del->prev->next = nullptr;
					del->prev = nullptr;


					del = nullptr;
				}
			}
			//First Node;
			else if (del->prev == nullptr)
			{
				del = del->next;
				del->prev = nullptr;

				n = del;
			}
			else
			{
				del->prev->next = del->next;
				del->next->prev = del->prev;

				del = nullptr;
				
			}
			break;
		}
		del = del->next;
	}
	printf("-------------------------------------------------\n\n");
}

char* Stand::ReturnEnumName(Name name)
{
	if (name == Name::Jaime)
		return "Jamie";
	else if (name == Name::Cersei)
		return "Cersei";
	else if (name == Name::Arya)
		return "Arya";
	else if (name == Name::Sansa)
		return "Sansa";
	else
		return "null";
}

void Stand::FindNumOrders()
{
	currentOrder = 0;
	SNode* t = n;

	while (t != nullptr)
	{
		++currentOrder;
		t = t->next;
	}

	if (peakOrder == 0) 
	{
		peakOrder = currentOrder;
	}
	else 
	{
		if (peakOrder < currentOrder)
		{
			peakOrder = currentOrder;
		}
	}
	
}

void Stand::Intitiate()
{
	if (once == false)
	{
		printf("HotDogStand: currNumOrders:%d  peakNumOrders:%d\n\n", currentOrder, peakOrder);
		once = true;
	}
	
}


char* Stand::ReturnEnumValue(Condiments c)
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

