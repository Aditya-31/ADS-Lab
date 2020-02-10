#include<iostream>
#include<cstring>
using namespace std;

class Node{
	int vertex;
	char city[20];
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
			
		}
};
