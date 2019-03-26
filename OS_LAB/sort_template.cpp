
#include<iostream>
#include<string.h>

using namespace std;


template < class S > 
void sorting (S ar[], int n)
{ 
	int i,j;
	S temp;
	
	for(i=0; i<=n-1;i++)
	{
		for(j=0; j<=n-2-i; j++)
		{
			if(ar[j+1] < ar[j])
			{
				temp = ar[j+1];
				 ar[j+1] = ar[j];
				 ar[j] = temp; 
				}		
		}	


	}
}


int main()
{
	int i,k,n;

	/*cout<<"Enter size of array: "<<endl;
	cin>>n;

	string a[n];
	
	cout<<"Enter input numbers:"<<endl;

	for(i=0;i<n;i++)
	cin>>a[i];

	sorting(a,n);

	cout<<"Output array: "<<endl;
	
	
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";

	cout<<endl;
*/

	int a1[100];
	double a2[100];
	float a3[100];
	char a4[100];


	do
	{
	cout<<"Enter 1 for integer value sorting, 2 for double values, 3 for floating values, 4 for char sortings, 5 to exit: "<<endl;

	cin>>k;
	
		switch (k)
		{

		case 1:
			cout<<"Enter array size: ";
			cin>>n;
			a1[n];
			
			cout<<"Enter integer values: ";
			
			for(i=0;i<n;i++)
			cin>>a1[i];
			
			sorting(a1 , n);

			cout<<"Sorted array is: ";
			
			for(i=0;i<n;i++)
				cout<<a1[i]<<" ";	
				cout<<endl;	
			
			break;

		case 2:
			cout<<"Enter array size: ";
			cin>>n;
		
			a2[n];
			
			cout<<"Enter double values: ";
			
			for(i=0;i<n;i++)
			cin>>a2[i];

			sorting(a2 , n);

			cout<<"Sorted array is: ";
			
			for(i=0;i<n;i++)
				cout<<a2[i]<<" ";	
				cout<<endl;	

			break;
		case 3:
			cout<<"Enter array size: ";
			cin>>n;
		
		 	a3[n];
			
			cout<<"Enter float values: ";
			
			for(i=0;i<n;i++)
			cin>>a3[i];

			sorting(a3 , n);

			cout<<"Sorted array is: ";
			
			for(i=0;i<n;i++)
				cout<<a3[i]<<" ";	
				cout<<endl;	
					
			break;
	
		case 4:
			cout<<"Enter array size: ";
			cin>>n;
		
		 	a4[n];
			
			cout<<"Enter char values: ";
			
			for(i=0;i<n;i++)
			cin>>a4[i];
			
			sorting(a4 , n);

			cout<<"Sorted array is: ";
			
			for(i=0;i<n;i++)
				cout<<a4[i]<<" ";	
				cout<<endl;	
				
			break;
		default:
			printf("Wrong input\n");

		}

		
	}
	while(k!=5);
	
}




