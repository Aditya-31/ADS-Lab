#include<iostream>
#include<string.h>
using namespace std;
class myHash
{
		char mobNo[10];
		char name[20];
	public:
		 myHash(){
		 strcpy(mobNo,"");
		 strcpy(name,"");
		 }
		 friend class Hash;
};
class Hash
{
		myHash h [50][5];
		int maxInput;
	public:
		Hash(){	maxInput=0;}
		void inputData(){
			cout<<"Please input the number of elements you want to input in the hash table : "<<endl;
			cin>>maxInput;
			for(int i=0;i<maxInput;i++)
			{
				cout<<"Enter name of the Person : ";
				flushall();
				cin.getline(h[i].name,sizeof(h[i].name));
				cout<<"Enter mobile number of the Person : ";
				cin.getline(h[i].mobNo,sizeof(h[i].mobNo));
				linearprobing();
			}
		}
		void linearprobing(){}
		int hash(char key[20],int basic=1)
		{
			if (basic)
			{
				//
			}
			else
			{
			}
		}
};
int main()
{
	Hash h;
	h.inputData();
	return 0;
}
