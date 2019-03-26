#include <iostream>
//#include<stdio.h>

using namespace std;


int main()
{
	int head = -1;
	int rear = -1;
	int n,i,rem,k,m;

	cout<<"Enter bucket size:";
	cin>>n;
//	cout<<"Enter transmission rate:";
//	cin>>t;
	int a[100];
	int out[100];

	cout<<"Enter 1 for enqueue , 2 for dequeue , 3 for termination: ";
	cin>>k; 
	while(k!=3)
	{
	switch(k)
	{
		case 1:
			cout<<"Enter input and 0 to terminate enquque:";
			cin>>i;


			while(i!=0)
			{
				if(head == -1)
				{
					a[++head] = i;
					++rear;
				}

				else
				{
					a[++rear] = i;
				}
			cout<<"Enter input and 0 to terminate enquque:";
			cin>>i;
	
			}
			break;
		
		case 2:
			if(head==-1 && rear==-1)
				cout<<"Queue empty cannot dequeue"<<endl;
			else
			{
				rem = a[head] - 1;
 				if(rem>0)
				{
					a[head+1] = rem + a[head+1];
					++head;

					for(m= head;m<=rear;m++)
						cout<<a[m]<<" ";
						cout<<endl;

					if(a[head]>n)
					{
						cout<<"Overflow"<<endl;
						return(0);
					}				
				}
			}
			
			break;
	}
			cout<<"Enter 1 for enqueue , 2 for dequeue , 3 for termination: ";
			cin>>k; 
	}
	
}
				
