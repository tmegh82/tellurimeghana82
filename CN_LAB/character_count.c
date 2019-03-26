#include<stdio.h>
#include<string.h>

int main()
{
	
	int i,j = 0,dsize,fsize,tsize,denter,frames;

	printf("Enter size of the data you want to enter:");
		scanf("%d",&dsize);

	char d[dsize],dstuff[dsize];

	printf("Enter data of size %d :",dsize);
		scanf("%s",d);

	printf("Entered data is :");

	for(i=0;i<dsize;i++)
		printf("%c ",d[i]);
		printf("\n");


	printf("Enter size of the frame : ");
		scanf("%d",&fsize);

	int s = fsize;
	denter = fsize - 1;
	frames = (dsize/denter) + 1;
	tsize = dsize + frames;
	char a[tsize];

	for(i=0;i<tsize;i++)
	{
		if(i%fsize == 0)
		{
			if(d[j]=='\0')
			break;

			if(dsize-j < fsize)
				fsize = (dsize -j) + 1;
			
			a[i] = (char)(fsize + 48);
		
		}
		else
		{
			if(d[j]=='\0')
				break;
	
			a[i] = d[j];
			++j;
			}
	}

	fsize = s;

	printf("Data Stuffed is :");

	for(i=0;i<tsize;i++)
		printf("%c ",a[i]);
		printf("\n");

	j=0;

	for(i=0;i<tsize;i++)
	{
		if(i%fsize==0)    //s is fsize
		{
		
		}
		else
		{
			dstuff[j]=a[i];
			++j;
			}
		}

	printf("On Receiver side data is :");
 
	for(i=0;i<dsize;i++)
		printf("%c ",dstuff[i]);
		printf("\n");

	return(0);
	}

