// Breadth First Search(DFS)  -- Extended

#include<stdio.h>
#include<iostream>
#include<list>

using namespace std;

void addvertex(int,int);
void printgraph(int);
void bfs(int);
int returnindex(int);
void printqueue();

struct vertex
{
  int data;
  struct vertex* next;
};

struct visited
{
  int vertex;
  int flag;	
};

struct vertex adjlist[10];
struct visited visitlist[10];

list<int> queue;

int main()
{
  int v=6;
  
  for (int i=0;i<v;i++)
   {
     adjlist[i].data=0;
	 adjlist[i].next=NULL;
   }  

  addvertex(1,2);
  addvertex(1,3);
  
  addvertex(2,1);
  addvertex(2,4);
  
  addvertex(3,1);
  addvertex(3,4);
  addvertex(3,6);
  
  addvertex(4,2);
  addvertex(4,3);
  addvertex(4,5);
  
  addvertex(5,4);
  
  addvertex(6,3); 
  
  
    
  printgraph(v);
  cout<<endl;
  
  for(int i=0;i<v;i++)
  {
 	visitlist[i].vertex=adjlist[i].data;
  	visitlist[i].flag=0;
  }
  
/*  for(int i=0;i<v;i++)
  {
   cout<<visitlist[i].vertex<<" ";
   cout<<visitlist[i].flag<<endl;
   } */
  
  cout<<endl;
  bfs(2);
  
  	
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

void bfs(int vertex)
{
   int i= returnindex(vertex);
   
   visitlist[i].flag=1;
   queue.push_back(vertex); printqueue();
   
   while(!queue.empty())
   {
   	vertex=queue.front();
   	queue.pop_front();
   	cout<<vertex<<" ";
   	i= returnindex(vertex);
   	
   struct vertex* temp;  
   temp=adjlist[i].next;
   
   while(temp!=NULL)
   {
   	i=returnindex(temp->data);
   	int flag=visitlist[i].flag;
   	if(flag==0)
   	 {
   	 	queue.push_back(temp->data);
   	 	visitlist[i].flag=1;
	 }
	 temp=temp->next;
   }
   	
   }
   
}

void printqueue()
{
	cout<<endl;
	for(auto elem:queue)
	cout<<elem<<" "; 
	
}

int returnindex(int vertex)
{
	int i=0;
	while(adjlist[i].next!=NULL && adjlist[i].data!=vertex)
      i++;
     
    return(i);
}

