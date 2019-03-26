#include<iostream>

using namespace std;

struct srt
{
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int flag;
};

class SRT
{
	public:
		int n;
		struct srt s[50];
		double avg_tat,avg_wt;
		int s2[50];
		
		SRT()
		{
			cout<<"Enter number of processes:";
			cin>>n;
			
			cout<<"Enter pid,at,bt:"<<endl;
			
			for(int i=0;i<=n-1;i++)
			{
				cin>>s[i].pid;
				cin>>s[i].at;
				cin>>s[i].bt;
			}
			for(int i=0;i<=n-1;i++)
			{
			s[i].flag = 0;
			s2[i] = s[i].bt;
				}
		}
		
	void sorting();
	void display();
		
		
};

void SRT::sorting()
{
	
	struct srt temp;
	int k,count=0;
	int min = 1000;
	int pos = -1;
	int c_t,total_tat = 0,total_wt = 0;
	int idle = 0;
	int i,j;
	
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-2-i;j++)
		{
			if(s[j+1].at < s[j].at)
			{
				temp =s[j+1];
				s[j+1] = s[j];
				s[j] = temp;
				}
			else
				{
					if(s[j+1].at == s[j].at && s[j+1].bt < s[j].bt)
					{
						temp = s[j+1];
						s[j+1] = s[j];
						s[j] = temp;
					}
				}
			}
		}
		
		k = 0;
		--s[k].bt;
		
		if(s[k].bt==0)
		{
			s[k].flag = 1;
			++count;
		}
		
		s[k].ct = s[k].at + 1;
		c_t = s[k].ct;
		//display();		

	//cout<<"Value of n before while is "<<n<<endl;
	
		while(count<n)
		{
			for(i=0;i<=n-1;i++)
			{
				if(s[i].at<=(c_t+idle) && s[i].flag!=1 && min>s[i].bt)
				{
					min = s[i].bt;
					pos = i;
					}
				}
			
				//cout<<"Position is "<<pos<<endl;				

				if((c_t+idle) >= s[n-1].at)
				{
					s[pos].ct = c_t + s[pos].bt + idle;
					s[pos].bt = 0;
					++count;
					s[pos].flag = 1;
				}
				else
				{	
					if(pos!=-1)
					{
					--s[pos].bt;
					s[pos].ct = c_t + 1 + idle;
					if(s[pos].bt == 0)
					{
						++count;
						s[pos].flag = 1;
						}	
							}
				}
				
				if(pos==-1)
					idle = s[k+1].at - c_t;
				else
					{
						idle = 0;
						c_t = s[pos].ct;
						
						}

					
					min = 1000;
					pos = -1;
					k = pos;
				//cout<<"Value of count is "<<count<<endl;
				//cout<<"Value of n is "<<n<<endl;	
			
			}
			
			for(int i=0;i<=n-1;i++)
			{
			s[i].tat = s[i].ct -  s[i].at;
			total_tat = total_tat + s[i].tat;
			s[i].wt = s[i].tat - s2[i];
			total_wt = total_wt + s[i].wt;
			}	
			
			avg_tat = (double)total_tat /n;
			avg_wt = (double)total_wt/n;
		
}

void SRT::display()
{
	cout<<"ProcessId  Arrival_Time  Burst_Time  Complete_Time  TAT_Time  Waiting_Time "<<endl;
	
	for(int j=0;j<=n-1;j++)
		cout<<s[j].pid<<"\t \t"<<s[j].at<<"\t \t"<<s2[j]<<"\t    "<<s[j].ct<<"\t \t"<<s[j].tat<<"\t \t"<<s[j].wt<<endl;
	cout<<"Average Turn Around Time  "<<avg_tat<<endl;
	cout<<"Average Waiting Time  "<<avg_wt<<endl;
}
	
int main()
{
	SRT S;
	S.sorting();
	S.display();
	
}




