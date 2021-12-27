/*Fibonacci search is very similar to binary search, except that the indexes used for comparison are based on Fibonacci numbers rather than the mean 
value of the endpoints. The idea is to first find the smallest Fibonacci number that is greater than or equal to the length of the given array. Let this
found Fibonacci number be the 'n' th Fibonacci number. Then, we use '(n-2)' th Fibonacci number as the index (If it is a valid index). Let '(n-2)' th
Fibonacci number be m, we compare arr[m] with key, and if key is same as arr[m], we return m. Else if key is greater, we recur for subarray after m,
else we recur for subarray before m*/

#include <bits/stdc++.h>
using namespace std;

//It is assumed that the given array is sorted in ascending order beforehand.

int fibonacciSearch(int arr[], int key, int len)
{
	// First initialize the first three consecutive Fibonacci numbers
	int fib1=0;
	int fib2=1;
	int fib3=fib1+fib2;
	// Now, fib3 will store the smallest Fibonacci number that is greater than or equal to the length of the given array
	while(fib3<len)
	{
		fib1=fib2;
		fib2=fib3;
		fib3=fib1+fib2;
	}
	int temp=-1;// Used to keep track of the eliminated range from the front
	while(fib3>1)
	{
		int i=min(temp+fib1, len-1);
		//If key is greater than the value at index fib1, then we cut the subarray array from temp to i
		if(arr[i]<key)
		{
			fib3=fib2;
			fib2=fib1;
			fib1=fib3-fib2;
			temp=i;
		}
		//If key is greater than the value at index fib1, then we cut the subarray after i+1
		else if(arr[i]>key)
		{
			fib3=fib1;
			fib2-=fib1;
			fib1=fib3-fib2;
		}
		//If none of the above conditions is satisfied, then it means that we have found the key at index i
		else
		{
			return i;
		}
	}
	if(fib2 && arr[temp+1]==key)
	{
		return temp+1;
	}
	// Key not found then return -1
	return -1;
}

int main()
{
	int right, key;
	cout<<"Enter number of elements in the array: "<<endl;
	cin>>right;//Length of array
	int arr[right];
	cout<<"Enter the elements of array in ascending order: "<<endl;
	for(int i=0;i<right;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter the element to be searched: "<<endl;
	cin>>key;// Key to be searched in the array
	int ans=fibonacciSearch(arr, key, right);// Search the key in array using Fibonacci Search Technique
	if(ans!=-1)// Check if key is there in array or not
		cout<<"Index of "<<key<<" is "<<ans<<endl;
	else
		cout<<"Element not found in array"<<endl;
}
/*
Time Complexity: O(log(N))
Sample I/O:
INPUT:
Enter number of elements in the array:
10
Enter the elements of array in ascending order:
2
4
6
8
10
12
14
16
18
20
Enter the element to be searched:
14
OUTPUT:
Index of 14 is 6
*/