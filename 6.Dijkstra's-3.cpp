// Shortest path - Dijkstra's algorithm (Udirected) (Input set 2)

#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;

void addvertex(int,int,int);
void printgraph(int);
void dijkstra(int);
void updatedistance(int,int,int);
int checkvisited(int);
void deleteMap();
void updateMap(int,int);
void showMap();
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
struct visited visitlist[10];
struct distance distancelist[10];
multimap<int,int> nodemap;


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
	addvertex(4,5,10);  */
	
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
 	visitlist[i].vertex=adjlist[i].data;
  	visitlist[i].flag=0;
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
  
  nodemap.insert({0,startvertex});
  for(int i=0;i<v;i++)
  {
 	int vertex = adjlist[i].data;
 	if(vertex!=startvertex)
 	 nodemap.insert({9999,vertex});
  }
  
//  showMap();
  
  cout<<"\nPath traversed:- ";
  dijkstra(startvertex);
  
  
/*  cout<<endl;
    for(int i=0;i<v;i++)
  {
   cout<<visitlist[i].vertex<<" ";
   cout<<visitlist[i].flag<<endl;
   } */
   
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

void dijkstra(int vertex)
{
   int i=0; 
   while(adjlist[i].data!=9999 && adjlist[i].data!=vertex)
     i++;
   visitlist[i].flag=1;
   cout<<"\nElement to check "<<vertex<<endl;

   deleteMap();   //Remove the first element from the queue
//   cout<<"hello";
   
   struct vertex* temp;  
   temp=adjlist[i].next;
   while(temp!=NULL)
   {

   	int flag=checkvisited(temp->data);
   	if(flag==0)
   	{
   	  updatedistance(vertex,temp->data,temp->weight);	
//    updatedistance(vertex,temp->data,temp->weight);
	}
	temp=temp->next;
   }
   
//   showMap();
   
   if(!nodemap.empty())
    {
      multimap<int,int>::iterator it;
	  it=nodemap.begin();
	  dijkstra(it->second);	
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
	  updateMap(nvertex,distancelist[i].dist+weight);
    }
  
}

void deleteMap()
{
  	multimap<int,int>::iterator it;
	
	it=nodemap.begin();
//	cout<<"Item to delete "<<it->first<<" "<<it->second<<" \n\n";		
	nodemap.erase(it);	
}

void updateMap(int vertex,int weight)
{
	multimap<int,int>::iterator it,itcopy;
//	cout<<"\n"<<weight<<" "<<vertex<<" \n";
	for(it=nodemap.begin();it!=nodemap.end();++it)
	{
		if(it->second==vertex)
		{
	//	  itcopy=it;
	//	  cout<<it->second<<"\n";
		  nodemap.erase(it);
		  nodemap.insert({weight,vertex});
	//	  showMap();
		  break;
		}
	}
//showMap();
	
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

int checkvisited(int vertex)
{
	int i=0;
	
	while(adjlist[i].data!=9999 && adjlist[i].data!=vertex)
     i++;
     
     return(visitlist[i].flag);
//     cout<<endl<<visitlist[i].flag;
	
}

void showMap()
{
	cout<<endl;
	  for(auto elem:nodemap)
	{
		cout<<elem.first<<" ";
		cout<<elem.second<<endl;
	}
}


