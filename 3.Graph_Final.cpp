// Directed/Weighted Graph implementation  (Final)

#include<stdio.h>
#include<iostream>

using namespace std;

void addvertex(int,int,int);
void printgraph(int);

struct vertex
{
  int data;
  int weight;
  struct vertex* next;
};

struct vertex adjlist[10];

int main()
{
  int v=9;
  
  for (int i=0;i<v;i++)
   {
     adjlist[i].data=9999;
     adjlist[i].weight=0;
	 adjlist[i].next=NULL;
   }

{/*
   addvertex(1,2,1);
   addvertex(1,3,2);
   addvertex(3,4,3); */
}
    
{ /*
  addvertex(1,2,2);
  addvertex(1,4,2);
  
  addvertex(2,3,3);
  addvertex(2,4,4);
  
  addvertex(3,5,5);
  addvertex(3,6,4);
  
  addvertex(4,5,1);
  
  addvertex(5,3,5);
  addvertex(5,6,0);  */

}

{ 
	addvertex(0,1,4);
	addvertex(0,7,8);
	
	addvertex(7,0,8);
	addvertex(7,1,11);
	addvertex(7,6,1);
	addvertex(7,8,7);

	addvertex(1,0,4);
	addvertex(1,2,8);
	addvertex(1,7,11);
	
	addvertex(6,5,2);
	addvertex(6,7,1);
	addvertex(6,8,6);
	
	addvertex(8,2,2);
	addvertex(8,6,6);
	addvertex(8,7,7);
	
	addvertex(2,1,8);
	addvertex(2,3,7);
	addvertex(2,5,4);
	addvertex(2,8,2);
	
	addvertex(5,2,4);
	addvertex(5,3,14);
	addvertex(5,4,10);
	addvertex(5,6,2);
	
	addvertex(3,2,7);
	addvertex(3,4,9);
	addvertex(3,5,14);
	
	addvertex(4,3,9);
	addvertex(4,5,10); 
	
} 

  printgraph(v);
	
  return 0;
}

void addvertex(int s, int d, int w)
{
  struct vertex *temp, *n;
  
  int i=0,j=0,flag=0;
  while(adjlist[i].data!=9999 && adjlist[i].data!=s)  //To reach to the correct position in the adjlist
   i++;
   
  if(adjlist[i].next==NULL)  //Source being added first time
  { 
//    cout<<"\nfirst";
    adjlist[i].data=s;
  	n=(struct vertex*)malloc(sizeof(struct vertex));
  	n->data=d;
  	n->weight=w;
  	n->next=NULL;
  	adjlist[i].next=n;
//    printgraph(6);
  }
  else if(adjlist[i].data==s)  //Source already added
  { 
//    cout<<"\nsecond ";
  	temp=adjlist[i].next;
  	
  	n=(struct vertex*)malloc(sizeof(struct vertex));
  	n->data=d;
  	n->weight=w;
  	n->next=NULL;
  	
  	 while(temp->next!=NULL)
  	  temp=temp->next;
  	  
  	 temp->next=n;
//  	printgraph(6);
  }
  
  while(adjlist[j].data!=9999)  //To check if destination is in adjlist 
  {
  	if(adjlist[j].data==d)
  	{
  	  flag=1;
  	  break;
	}
	j++;
  }
  
  if(flag==0)                    //To add destination in adjlist
  	adjlist[j].data=d; 
//  cout<<adjlist[j].data<<endl;
//  cout<<"\nThird";
//  printgraph(6);

}

void printgraph(int v)
{
 struct vertex* temp;
 cout<<endl;
 for (int i=0;i<v;i++)
   {
   	  cout<<adjlist[i].data<<"-";
   	  temp=adjlist[i].next;
	  while(temp!=NULL)
	   {
	   	cout<<"->"<< temp->data;
	   	cout<<"("<<temp->weight<<")";
	   	temp=temp->next;
	   }	
   	cout<<endl;
   }
 
}




