#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,m,f,x,x1,n,ws,k,nck,n1,x3,sw,flag = 0;

	printf("Enter window size : ");
	scanf("%d",&ws);
	
	int send[ws];
	
	printf("Number of frames? :");
	scanf("%d",&f);
	
	m = f;
	k = 1;

	while(k<=m)
	{
		if(flag!=0)
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

		x = rand()%2;
		if(x==0)
		{
			x1 = rand()%2;
			if(x1==0)
			{
				flag = 1;
				printf("Receiver has sent Ack number? : ");
				scanf("%d",&n1);
				printf("Sender: Retransmitting packt %d \n",n1);
				
				for(i=1;i<=ws && send[i]!=k;i++)
				{
					if(send[i]!=n1)
					printf("Pckt %d received successfully\n",send[i]);
					sw = i;
					}	

						
			}
			
			else
			{
				flag = 11;
				printf("Enter the pckt for which it is time out (As ack is lost)\n");
				scanf("%d",&n1);
				printf("Packet %d to be retransmitted\n",n1);

				/*if(k<=(m-ws))
					x3 = ws;
				else
					x3 = m - k;
				*/
				for(i=1;i<=ws && send[i]!=k;i++)
				{
					if(send[i]!=n1)
					printf("Pckt %d received successfully\n",send[i]);
					sw = i;
					}	
			
			}	
		}
		
		else
		{
			for(i=1;i<=sw;i++)
			{
				printf("Pckt %d received successfully\n",send[i]);
				
			}
		
		}
}

	/*	for(j=1;j<=sw && sw!=-1;j++)
			printf("Pckt %d received successfully\n",send[j]);
	*/					
return(0);
}
