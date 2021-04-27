#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node *link;
}*start=NULL,*tail=NULL;

void insert_at_beg(int n)
{
	Node *new_node=new Node;
	new_node->data=n;
	if(start==NULL)
	{
		start=new_node;
		new_node->link=start;
		tail=new_node;
	}
	else
	{
		new_node->link=start;
		start=new_node;
		tail->link=start;
	}
}
void insert_at_end(int n)
{
	Node *new_node=new Node;
	new_node->data=n;
	if(start==NULL)
	{
		start=new_node;
		new_node->link=start;
		tail=new_node;
	}
	else
	{
		tail->link=new_node;
		tail=new_node;
		new_node->link=start;
	}
	
}
void insert_after_loc(int n)
{
	Node *new_node=new Node;
	new_node->data=n;
	if(start==NULL)
	{
		insert_at_beg(n);
		return;
	}
	
	Node *ptr=start;
	int loc;

	cout<<"\n enter the location after which you want to insert :";
	cin>>loc;
	if(loc<0)
	cout<<"\n invalid position";
	else if(loc==0)
	insert_at_beg(n);
	else
	{
		int i=1;
		while(i<loc)
		{
			ptr=ptr->link;
			i++;
		}
		if(ptr==tail)
		insert_at_end(n);
		else
		{
			new_node->link=ptr->link;
	    	ptr->link=new_node;
		}
		
	}
}
void deletion_at_beg()
{
	Node *ptr=start;
	if(start==NULL)
	cout<<"\n Nothing to delete ";
	
	else if(start==tail)
	{
		tail=start=NULL;
		cout<<"deleted item is "<<ptr->data;
		delete ptr;
	}
	else
	{
		start=start->link;
		tail->link=start;
		cout<<"deleted item is "<<ptr->data;
		delete ptr;
	}
}
void deletion_at_end()
{
	Node *ptr=start;
	Node*ptr1;
	if(start==NULL)
	cout<<"\n Nothing to delete ";
	
	else if(start==tail)
	{
		tail=start=NULL;
		cout<<"deleted item is "<<ptr->data;
		delete ptr;
	}
	else
	{
		while(ptr->link!=start)
		{
			ptr1=ptr;
			ptr=ptr->link;
		}
		ptr1->link=start;
		tail=ptr1;
		cout<<"deleted item is "<<ptr->data;
		delete ptr;
	}
}
void deletion_after_loc()
{
	Node *ptr=start;
	Node*nodeptr;
	int loc;
	if(start==NULL)
	{
		cout<<"\n Nothing to delete ";
		return;
	}
	
	cout<<"\n enter location after which you want delete";
	cin>>loc;
	if(loc<0)
	cout<<"\n invalid position ";
	else if(loc==0)
	deletion_at_beg();
	else
	{
		int i=0;
		while(i<loc)
		{
			nodeptr=ptr;
			ptr=ptr->link;
			i++;
		}
		if(ptr==tail)
		{
			nodeptr->link=start;
			tail=nodeptr;
		    cout<<"deleted item is "<<ptr->data;
		    delete ptr;
		}
		else
		{
			nodeptr->link=ptr->link;
		    cout<<"deleted item is "<<ptr->data;
		    delete ptr;
		}
	}
}
void display()
{
	if(start==NULL)
	{
		cout<<"\n Nothing to delete ";
	}
	else 
	{
		Node*ptr=start;
		while(ptr->link!=start)
		{
			cout<<ptr->data<<" ";
			ptr=ptr->link;
		}
		cout<<ptr->data<<" ";
	}
}
void search()
{
	int a,i=0;
	bool found=false;
	if(start==NULL)
	{
		cout<<"\n Nothing to search...list is empty ";
	}
	else
	{
		Node*ptr=start;
		cout<<"\n enter the element to be search";
		cin>>a;
		while(ptr!=NULL)
		{
			if(ptr->data!=a)
			{
				i++;
				ptr=ptr->link;	
			}
			else if(ptr->data==a)
			{
				cout<<"\n found at "<<i+1<<"position";
				found=true;
				break;
			}	
		}
		if(found==false)
		{
			cout<<"\n not found";
		}	
	}
}
int main()
{
	int n;
	char ch;
	while(true)
	{
		cout<<"\n OPTIONS \n 1. insert at begining \n 2. insert at end \n 3. insert after specific location ";
		cout<<"\n 4. deletion at begining \n 5. deletion at end \n 6. deletion after specific location ";
		cout<<"\n 7. search \n 8. display \n Enter your choice :";
		cin>>ch;
		switch(ch)
		{
			case '1': cout<<"\n enter element to insert :";
			  cin>>n;
			 insert_at_beg(n);
			 break;
			 case '2': cout<<"\n enter element to insert :";
			  cin>>n;
			 insert_at_end(n);
			 break;
			 case '3': cout<<"\n enter element to insert :";
			  cin>>n;
			 insert_after_loc(n);
			 break;
			 case '4': deletion_at_beg();
			 break;
			 case '5': deletion_at_end();
			 break;
			 case '6': deletion_after_loc();
			 break;
			 case '7': search();
			 break;
			 case '8': display();
			 break;
		}
		
	} 
}

