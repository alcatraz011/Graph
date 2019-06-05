// Prims Algorithm - Undirected graph (Adjacency list)
// https://www.geeksforgeeks.org/prims-mst-for-adjacency-list-representation-greedy-algo-6/

#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;

void addvertex(int,int,int);
void printgraph(int);
void prims(int);
void deleteMap();
void updateMap(int,int,int);
void updateMST(int,int);
void showMST(int);
void showMap();
int IsExistInMap(int);

struct vertex
{
  int data;
  int weight;
  struct vertex* next;
};

struct MST
{
  int vertex;
  int parent;
};


struct vertex adjlist[10];
struct MST MSTlist[10];
multimap<int,int> nodemap;

int main()
{
   int v=9;
  
  for (int i=0;i<v;i++)
   {
     adjlist[i].data=9999;
     adjlist[i].weight=0;
	 adjlist[i].next=NULL;
   }
   
{  /* 
    addvertex(1,2,4);
    addvertex(1,4,2);
    
    addvertex(2,1,4);
    addvertex(2,3,3);
    addvertex(2,6,1);
    
    addvertex(3,2,3);
    addvertex(3,4,5);
    addvertex(3,6,0);
    
    addvertex(4,1,2);
    addvertex(4,3,5);
    addvertex(4,5,6);
    
    addvertex(5,4,6);
    
    addvertex(6,2,1);
    addvertex(6,3,0); */
    
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
  
  int startvertex=5;  
  nodemap.insert({0,startvertex});
  for(int i=0;i<v;i++)
  {
 	int vertex = adjlist[i].data;
 	if(vertex!=startvertex)
 	{
 	 nodemap.insert({9999,vertex});
 	 MSTlist[i].vertex=vertex;
    }
  }
 
 showMap();	
 //showMST(v);
 prims(startvertex);
 showMST(v);
	
 return 0;
}


void prims(int vertex)            ///////////////////////////////////////////
{
     int i=0; 
   while(adjlist[i].data!=9999 && adjlist[i].data!=vertex)
     i++;

   cout<<"\nElement to check "<<vertex<<endl;
   
  deleteMap();
  
  struct vertex* temp;  
  temp=adjlist[i].next;
  
  while(temp!=NULL)
  {
  	if((IsExistInMap(temp->data))==1)
  	{
  	 updateMap(vertex,temp->data,temp->weight);
    }
    temp=temp->next;
  }
//  showMap();
  
  // Get the first element in map and call the function again
     if(!nodemap.empty())
    {
      multimap<int,int>::iterator it;
	  it=nodemap.begin();
	  prims(it->second);	
	} 
	
}


void deleteMap()
{
  	multimap<int,int>::iterator it;
	
	it=nodemap.begin();
//	cout<<"Item to delete "<<it->first<<" "<<it->second<<" \n\n";		
	nodemap.erase(it);	
}

void updateMap(int svertex,int cvertex,int weight)
{
	multimap<int,int>::iterator it;
    //cout<<"\n"<<weight<<" "<<vertex<<" \n";
	for(it=nodemap.begin();it!=nodemap.end();++it)
	{
		//Search the vertex and update its value if current value is more than the new weight
		if(it->second==cvertex && it->first>weight)
		{

		  nodemap.erase(it);
		  nodemap.insert({weight,cvertex});
		  updateMST(svertex,cvertex);
	      //showMap();
		  break;
		}
		
	}

//showMap();	
}

int IsExistInMap(int vertex)
{
	multimap<int,int>::iterator it;
	int flag=0;
	for(it=nodemap.begin();it!=nodemap.end();++it)
	{
		if(it->second==vertex)
		{
          flag=1;
		  break;
		}
	}
	return(flag);
	
}

void updateMST(int svertex, int cvertex)
{
	int i=0;
	while(MSTlist[i].vertex!=cvertex)
	 i++;
	MSTlist[i].parent=svertex; 
}

void showMST(int v)
{
  for(int i=0;i<v;i++)
  {
  	if(MSTlist[i].vertex!=MSTlist[i].parent)
	  cout<<MSTlist[i].vertex<<" "<<MSTlist[i].parent<<endl;
  }
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


void showMap()
{
	cout<<endl;
	  for(auto elem:nodemap)
	{
		cout<<elem.first<<" ";
		cout<<elem.second<<endl;
	}
}











