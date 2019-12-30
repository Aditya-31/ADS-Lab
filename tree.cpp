/*
	Name: Aditya Gade		Date:30/12/2019		Class: SE-A
	A C++ Program for Linked Implementation of Binary Tree 
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{

	Node* right;
	Node* left;
	char data;
	
	friend class BinaryTree;
	
	Node(){
		
		left=right=NULL;
	}
};

class BinaryTree{
		Node* root;
	public:
		BinaryTree(){
			root=NULL;
		}
		
		void create(){
		
			Node* current,*temp;
			char choice;
			do{
			
				temp=new Node;
				cout<<"\nPlease Enter Data for newly created node : ";
				cin>>temp->data;
				temp->right=temp->left=NULL;
				if(!root)
					root=temp;
				else{
					
					current=root;
					do{
						char leftOrRight;
						do{
							cout<<"\nPLEASE ENTER ('l'/'r'/'L'/'R')\n";
							cout<<"\nDo you want to attach "<<temp->data<<" to left or right of "
										<<current->data<<endl;
							cin>>leftOrRight;
						}while(leftOrRight!='r' && leftOrRight!='l' && leftOrRight!='R' && leftOrRight!='L');
						if(leftOrRight=='l'|| leftOrRight=='L'){
						
							if(current->left==NULL){
								
								current->left=temp;
								cout<<"\n"<<temp->data<<" added to the left of "<<current->data;
								break;
							}
							else
								current=current->left;
						}
						else{	//ASSUMED FOR RIGHT AS AN OPTION
						
							if(current->right==NULL){
							
								current->right=temp;
								cout<<"\n"<<temp->data<<" added to the right of "<<current->data;
								break;
							}
							else
								current=current->right;
						}
					}while(1);
				}
				cout<<"\nDo You Want to add more Nodes? (Y/N))";
				cin>>choice;
			}while(choice=='Y'||choice =='y');
		}
		
		void inorderDisplay()
		{
			inorder(root);
		}
		void inorder(Node* temp){
			if(temp!=NULL){
			
				inorder(temp->left);
				cout<<temp->data<<"\t";
				inorder(temp->right);
			}
		}
		
		void preorderDisplay()
		{
			preorder(root);
		}
		void preorder(Node* temp){
			if(temp!=NULL){
			
				cout<<temp->data<<"\t";			
				preorder(temp->left);
				preorder(temp->right);
			}
		}
		
		void postorderDisplay()
		{
			postorder(root);
		}
		void postorder(Node* temp){
			if(temp!=NULL){
			
				postorder(temp->left);
				postorder(temp->right);
				cout<<temp->data<<"\t";
			}
		}
		
};
int main()
{
	BinaryTree B1;
	char switchChoice;
	do{
	
		cout<<"\nMENU:\n";
		cout<<"1.Create and Insert Nodes:"<<endl;
		cout<<"2.Inorder Display"<<endl;
		cout<<"3.Postorder Display"<<endl;
		cout<<"4.Preorder Display"<<endl;
		cout<<"0.Exit"<<endl;
		cout<<"\nEnter your Choice: ";
		cin>>switchChoice;
		switch(switchChoice)
		{
			case '1':
				B1.create();
				break;
			case '2':
				cout<<"Entered Tree Inorder is:\n\n";			
				B1.inorderDisplay();
				break;
			case '3':
				cout<<"Entered Tree Postorder is:\n\n";			
				B1.postorderDisplay();
				break;
			case '4':
				cout<<"Entered Tree Preorder is:\n\n";			
				B1.preorderDisplay();
				break;
			default:
				cout<<"\nPlease Enter a Valid Choice\n";
		}
	}while(switchChoice !=0);
	cout<<"\nExiting the Program";
	return 0;
}
/*OUTPUT:
unix@unix-dx2480-MT:~/SEA18$ g++ tree.cpp
unix@unix-dx2480-MT:~/SEA18$ ./a.out

MENU:
1.Create and Insert Nodes:
2.Inorder Display
3.Postorder Display
4.Preorder Display
0.Exit

Enter your Choice: 1

Please Enter Data for newly created node : A

Do You Want to add more Nodes? (Y/N))y

Please Enter Data for newly created node : D

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach D to left or right of A
l

D added to the left of A
Do You Want to add more Nodes? (Y/N))y

Please Enter Data for newly created node : G

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach G to left or right of A
l

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach G to left or right of D
l

G added to the left of D
Do You Want to add more Nodes? (Y/N))y

Please Enter Data for newly created node : J

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach J to left or right of A
l

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach J to left or right of D
l

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach J to left or right of G
l

J added to the left of G
Do You Want to add more Nodes? (Y/N))y

Please Enter Data for newly created node : H

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach H to left or right of A
l

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach H to left or right of D
r

H added to the right of D
Do You Want to add more Nodes? (Y/N))y

Please Enter Data for newly created node : B

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach B to left or right of A
r

B added to the right of A
Do You Want to add more Nodes? (Y/N))y

Please Enter Data for newly created node : C

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach C to left or right of A
r

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach C to left or right of B
l

C added to the left of B
Do You Want to add more Nodes? (Y/N))y

Please Enter Data for newly created node : I

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach I to left or right of A
r

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach I to left or right of B
l

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach I to left or right of C
l

I added to the left of C
Do You Want to add more Nodes? (Y/N))y

Please Enter Data for newly created node : F

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach F to left or right of A
r

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach F to left or right of B
l

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach F to left or right of C
r

F added to the right of C
Do You Want to add more Nodes? (Y/N))y

Please Enter Data for newly created node : E

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach E to left or right of A
r

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach E to left or right of B
r

E added to the right of B
Do You Want to add more Nodes? (Y/N))n

MENU:
1.Create and Insert Nodes:
2.Inorder Display
3.Postorder Display
4.Preorder Display
0.Exit

Enter your Choice: 2
Entered Tree Inorder is:

J	G	D	H	A	I	C	F	B	E	

MENU:
1.Create and Insert Nodes:
2.Inorder Display
3.Postorder Display
4.Preorder Display
0.Exit

Enter your Choice: 3
Entered Tree Postorder is:

J	G	H	D	I	F	C	E	B	A

MENU:
1.Create and Insert Nodes:
2.Inorder Display
3.Postorder Display
4.Preorder Display
0.Exit

Enter your Choice: 4
Entered Tree Preorder is:

A	D	G	J	H	B	C	I	F	E	

MENU:
1.Create and Insert Nodes:
2.Inorder Display
3.Postorder Display
4.Preorder Display
0.Exit

Enter your Choice: 0

Exiting the Program
unix@unix-dx2480-MT:~/SEA18$ 

*/
