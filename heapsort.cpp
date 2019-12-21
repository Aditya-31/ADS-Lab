#include<iostream>
using namespace std;

class Array
{
		int *arr;
		int size;
	public:
		Array(int n)	//Parameterized Constructor
		{
			size=n;
			arr= new int[size];
		}
		void readArray()
		{
			cout<<"Enter "<<size<<" Elements:"<<endl;
			for(int i=0;i<size;i++)
				cin>>arr[i];
		}
		void displayArray(const char msg[]="")
		{
			cout<<msg<<endl;
			for(int i=0;i<size;i++)
				cout<<arr[i]<<" ";
			cout<<endl;
		}
		void heapSort()
		{
			for(int j=(size-1)/2;j>=0;j--)
			{
				cout<<j;
				reHeapDown(j,size-1);
				
			}
			int currentsize=size-1;
			while(currentsize)	
			{
				if(currentsize!=1)
					swap(currentsize);//Default Parameter used in the function prototype
				reHeapDown(0,currentsize);
				currentsize--;
			}
		}
		void swap(int j,int i=0)
		{
			int temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;		
		}	
		void reHeapDown(int i,int currentsize)
		{
			do
			{
				int left=2*i+1;
				int right=2*i+2;
				if((arr[left]<arr[right])&& (right<currentsize))//Right bigger & bound check
				{	
					if(arr[right]>arr[i])
						swap(i,right);
					i=right;
				}
				else if((arr[right]<arr[left]) && (left<currentsize))//Left bigger & bound check
				{	
					if(arr[left]>arr[i])
						swap(i,left);
					i=left;				
				}
				else
					break;
				
			}while(2*i<currentsize);
			displayArray();
		}
		void initialize()
		{
			cout<<"\nYour Array has been initialized to the given default case!!\n";
			int b[10]={129,30,80,60,10,5,122,92,69,55};
			int temp=0;			
			while(temp<size)
			{
				arr[temp]=b[temp];
				temp++;	
			}
		}

};
int main()
{
	Array a(10);
	//a.initialize();
	a.readArray();	
	a.displayArray("Entered Elements are:");
	a.heapSort();
	a.displayArray("Sorted Array is:");
	return 0;
}
