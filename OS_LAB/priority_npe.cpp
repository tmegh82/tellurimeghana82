#include<iostream>

using namespace std;

struct priority_sche
{
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int flag;
	int pri_ty;
};

class PRIORITY
{
	public:
		int n;
		priority_sche p[50];
		double avg_tat;
		double avg_wt;
		void sorting();
		void display();
				
	PRIORITY()
	{
		
		
			cout<<"Enter number of processes: ";
			cin>>n;
			
			for(int i=0;i<=n-1;i++)
			p[i].flag = 0;
			
			cout<<"Enter pid, at, bt, priority"<<endl;
			
			for(int i=0;i<=n-1;i++)
			{
				cin>>p[i].pid;
				cin>>p[i].at;
				cin>>p[i].bt;	
				cin>>p[i].pri_ty;
			}
	}
		
};

void PRIORITY::sorting()
{
	priority_sche temp;
	int k = 0;
	int max = -1;
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
			if(p[j+1].at < p[j].at)
			{
				temp = p[j+1];
				p[j+1] = p[j];
				p[j] = temp;
				}
				
			else
			{ 
				if(p[j+1].at == p[j].at && p[j+1].bt< p[j].bt)
				{
					temp = p[j+1];
					p[j+1] = p[j];
					p[j] = temp;
					}
				}	
		}
	}
		
	p[k].ct = p[k].at + p[k].bt;
	p[k].tat = p[k].ct - p[k].at;
	p[k].wt = p[k].tat - p[k].bt;
	p[k].flag = 1;
	
	c_t = p[k].ct;
	
	++count;
	
	while(count<n)
	{
		for(int m=1;m<=n-1;m++)
		{
			if(p[m].at <= c_t && max<p[m].pri_ty && p[m].flag!=1)
			{
				max = p[m].pri_ty;
				pos = m;
			}
		}
		
		idle = p[pos].at - p[k].ct;
		
		if(idle>0)
		p[pos].ct = p[k].ct + p[pos].bt + idle;
		
		else
		p[pos].ct = p[k].ct + p[pos].bt;
		
		p[pos].tat = p[pos].ct - p[pos].at;
		p[pos].wt = p[pos].tat - p[pos].bt;
		p[pos].flag = 1;
		
		c_t = p[pos].ct;
		k = pos;
		++count;
		max = -1;
		idle = 0;
		
		}
		
	for(int m=0;m<=n-1;m++)
	{
		total_tat = total_tat + p[m].tat;
		total_wt = total_wt + p[m].wt;
		}
		
		avg_tat = (double)total_tat/n;
		avg_wt = (double)total_wt/n;

}

void PRIORITY::display()
{
		cout<<"ProcessId  Arrival_Time  Burst_Time  Priority   Complete_Time  TAT_Time  Waiting_Time "<<endl;
		
	for(int j=0;j<=n-1;j++)
		cout<<p[j].pid<<"\t \t"<<p[j].at<<"\t \t"<<p[j].bt<<"\t    "<<p[j].pri_ty<<"\t    "<<p[j].ct<<"\t \t"<<p[j].tat<<"\t \t"<<p[j].wt<<endl;
	
		cout<<"Average Turnaround time :"<<avg_tat<<endl;
		cout<<"Average Waiting Time:" <<avg_wt<<endl;
}


int main()
{
	PRIORITY S;
	S.sorting();
	S.display();
}
	






