#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,m,f,x,x1,x2,n,ws,k,x3,sw,flag = 0;

	printf("Enter window size : ");
	scanf("%d",&ws);
	
	int send[ws];
	
	printf("Number of packets? :");
	scanf("%d",&f);
	
	m = f;
	k = 1;
	n = 0;
	while(n<=m)
	{
		/*if(flag!=0)
		{
			                                                                                                                                                                                                                                                                                                                                                                                                                                                   		send[1] = n1;
				printf("Transmitting : %d \n" ,send[1]);
				for(i=2;i<=ws && k<=m;i++,k++)
				{
					send[i] = k;
					printf("Transmitting : %d \n" ,send[i]);
					sw = i;
					}	
				if(flag==11)
				printf("Receiver: Duplicate packt %d is received so discarded\n",n1);	
			}
		else
		{
			for(i=1;i<=ws && k<=m;i++,k++)
			{
				send[i] = k;
				printf("Transmitting frame: %d \n" ,send[i]);
				sw = i;
			}
		}
		
		flag = 0;
*/

		//printf("Transmitting : %d \n" ,send[1]);
			

		if(flag==1)
		{	
				printf("\n");
			for(i=1;i<=sw;i++)
			{
					printf("Retransmitting : %d \n" ,send[i]);
				
			}		
		     printf("\n");
			if(x3==1)
			printf("Receiver: Duplicate Packet received so discarded (When Ack lost previoulsy)\n\n");
			x3 = 0;
		}

		else
		{
			for(i=1;i<=ws && k<=m;i++,k++)
			{
			       send[i] = k;
				printf("Transmitting : %d \n" ,send[i]);
				sw = i;
			}
			printf("\n");
		}
		//printf("Value of k is  %d\n",k);

		flag = 0;

		x = rand()%2;
		if(x==0)
		{
			x1 = rand();
			x2 = x1%(sw+1);
			if(x2==0)
			x2 = x2 + 1;
		//	printf("Value of x2 is %d\n",x2);
			x3 = rand()%2;
			printf("Sender time out : Time out; Ack for packet %d is not received \n",send[x2]);
			printf("Retransmitting whole frame\n");
			flag = 1;
		
		}	

		else
		{
			printf("Ack received is: Ack %d\n\n",send[sw] + 1);
			for(i=1;i<=sw;i++)
			{
				printf("Pckt %d received successfully\n",send[i]);
				++n;
				//printf("Value of n is %d\n",n);
			}
			printf("..............................................................\n"); 
			printf("\n");
			if(n==m)
			break;
		}
		
	}
printf("End of Go-Back_n protocol\n");

return(0);
}
