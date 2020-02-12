#include<iostream>
#include<cstring>
#include<cstring>
using namespace std;

string Cities[]={"Nashik","Mumbai","Pune","Delhi","Banglore","Chennai"};
class Node{
	int vertex;
	string city;
	float distance;
	Node* next;
	Node(){next = NULL;}
	friend class Graph;
};

class Graph{
	Node* head[10];
	int noOfVertices;
	
	public:
		Graph(int n)
		{
			noOfVertices = n;
			for(int i=0;i<noOfVertices;i++)
			{
				head[i]=new Node;
				head[i]->vertex=i;
				head[i]->distance=0;
				head[i]->city=Cities[i];
			}
		}
		void read()
		{
			Node *current,*temp; 
			int x;
		    for(int i=0;i<noOfVertices;i++)
		    {
		        cout << "\n How many cities connected to "<< head[i]->city<<" : ";
		        cin >> x;  
		        temp=head[i];
		        for (int j=0;j<x;j++)
		        {
		          current=new Node;
		          cout << "\n Enter vertex : ";
		          cin >> current->vertex;
		          cout<<"\nEnter the distance of "<<Cities[current->vertex]<<" from "<<head[i];
		          current->city=Cities[current->vertex];
		          cin >> current->distance;
		          current->next=NULL;
		          temp->next=current;
		          temp=current;
		        }
		    }	
		}

		void display()
		{
		   Node * current;
		   for(int i=0;i<noOfVertices;i++)
		    {
		        current=head[i];
		        while(current != NULL)
		        {
		            cout  << current->vertex<< " " << current->city<< " " << current->distance ;
		            if(current->next)
		            	cout<< "--->";
		            else
		            	cout<<"---_";
		            current=current->next;
		        }
		        cout<<endl;
		    }
		}
};

int main()
{
	int n;
	cout<<"You want Graph of How many Vertices ?"<<endl;
	cin>>n;
	Graph g(n);
	g.read();
	g.display();
	return 0;
}
