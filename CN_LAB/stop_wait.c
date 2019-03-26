#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{

	int frames;
	int x,x1,x2;

	printf("How many packets you want to send:? ");
	scanf("%d",&frames);

	x1 = 1;

	while(x1<=frames)
	{
		printf("Sending Packet : %d\n",x1);
		printf("\n");
		x = rand();
		
		while(1)
		{

			if(x%2==0)
			{
				x2 = rand();
				if(x2%2==0)
				{
					printf("Packet lost --> sender timeouts\n\n");
					printf("Retransmitting Packet: %d\n\n",x1);
					x = rand();
					continue;
				}
				else
				{
					printf("Acknowledgment lost\n");
					printf("Retransmitting Packet: %d\n",x1);
					printf("Receiver: Duplicate packet\n\n");
					x = rand();
					continue;
					}
			
			}
			else
			break;
		}
		
	printf("\n");
	printf("Acknowledgment for Packet is: ACK%d \n",x1+1);
	printf("Packet %d received successfully\n............................................................\n",x1);						
	x1 = x1 + 1;

		}

	printf("End of stop and wait protocol\n");


	}
