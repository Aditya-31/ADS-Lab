/*Name: Aditya Gade		Date:23/12/2019		Class: SE-A
	A Java Program to take array size input and elements so as to perform HEAP SORT
*/
import java.util.Scanner;

class Heapsort{
	
	public static Scanner s=new Scanner(System.in);
	public static int arr[]=new int [50];
	public static int size;
	
	public static void readArray(){
			System.out.println("\nEnter Size of Array : ");
			size=s.nextInt();
			System.out.println("\n Enter Element of array: ");
			for(int i=0;i<size;i++)
				arr[i]=s.nextInt();
	}//End of Read Array
	
	public static void displayArray(){
			System.out.println("\n\n Array is :\n");
			for(int i=0;i<size;i++){
				System.out.print(" ");
				System.out.print(+arr[i]);
			}
			System.out.println("\n");
	}//End of display
	
	public static void initialize(){
			size=10;
			System.out.print("\nYour Array has been initialized to the given default case!!\n");
			int b[]={129,30,80,60,10,5,122,92,69,55};
			int temp=0;			
			while(temp<size)
			{
				arr[temp]=b[temp];
				temp++;	
			}
	}//End of initialize
	
	public static void heapSort(){
			for(int j=(size-1)/2;j>=0;j--)
			{
				System.out.print(j);
				reHeapDown(j,size-1);
				
			}
			int currentsize=size-1;
			while(currentsize!=0)	
			{
				if(currentsize!=1)
					swap(currentsize,0);//Default Parameter used in the function prototype
				reHeapDown(0,currentsize);
				currentsize--;
			}
	}//End of heapsort
	
	public static void swap(int j,int i){
			int temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;		
	}//End of Swap
		
	public static void reHeapDown(int i,int currentsize){
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
	}//End of reHeapDown
	
	public static void main(String args[]){
			initialize();
			//readArray();	//if user inputs	
			System.out.println("Entered Elements are:");
			displayArray();
			heapSort();
			System.out.println("Sorted Array is:");
			displayArray();	
	}//End of Main Function
}
/**/
