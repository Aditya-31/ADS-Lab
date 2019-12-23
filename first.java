/*Name: Aditya Gade		Date:23/12/2019		Class: SE-A
	A Java Program to take array size input and elements so as to calculate Average and Sum of the Array
*/
import java.util.Scanner;

class average{
	public static void main(String args[]){
				Scanner s=new Scanner(System.in);
				int a[]=new int [50];
				int n,i,sum=0,avg=0;
				System.out.println("\nEnter Size of Array : ");
				n=s.nextInt();
				System.out.println("\n Enter Element of array: ");
				for(i=0;i<n;i++)
				{
					a[i]=s.nextInt();
					sum+=a[i];
				}
				avg=sum/n;
				System.out.println("\n\n The Elemennts you entered are:\n");
				for(i=0;i<n;i++)
					System.out.println(+a[i]);
				System.out.println("\n Sum of array: "+sum);
				System.out.println("\n Average of array: "+avg);
			}
}
/*
unix@unix-dx2480-MT:~$ cd SEA18
unix@unix-dx2480-MT:~/SEA18$ javac first.java
unix@unix-dx2480-MT:~/SEA18$ java average

Enter Size of Array : 
6

 Enter Element of array: 
1
2
3
4
5
6
1
2
3
4
5
6

 Sum of array: 21

 Average of array: 3
unix@unix-dx2480-MT:~/SEA18$ 
*/
