#include<iostream>
#include <cstring>
using namespace std;
class Node{
    public:
    int v;
	string city;
	float dist;  
	Node* next;
};
class Graph{
	Node *head[10];
	string city1[10];
	int n;
	public:
		Graph()
		{
		    city1[0]="Nasik"; city1[1]="mumbai"; city1[2]="Pune";
		    for(int i=0;i<3;i++)
		    {
		         head[i]=new Node; head[i]->v=i;head[i]->dist=0;
		         head[i]->city=city1[i];
		         head[i]->next=NULL; 
     	    }
		}
		void read()
		{
		    Node *curr,*temp; int x;
		    for(int i=0;i<3;i++)
		    {
		        cout << "\n How many cities connected to "<< city1[i];
		        cin >> x;  temp=head[i];
		        for (int j=0;j<x;j++)
		        {
		          curr=new Node;
		          cout << "\n Enter vertex and dist ";
		          cin >> curr->v;
		          curr->city=city1[curr->v];
		          cin >> curr->dist;
		          curr->next=NULL;
		          temp->next=curr;
		          temp=curr;
		        }
		    }
		}
		void display()
		{
		   Node * curr;
		   for(int i=0;i<3;i++)
		    {
		        curr=head[i];
		        while(curr != NULL)
		        {
		            cout  << curr->v<< " " << curr->city<< " " << curr->dist ;
		            if(curr->next)
		            	cout<< "--->";
		            else
		            	cout<<"---_";
		            curr=curr->next;
		        }
		        cout<<endl;
		    }
		}
};
int main(){

      Graph g;
      g.read();
      g.display();

	return 0;
}
