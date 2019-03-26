#include<iostream>

using namespace std;

struct sjf_sche
{
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int flag;
};

class SJF
{
	public:
		int n;
		sjf_sche s[50];
		double avg_tat;
		double avg_wt;
		void sorting();
		void display();
				
	SJF()
	{
		
		
			cout<<"Enter number of processes: ";
			cin>>n;
			
			for(int i=0;i<=n-1;i++)
			s[i].flag = 0;
			
			cout<<"Enter pid, at, bt"<<endl;
			
			for(int i=0;i<=n-1;i++)
			{
				cin>>s[i].pid;
				cin>>s[i].at;
				cin>>s[i].bt;	
			}
	}
		
};

void SJF::sorting()
{
	sjf_sche temp;
	int k = 0;
	int min = 39;
	int count = 0;
	int idle;
	int pos;
	int c_t;
	int total_tat = 0;
	int total_wt = 0;
	
	for(int i=0;i<=n-1;i++)
	{
		for(int j=0;j<=n-2-i;j++)
		{
			if(s[j+1].at < s[j].at)
			{
				temp = s[j+1];
				s[j+1] = s[j];
				s[j] = temp;
				}
				
			else
			{ 
				if(s[j+1].at == s[j].at && s[j+1].bt<s[j].bt)
				{
					temp = s[j+1];
					s[j+1] = s[j];
					s[j] = temp;
					}
				}	
		}
	}
		
	s[k].ct = s[k].at + s[k].bt;
	s[k].tat = s[k].ct - s[k].at;
	s[k].wt = s[k].tat - s[k].bt;
	s[k].flag = 1;
	
	c_t = s[k].ct;
	
	++count;
	
	while(count<n)
	{
		for(int m=1;m<=n-1;m++)
		{
			if(s[m].at <= c_t && min>s[m].bt && s[m].flag!=1)
			{
				min = s[m].bt;
				pos = m;
			}
		}
		
		idle = s[pos].at - s[k].ct;
		
		if(idle>0)
		s[pos].ct = s[k].ct + s[pos].bt + idle;
		
		else
		s[pos].ct = s[k].ct + s[pos].bt;
		
		s[pos].tat = s[pos].ct - s[pos].at;
		s[pos].wt = s[pos].tat - s[pos].bt;
		s[pos].flag = 1;
		
		c_t = s[pos].ct;
		k = pos;
		++count;
		min = 39;
		idle = 0;
		
		}
		
	for(int m=0;m<=n-1;m++)
	{
		total_tat = total_tat + s[m].tat;
		total_wt = total_wt + s[m].wt;
		}
	
		avg_tat = (double)total_tat/n;
		avg_wt = (double)total_wt/n;

}

void SJF::display()
{
		cout<<"ProcessId  Arrival_Time  Burst_Time  Complete_Time  TAT_Time  Waiting_Time "<<endl;
		
	for(int j=0;j<=n-1;j++)
		cout<<s[j].pid<<"\t \t"<<s[j].at<<"\t \t"<<s[j].bt<<"\t    "<<s[j].ct<<"\t \t"<<s[j].tat<<"\t \t"<<s[j].wt<<endl;
	
		cout<<"Average Turnaround time :"<<avg_tat<<endl;
		cout<<"Average Waiting Time:" <<avg_wt<<endl;
}


int main()
{
	SJF p;
	p.sorting();
	p.display();
}
	






