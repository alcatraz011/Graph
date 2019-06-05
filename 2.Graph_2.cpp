// Graph implementation(Non-Weighted)  -- Extended (Contains separate struct array to store list of vertices)

#include<stdio.h>
#include<iostream>

using namespace std;

void addvertex(int,int);
void printgraph(int);

struct vertex
{
  int data;
  struct vertex* next;
};

struct vertex adjlist[10];


int main()
{
  int v=6;
  
  for (int i=0;i<v;i++)
   {
     adjlist[i].data=0;
	 adjlist[i].next=NULL;
   }
   
{ 
  addvertex(1,2);
  addvertex(1,4);
  
  addvertex(2,3);
  addvertex(2,4);
  
  addvertex(3,5);
  addvertex(3,6);
  
  addvertex(4,5);
  
  addvertex(5,3);
  addvertex(5,6);  

}
   
 
  printgraph(v);
	
  return 0;
}

void addvertex(int s, int d)
{
  struct vertex *temp, *n;
  
  int i=0,j=0,flag=0;
  while(adjlist[i].data!=0 && adjlist[i].data!=s)
   i++;
   
  if(adjlist[i].next==NULL)  
  { 
    adjlist[i].data=s;
  	n=(struct vertex*)malloc(sizeof(struct vertex));
  	n->data=d;
  	n->next=NULL;
  	adjlist[i].next=n;
  }
  else if(adjlist[i].data==s)
  {
  	temp=adjlist[i].next;
  	
  	n=(struct vertex*)malloc(sizeof(struct vertex));
  	n->data=d;
  	n->next=NULL;
  	
  	if(adjlist[i].next==NULL)
  	 adjlist[i].next=n;
  	else
  	{
  	 while(temp->next!=NULL)
  	  temp=temp->next;
  	  
  	 temp->next=n;
//  	 cout<<" "<<temp->data<<" "; 
     } 
   }

    
  while(adjlist[j].data!=0)
  {
  	if(adjlist[j].data==d)
  	{
  	  flag=1;
  	  break;
	}
	j++;
  }
  
  if(flag==0)
  	adjlist[j].data=d; 
  
}

void printgraph(int v)
{
 struct vertex* temp;
 
 for (int i=0;i<v;i++)
   {
   	  cout<<adjlist[i].data<<"-";
   	  temp=adjlist[i].next;
	  while(temp!=NULL)
	   {
	   	cout<<"->"<< temp->data;
	   	temp=temp->next;
	   }	
   	cout<<endl;
   }
 
}




