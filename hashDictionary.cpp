#include<iostream>
#include<string.h>
using namespace std;
class MyHash
{
	char word[20];
	char meaning[50];
	MyHash()
	{
		strcpy(word,"NULL");
		strcpy(meaning,"NULL");
	}
	public:
		void operator +(MyHash& temp)
		{
			strcpy(word,temp.word);
			strcpy(meaning,temp.meaning);
		} 
	friend class Dictionary;	
};
class Dictionary
{	
	MyHash** oxford;
	int rows;
	int columns;
		public:
			Dictionary(int c,int r=26)
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
				char word;
				do
				{
					cout<<"\nEnter the word : ";
					cin>>temp.word;
					/*for(int i=0;temp.word;i++)
						temp.word[i]=tolower(temp.word[i]);
					*/
					cout<<"Enter the Meaning: ";
					cin.ignore();
					cin.getline(temp.meaning,sizeof(temp.meaning));
					linearProbing(temp);
					cout<<"\nEnter another word?? : ";
					cin>>word;
				}while (word=='y' || word=='Y');
			}
			void linearProbing(MyHash temp)
			{
				int index;
				index=hash(temp.word);
				if (!strcmp(oxford[index][0].word , "NULL"))
				{
					oxford[index][0]=temp;
					//cout<<oxford[index][0].word<<endl;		
				}
				else
				{
					for(int i=0; i< columns ; i++)
					{						 
							if (!strcmp(oxford[index][i].word , "NULL"))
							{
								 oxford[index][i]=temp;
								 cout<<oxford[index][i].word<<endl;		
								 break;
							}
							else
								cout<<"Can't add more words starting with alphabet"<<oxford[index][i].word[0]<<"!!!";
					}
				}
			}
			int hash(char key[])
			{
				//cout<<key[0]-97;
				return key[0]-97;
			}
			void task(char query[],int search=0,int erase=0,int update=0)
			{
				int index;
				/*for(int i=0;query;i++)
					query[i]=tolower(query[i]);*/
				index=hash(query);
				for(int i=0; i< columns ; i++)
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
						 	cout<<"\nEnter the New meaning of "<<oxford[index][i].word<<" : ";
						 	cin.ignore();
						 	cin.getline(oxford[index][i].meaning,sizeof(oxford[index][i].meaning));
						 	cout<<query<<" is Updated"<<endl;
						 }
						return;
					}
				}
				cout<<"The word "<<query<<" isn't present in our Dictionary.\n";
			}
			void displayDictionary()
			{
				for(int i=0;i<rows;i++)
				{
					if(strcmp(oxford[i][0].word,"NULL"))
					{
						cout<<(char)i+65<<endl;
						for(int j=0;j<columns;j++)
						{
							if(!strcmp(oxford[i][j].word,"NULL"))
							{
								cout<<oxford[i][j].word<<" : "<<oxford[i][j].meaning<<endl;
							}
						}
					}
				}
			}
			void writeToFile()
			{
				//fout.open("reportcard.csv", ios::out | ios::app);
			}
};
int main()
{
	int c;
	cout<<"Enter the number of maximum words starting by an alphabet : ";
	cin>>c;
	char yes,query[20];
	int choice;
	Dictionary d(26);
	do
	{
		cout<<"\nDICTIONARY:";
		cout<<"\n\t1.Input\n\t2.Search\n\t3.Delete\n\t4.Update.\n\t5.Display Dictionary.";
		cout<<"\nPlease Enter Your Choice : ";
		cin>>choice;
		if(choice!= '1')
			
		switch(choice)
		{
			case 1:
				d.input();
				break;
			//void task(char query[],int search=0,int erase=0,int update=0)
			case 2:
				cout<<"Enter the query to be searched : ";
				cin>>query;
				d.task(query,1,0,0);			
				break;
			case 3:
				cout<<"Enter the query to be deleted : ";
				cin>>query;
				d.task(query,0,1,0);
				break;
			case 4:
				cout<<"Enter the query to be updated : ";
				cin>>query;
				d.task(query,0,0,1);
				break;
			case 5:
				d.displayDictionary();
				break;
			default:
				cout<<"\nEnter valid choice!!!! ";
				break;
		}
		cout<<"Do you wish to continue \?\? : ";
		cin>>yes;
	}while(yes=='y' || yes=='Y');
	//d.writeToFile();
}
/*
OUTPUT:
unix@unix-HP-280-G4-MT-Business-PC:~$ cd SEA18
unix@unix-HP-280-G4-MT-Business-PC:~/SEA18$ g++ hashDictionary.cpp
unix@unix-HP-280-G4-MT-Business-PC:~/SEA18$ ./a.out
Enter the number of maximum words starting by an alphabet : 5

DICTIONARY:
	1.Input
	2.Search
	3.Delete
	4.Update.
	5.Display Dictionary.
Please Enter Your Choice : 1

Enter the word : bottle

Enter the Meaning: the equipment to store water
Enter another word?? : y

Enter the word : mobile

Enter the Meaning: the device used for communication
Enter another word?? : y

Enter the word : watch

Enter the Meaning: the device for time related info      
Enter another word?? : y

Enter the word : assignments

Enter the Meaning: used for regular evaluation
Enter another word?? : y

Enter the word : earth

Enter the Meaning: the place where humans live
Enter another word?? : n
Do you wish to continue ?? : y

DICTIONARY:
	1.Input
	2.Search
	3.Delete
	4.Update.
	5.Display Dictionary.
Please Enter Your Choice : 2
Enter the query to be searched : earth 
earth : the place where humans live
Do you wish to continue ?? : y

DICTIONARY:
	1.Input
	2.Search
	3.Delete
	4.Update.
	5.Display Dictionary.
Please Enter Your Choice : 2
Enter the query to be searched : bottle
bottle : the equipment to store water
Do you wish to continue ?? : y

DICTIONARY:
	1.Input
	2.Search
	3.Delete
	4.Update.
	5.Display Dictionary.
Please Enter Your Choice : 2
Enter the query to be searched : pen
The word pen isn't present in our Dictionary.
Do you wish to continue ?? : y

DICTIONARY:
	1.Input
	2.Search
	3.Delete
	4.Update.
	5.Display Dictionary.
Please Enter Your Choice : 3
Enter the query to be deleted : earth
earth Deleted
Do you wish to continue ?? : y

DICTIONARY:
	1.Input
	2.Search
	3.Delete
	4.Update.
	5.Display Dictionary.
Please Enter Your Choice : 4
Enter the query to be updated : assignments

 Enter the New meaning of assignments : 
copy and submit it
assignments is Updated
Do you wish to continue ?? : y

DICTIONARY:
	1.Input
	2.Search
	3.Delete
	4.Update.
	5.Display Dictionary.
Please Enter Your Choice : 2
Enter the query to be searched : assignments
assignments : copy and submit it
Do you wish to continue ?? : 5
unix@unix-HP-280-G4-MT-Business-PC:~/SEA18$ 

*/
