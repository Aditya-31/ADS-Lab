/*
	Name: Aditya Gade		Date:2/1/2020		Class: SE-A
								A TEMPLATE MY STACK HEADER FILE
*/
#include<iostream>
using namespace std;
template<typename T>
class MyStack{
		T *s;
		int top,capacity;
    public:
   		MyStack (){	//Default Constructor
			cout<<"\nEnter Maximum Capacity of stack : ";
			cin>>capacity;
			s= new T[capacity];
		    top=-1;
		}

		MyStack (int size){	//Paramerterized Constructor
			capacity=size;
			s= new T[capacity];
		    top=-1;
		}

		int	isFull(){
			return top==capacity-1;
		}
		int	isEmpty(){
			return top==-1;
		}

		void push(T ch){
			if(!isFull())
				s[++top]=ch;
			else
				cout<<"Stack Overflow\n";
		}

		T getTop(){
			if(!isEmpty())
				return s[top];
			else
				cout<<"Stack is Empty\n"<<endl;
		}
		
		T pop(){
			if(!isEmpty())
				return s[top--];
			else
				cout<<"Stack is Empty\n"<<endl;
		}
		
		~ MyStack(){	//DESTRUCTOR
			cout<<"\nALL YOUR DATA IS SUCCESFULLY EMPTIED!!!\n";
		}	
};

