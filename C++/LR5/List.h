//---------------------------------------------------------------------------

#ifndef ListH
#define ListH
#include "Queue.h"
class List:public Queue
{
	 public:
	 part *Head;
	 List():Queue(),Head(0){}
	 void Add(int value)
	 {
		part* temp=new part;
		temp->value=value;
		temp->next=0;
		if(Head==0)
		{
			temp->prev=0;
			Head=temp;
		}
		else
		{
			part* current=new part;
			current=Head;
			while(current->next!=0)
			{
				 current=current->next;
			}
			temp->prev=current;
			current->next=temp;
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
};
//---------------------------------------------------------------------------
#endif
