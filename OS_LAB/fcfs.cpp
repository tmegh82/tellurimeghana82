#include<iostream>

using namespace std;

	struct fcfs
	{
		int pid;
		int at;
		int bt;
		int tat;
		int wt;
		int ct;
		};

class FCFS
{
	public:
	int i;	
	fcfs f[50];
	void input();
	void find_avgturnaroundtime();
	void find_avgwaitingtime();
	void display();
	void sequence();
	double avg_tat;
	double avg_wt;
};



void FCFS::input()
{
	i = -1;
	int k = 1;
	
	
	while(k!=0)
	{
		++i;
		cout<<"Enter the pid, arrival time (in queue), burst time:"<<endl;
		cin>>f[i].pid;
		cin>>f[i].at;
		cin>>f[i].bt;
		cout<<"Enter 1 for entering a process and 0 for termination:"<<endl;
		cin>>k;	
	}
}

void FCFS::sequence()
{
	struct fcfs temp;
	for(int k=0; k<=i;k++)
		{
		 for(int j=0;j<i-k;j++)
			
		if(f[j+1].at < f[j].at)
		   {
		   	temp = f[j];
		   	f[j] = f[j+1];
		   	f[j+1] = temp;
		   		}
		else 
			{
			if(f[j].at==f[j+1].at)
			{
				if(f[j].pid > f[j+1].pid)
				{
				
				temp = f[j];
				f[j] = f[j+1];
				f[j+1] = temp;
					}
				}
			}
		}
	}

void FCFS::find_avgturnaroundtime()
{
	int idle;
	
		f[0].ct = f[0].at + f[0].bt;
		f[0].tat = f[0].ct - f[0].at;
		int	total_tat = f[0].tat;
		
	for(int j=1;j<=i;j++)
	{
		if(f[j].at>f[j-1].ct)
		{
				idle = f[j].at-f[j-1].ct;
				f[j].ct = f[j-1].ct + f[j].bt+idle;	  
			}
		else
		f[j].ct = f[j-1].ct + f[j].bt;
	
		f[j].tat = f[j].ct - f[j].at;
		total_tat = total_tat + f[j].tat;
		}
		
	avg_tat = (double)total_tat/(i+1);
	
}

void FCFS::find_avgwaitingtime()
{
	
		int	total_wt = 0;
		
	for(int j=0;j<=i;j++)
	{
		f[j].wt = f[j].tat - f[j].bt;
		total_wt = total_wt + f[j].wt;
		}
		
	avg_wt = (double)total_wt/(i+1);
	
}

void FCFS::display()
{
	cout<<"ProcessId  Arrival_Time  Burst_Time  Complete_Time  TAT_Time  Waiting_Time "<<endl;
	
	for(int j=0;j<=i;j++)
	cout<<f[j].pid<<"\t \t"<<f[j].at<<"\t \t"<<f[j].bt<<"\t    "<<f[j].ct<<"\t \t"<<f[j].tat<<"\t \t"<<f[j].wt<<endl;
	cout<<"Average Turn Around Time  "<<avg_tat<<endl;
	cout<<"Average Waiting Time  "<<avg_wt<<endl;
}


int main()
{
	FCFS f;
	f.input();
	f.sequence();
	f.find_avgturnaroundtime();
	f.find_avgwaitingtime();
	f.display();
}
