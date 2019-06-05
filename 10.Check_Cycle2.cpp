//Check cycle in a graph

#include<iostream>
#include<set>

using namespace std;

void addvertex(int,int);
void printgraph(int);
void checkcycle(int);


struct vertex
{
  int data;
  struct vertex* next;
};

struct vertex adjlist[10];
set<int> nonvisited;
set<int> visiting;
set<int> visited;

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
  addvertex(2,3); 
  addvertex(3,1);
  addvertex(4,2); 
  addvertex(4,5);
  addvertex(5,6);
  addvertex(6,4);
}
    
  printgraph(v);
  cout<<endl;
  
    for(int i=0;i<v;i++)
     nonvisited.insert(adjlist[i].data);

  set<int>::iterator it;
  
  for(it=nonvisited.begin();it!=nonvisited.end();++it)
   //cout<<*it<<" ";
   
  cout<<endl;
  
  int startvertex=4;  
  checkcycle(startvertex);

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

void checkcycle(int vertex)
{
	cout<<"checkcycle "<<vertex<<endl;
  	int i=0,inNonvisted,inVisiting=1, inVisited=1;
  	while(adjlist[i].data!=vertex)
  	 i++;
    
// Moviing vertex from nonvisited to visting    
  	set<int>::iterator it;
  	it=nonvisited.find(vertex);
	nonvisited.erase(it);
	visiting.insert(vertex);
	
  	struct vertex* temp;
  	temp=adjlist[i].next;
  	
  	while(temp!=NULL)
  	{
 // 		cout<<"hello\n";
        inNonvisted=inVisiting=inVisited=1;
        
  	   	it=visited.find(temp->data);   //Check status of vertex in visited;
  	   	cout<<vertex<<" "<<temp->data<<endl;
  	   	if(it==visited.end())
  	   	 {
			  inVisited=0;
		}
  	   	 
  	   	it=visiting.find(temp->data);  //Check status of vertex in visting
  	   	if(it==visiting.end())
  	   	 inVisiting=0;
  	   	 
  	   	if(inVisiting==1)
  	   	 {
  	   	   cout<<"Cycle found.....\n";
		   return;	
		 }
		if(inVisited==0)
		 checkcycle(temp->data);
  	 
	   temp=temp->next;	
	} 
	
  	// Moving vertex from visiting to visited
  	it=visiting.find(vertex);
	visiting.erase(it);
	visited.insert(vertex);
	
	for(it=nonvisited.begin();it!=nonvisited.end();++it)
        cout<<*it<<" ";
        cout<<endl;
    for(it=visiting.begin();it!=visiting.end();++it)
        cout<<*it<<" ";
        cout<<endl;
	for(it=visited.begin();it!=visited.end();++it)
        cout<<*it<<" ";
        cout<<endl<<endl;
	
// If the all the current visting vertices are vistited then we select another from nonvisited	
    if(visiting.empty() && !nonvisited.empty())
    {
    //	cout<<"Hello 3\n";
    	it=nonvisited.begin();
    	checkcycle(*it);
	}
  	
  	
}





