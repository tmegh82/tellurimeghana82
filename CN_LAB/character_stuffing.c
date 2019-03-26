#include<stdio.h>
#include<string.h>

int main()
{
	char a[50],b[50];
	int i = 0,j = 0,n,ns,nb;
	
	strcpy(b, "");

        printf("Enter data string :");
		scanf("%s",a);

        n = strlen(a);

    	printf("Let us take starting delimiter as : dlestx and ending as: dleetx\n");
	
	char s[7] = {'d','l','e','s','t','x','\0'};
	char e[7] = {'d','l','e','e','t','x','\0'};
	
	b[0] = 'i';

	strcat(b,s);
	nb = strlen(b);

	/*for(j=1;j<nb;j++)
	printf("%c",b[j]);
	printf("\n");
		*/
	j = nb;

	while(i<n)
	{
		if(a[i]=='d' && a[i+1]=='l' && a[i+2]=='e')
		{
			b[j] = 'd';
			b[j+1] = 'l';
			b[j+2] = 'e';
			j = j + 3; 
			}
		b[j] = a[i];
		++i;
		++j;	
		//b[j] = '\0';
		}
	
	b[j] = '\0';

	strcat(b,e);
	nb = strlen(b);

	printf("Length of string at the end :%d \n",nb);
	printf("Data after stuffing is :");

	for(i=1;i<nb;i++)
		printf("%c",b[i]);

	printf("\n");

	printf("On receiver side after destuffing it is ");
	
	for(i=0;i<n;i++)
		printf("%c",a[i]);
		printf("\n");

	return(0);
}

