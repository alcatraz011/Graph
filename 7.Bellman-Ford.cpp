// Shortest path - Bellman-Ford algorithm

#include<stdio.h>
#include<iostream>

using namespace std;

void addvertex(int,int,int);
void printgraph(int);
void bellmanford(int,int);
void updatedistance(int,int,int);
void showpath(int);



struct vertex
{
  int data;
  int weight;
  struct vertex* next;
};

struct visited
{
  int vertex;
  int flag;	
};

struct distance
{
   int vertex;
   int dist;
   int previous;
};

struct vertex adjlist[10];
struct distance distancelist[10];
int changeflag=1;

int main()
{
  int v=6;
  
  for (int i=0;i<v;i++)
   {
     adjlist[i].data=9999;
     adjlist[i].weight=0;
	 adjlist[i].next=NULL;
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
  addvertex(5,6,0);   */

}

{/*
	addvertex(1,2,1);
	addvertex(1,3,2);
	addvertex(3,4,3);  */
}

{ /*
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
	addvertex(4,5,10); */ 
	
}  
  
{ 
  addvertex(1,2,4);
  addvertex(1,3,2);
  
  addvertex(2,1,4);
  addvertex(2,3,1);
  addvertex(2,5,3);
  
  addvertex(3,1,2);
  addvertex(3,4,1);
  addvertex(3,2,1);
  addvertex(3,5,5);
  
  addvertex(4,3,1);
  addvertex(4,5,4);
  addvertex(4,6,3);
  
  addvertex(5,2,3);
  addvertex(5,3,5);
  addvertex(5,4,4);
  addvertex(5,6,6);
  
  addvertex(6,4,3);
  addvertex(6,5,6);  
}
    
  
    for(int i=0;i<v;i++)
  {
 	distancelist[i].vertex=adjlist[i].data;
  	distancelist[i].dist=9999;
  	distancelist[i].previous=-1;
  }
    
   printgraph(v);
  
  
  int i=0,startvertex=1;
  while(distancelist[i].vertex!=startvertex)
   i++;
  distancelist[i].dist=0;

  
  cout<<"\nCalling BellmanFord\n\n";
  bellmanford(startvertex,v);               // Calling Bellmanford

   
   cout<<"\n\nDistance matrix:-\n";
     for(int i=0;i<v;i++)
  {
   cout<<distancelist[i].vertex<<" ";
   cout<<distancelist[i].dist<<" ";
   cout<<distancelist[i].previous<<endl;
   } 
  
  cout<<endl;
  for(int i=0;i<v;i++)
  {
  	  cout<<"Shortest path to "<<distancelist[i].vertex;
	  showpath(distancelist[i].vertex);
	  cout<<endl;
  }
	
  return 0;
}

void addvertex(int s, int d, int w)
{
  struct vertex *temp, *n;
  
  int i=0,j=0,flag=0;;
  while(adjlist[i].data!=9999 && adjlist[i].data!=s)
   i++;

   
  if(adjlist[i].next==NULL)  
  { 
    adjlist[i].data=s;
  	n=(struct vertex*)malloc(sizeof(struct vertex));
  	n->data=d;
  	n->weight=w;
  	n->next=NULL;
  	adjlist[i].next=n;
 // 	cout<<"1\n";
  }
  else if(adjlist[i].data==s)
  {
  	temp=adjlist[i].next;
  	
  	n=(struct vertex*)malloc(sizeof(struct vertex));
  	n->data=d;
  	n->weight=w;
  	n->next=NULL;
  	
  	while(temp->next!=NULL)
  	 temp=temp->next;
  	 
  	temp->next=n;
 // 	cout<<"2\n";
  } 
  
    while(adjlist[j].data!=9999)
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
//  cout<<adjlist[j].data<<endl;
//  printgraph(4);
}

void bellmanford(int vertex, int v)
{
 struct vertex* temp;

for (int times=1;times<v;times++) 
{
  if(changeflag==0)           //If no changes in the minimum distance then break loop
    break;  
  changeflag=0;
  for (int i=0;i<v;i++)
   { 
   	  temp=adjlist[i].next;
	  while(temp!=NULL)
	   {
        updatedistance(adjlist[i].data,temp->data,temp->weight);
	   	temp=temp->next;
	   }
   } 
   cout<<times<<endl;

}
  
}

void updatedistance(int cvertex, int nvertex, int weight)
{
  int i=0,j=0;
  while(distancelist[i].vertex!=cvertex)
   i++;
  while(distancelist[j].vertex!=nvertex)
   j++; 
   
   if(distancelist[j].dist>distancelist[i].dist+weight)
    {
	  distancelist[j].dist=distancelist[i].dist+weight;
	  distancelist[j].previous=cvertex;
	  changeflag=1;
    }
  
}



void showpath(int vertex)
{
  int i=0;
  while(distancelist[i].vertex!=vertex)
    i++;

  if(distancelist[i].previous!=-1)
  {
	cout<<"<-"<<distancelist[i].previous;
	showpath(distancelist[i].previous);
  }
  
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
	   	cout<<"("<<temp->weight<<")";
	   	temp=temp->next;
	   }	
   	cout<<endl;
   }
 
}


