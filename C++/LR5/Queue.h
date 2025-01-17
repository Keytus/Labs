//---------------------------------------------------------------------------

#ifndef QueueH
#define QueueH
#include "Unit1.h"
#include "Part.h"
class Queue
{
	part *Head,*Tail;
	public:

	Queue():Head(0),Tail(0){}
	void Add(int value)
	{
		part* temp=new part;
		temp->value=value;
		temp->next=0;
		if(Head==0)
		{
			temp->prev=0;
			Head=Tail=temp;
		}
		else
		{
			temp->prev=Tail;
			Tail->next=temp;
			Tail=temp;
		}
	}
	void Print(TListBox *ListBox1)
	{
		part* temp=new part;
		temp=Head;
		while(temp!=0)
		{
			ListBox1->Items->Add(temp->value);
			temp=temp->next;
		}
	}
	void RemoveHead()
	{
		if(Head!=0)
		{
			part* temp=new part;
			temp=Head->next;
			delete Head;
			Head=temp;
		}
	}
	void RemoveQueue()
	{
		while(Head!=0)
		{
			RemoveHead();
		}
    }
	void Empty(TListBox *ListBox1)
	{
		if(Head==0)
		{
			ListBox1->Items->Add("������� �����.");
		}
		else
		{
			ListBox1->Items->Add("������� �� �����.");
		}
	}
};
//---------------------------------------------------------------------------
#endif
