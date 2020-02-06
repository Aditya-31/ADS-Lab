/*
	Name: Aditya Gade		Date:30/12/2019		Class: SE-A
	A C++ Program for Implementation of Threaded Binary Tree, traversals using it.
*/
#include<iostream>
using namespace std;

class Node{
	
		Node *right,*left;
		int data;
		int isLThread, isRThread;
	public:
		Node(){
			right=left=NULL;
			isLThread=isRThread=0;
		}	
		friend class TBT;
};
class TBT{
		Node *head,*root;	
	public:
		TBT(){
			root=NULL;
			head=new Node;
			head->right=head->left=head;
			head->isLThread=head->isRThread=1;
		}
		void create(){
			Node *temp,*curr;
			char ch;
			do{
				curr=new Node;
				cout<<"\n Enter data for newly created node: ";
				cin>>curr->data;
				curr->left=curr->right=head;
				curr->isLThread=curr->isRThread=1;
				if(root==NULL)
				{
					root=curr;
					head->left=curr;
					head->isLThread=0;
				}
				else
				{	
					temp=root;
					while(1)
					{
						if(curr->data<temp->data)
						{
							if(temp->isLThread==1)
							{
								curr->left=temp->left;
								temp->left=curr;
								temp->isLThread=0;
								curr->right=temp;
								break;
							}
							else
							{
								temp=temp->left;
							}
						}
						else
						{
							if(temp->isRThread==1)
							{
								curr->right=temp->right;
								temp->right=curr;
								temp->isRThread=0;
								curr->left=temp;
								break;			
							}
							else
							{
								temp=temp->right;
							}
						}
					}
				}
				cout<<" "<<curr->data<<" is successfully inserted in Threaded Binary Tree."<<endl;
				cout<<"Do You Wish to enter another node? : ";
				cin>>ch;
			}while(ch=='y' || ch=='Y');
		}
		int search(char key){
		    Node* temp = root;
		    do{
				if(temp->data==key)
					return 1;
				else if(key<temp->data)
					temp=temp->left;
				else
					temp=temp->right;
            }while(temp);
            return 0;		//If not Found
		}
		void inorderDisplay(){
			cout<<"\nInorder Display : ";
			inorder(root);
		}
		void inorder(Node *root){
			Node *temp;
			int flag=0;
			temp=root;
			while(temp!=head){
				
				if(temp->isLThread==0 && flag==0){
					temp=temp->left;
				}
				else{
					cout<<temp->data<<" ";
					if(temp->isRThread==0){
						temp=temp->right;
						flag=0;
					}
					else{
						temp=temp->right;
						flag=1;
					}
				}
				
			}
		}
		void preorderDisplay(){
			cout<<"\nPreorder Display : ";
			preorder(root);
		}
		void preorder(Node *root){
			Node *temp;
			int flag=0;
			temp=root;
			while(temp!=head){
				if(flag==0)
					cout<<temp->data<<" ";
				if(temp->isLThread==0 && flag==0){
					temp=temp->left;
				}
				else{
					if(temp->isRThread==0){
						temp=temp->right;
						flag=0;
					}
					else{
						temp=temp->right;
						flag=1;
					}
				}
				
			}
		}

};
int main()
{
	TBT tree;
	tree.create();
	tree.inorderDisplay();
	tree.preorderDisplay();
	return 0;
}
/*
unix@unix-HP-280-G4-MT-Business-PC:~$ cd SEA18
unix@unix-HP-280-G4-MT-Business-PC:~/SEA18$ g++ TBT.cpp
unix@unix-HP-280-G4-MT-Business-PC:~/SEA18$ ./a.out

 Enter data for newly created node: O 
 O is successfully inserted in Threaded Binary Tree.
Do You Wish to enter another node? : y

 Enter data for newly created node: Q 
 Q is successfully inserted in Threaded Binary Tree.
Do You Wish to enter another node? : y

 Enter data for newly created node: J
f1 J is successfully inserted in Threaded Binary Tree.
Do You Wish to enter another node? : y

 Enter data for newly created node: G
f1 G is successfully inserted in Threaded Binary Tree.
Do You Wish to enter another node? : y

 Enter data for newly created node: L
 L is successfully inserted in Threaded Binary Tree.
Do You Wish to enter another node? : y

 Enter data for newly created node: P
f1 P is successfully inserted in Threaded Binary Tree.
Do You Wish to enter another node? : y

 Enter data for newly created node: T
 T is successfully inserted in Threaded Binary Tree.
Do You Wish to enter another node? : y

 Enter data for newly created node: D
f1 D is successfully inserted in Threaded Binary Tree.
Do You Wish to enter another node? : y

 Enter data for newly created node: I
 I is successfully inserted in Threaded Binary Tree.
Do You Wish to enter another node? : y

 Enter data for newly created node: K
f1 K is successfully inserted in Threaded Binary Tree.
Do You Wish to enter another node? : y

 Enter data for newly created node: N
 N is successfully inserted in Threaded Binary Tree.
Do You Wish to enter another node? : y

 Enter data for newly created node: S
f1 S is successfully inserted in Threaded Binary Tree.
Do You Wish to enter another node? : y

 Enter data for newly created node: V
 V is successfully inserted in Threaded Binary Tree.
Do You Wish to enter another node? : y

 Enter data for newly created node: R
f1 R is successfully inserted in Threaded Binary Tree.
Do You Wish to enter another node? : y

 Enter data for newly created node: U
f1 U is successfully inserted in Threaded Binary Tree.
Do You Wish to enter another node? : y

 Enter data for newly created node: W
 W is successfully inserted in Threaded Binary Tree.
Do You Wish to enter another node? : n

Inorder Display : D G I J K L N O P Q R S T U V W 
Preorder Display : O J G D I L K N Q P T S R V U W \unix@unix-HP-280-G4-MT-Business-PC:~/SEA18$ \

*/
