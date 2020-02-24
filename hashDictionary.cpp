#include<iostream>
#include<string.h>
using namespace std;
class MyHash
{
	char word[20];
	char meaning[50];
	MyHash()
	{
		strcpy(word,"");
		strcpy(meaning,"");
	}
	friend class Dictionary;	
};
class Dictionary
{	
	MyHash** oxford;
	int rows;
	int columns;
		public:
			Dictionary(int r, int c)
			{
				rows=r;
				columns=c;
				oxford= new MyHash* [rows];
				for(int i=0;i<rows;i++)
					oxford[i]=new MyHash[columns];
			}
			void input()
			{
				MyHash temp;
				int t;
				cout<<"\nEnter the number of words you are inputing in the dictionary : ";
				cin>>t;
				for(int i=0;i<t;i++)
				{
					cout<<"\nEnter the word : ";
					cin>>temp.word;
					for(int i=0;temp.word;i++)
						temp.word[i]=tolower(temp.word[i]);
					cout<<"\nEnter the Contact Number: ";
					cin.getline(temp.meaning,sizeof(temp.meaning));
					linearProbing(temp);
				}
			}
			void linearProbing(MyHash temp)
			{
				int index;
				index=hash(temp.word);
			   
				if (oxford[index][0].word == "")
					oxford[index][0]=temp;
				else
				{
					for(int i=1; i< columns ; i=i++)
					{						 
							if (oxford[index][i].word == "")
							{
								 oxford[index][i]=temp;
								 break;
							}
							else
								cout<<"Can't add more words starting with alphabet"<<oxford[index][i].word[0]<<"!!!";
					}
				}
			}
			int hash(char key[])
			{
					key[0]=toupper(key[0]); 
				return key[0]-65;
			}
			void task(char query[],int search=0,int erase=0,int update=0)
			{
				int index;
				for(int i=0;query;i++)
					query[i]=tolower(query[i]);
				index=hash(query);
				for(int i=1; i< columns ; i=i++)
					{						 
							if (!strcmp(oxford[index][i].word,query))
							{
								 if(search)
								 	cout<<oxford[index][i].word<<" : "<<oxford[index][i].meaning<<endl;
								 if(erase)
								 {
								 	strcpy(oxford[index][i].word,"");
								 	strcpy(oxford[index][i].meaning,"");
								 	cout<<query<<" Deleted"<<endl; 
								 }
								 if(update)
								 {
								 	cout<<"\n Enter the New meaning of "<<oxford[index][i].word<<" : \n";
								 	cin.getline(oxford[index][i].meaning,sizeof(oxford[index][i].meaning));
								 	cout<<query<<" Updated"<<endl;
								 }
								 break;
							}
							else
								cout<<"The word "<<query<<" isn't present in our Dictionary to perform specified operation";
					}
			}
};
int main()
{
	int c;
	cout<<"Enter the number of maximum words starting by an alphabet : ";
	cin>>c;
	char yes,choice,query[20];
	Dictionary d(26,c);
	do
	{
		cout<<"\nDICTIONARY:";
		cout<<"\n\t1.Input\n\t2.Search\n\t3.Delete\n\t4.Update.";
		cout<<"\nPlease Enter Your Choice : ";
		cin>>choice;
		if(choice!= '1')
			
		switch(choice)
		{
			case '1':
				d.input();
				break;
//				void task(char query[],int search=0,int erase=0,int update=0)
			case '2':
				cout<<"Enter the query : ";
				cin>>query;
				d.task(query,1,0,0);			
				break;
			case '3':
				cout<<"Enter the query : ";
				cin>>query;
				d.task(query,0,1,0);
				break;
			case '4':
				cout<<"Enter the query : ";
				cin>>query;
				d.task(query,0,0,1);
				break;
			default:
				cout<<"\nEnter valid choice!!!! ";
				break;
		}
		cout<<"So you wish to continue \?\? : ";
		cin>>yes;
	}while(yes=='y' || yes=='Y');
}
