
#include<iostream>

using namespace std;

struct priority_pe
{
	int pid;
	int at;
	int bt;
	int priority;
	int ct;
	int tat;
	int wt;
	int flag;
};

class PRIORITY_PE
{
	public:
		int n;
		struct priority_pe p[50];
		double avg_tat,avg_wt;
		int p2[50];
		
		PRIORITY_PE()
		{
			cout<<"Enter number of processes :";
			cin>>n;
			
			cout<<"Enter the pid, arrival time (in queue), burst time, priority"<<endl;
			
			for(int i=0;i<=n-1;i++)
			{
				cin>>p[i].pid;
				cin>>p[i].at;
				cin>>p[i].bt;
				cin>>p[i].priority;
			}
			//cout<<"Hello"<<endl;
			
			for(int i=0;i<=n-1;i++)
			{
				p[i].flag = 0;
				p2[i] = p[i].bt;
				}
		}
		
	void sorting();
	void display();
		
		
};

void PRIORITY_PE::sorting()
{
	
	struct priority_pe temp;
	int k,count=0;
	int max = -1;
	int pos = -1;
	int c_t,total_tat = 0,total_wt = 0;
	int idle = 0;
	int m = n;
	int o = n-1;

	
	for(int i=0;i<=m-1;i++)
	{
		for(int j=0;j<=m-2-i;j++)
		{
			if(p[j+1].at < p[j].at)
			{
				temp =p[j+1];
				p[j+1] = p[j];
				p[j] = temp;
				}
			else
				{
					if(p[j+1].at == p[j].at && p[j+1].priority < p[j].priority)
					{
						temp = p[j+1];
						p[j+1] = p[j];
						p[j] = temp;
					}
				}
			}
		}
		
		k = 0;
		--p[k].bt;
		
		if(p[k].bt==0)
		{
			p[k].flag = 1;
			++count;
		}
		
		p[k].ct = p[k].at + 1;
		c_t = p[k].ct;
	//cout<<"Value of m before while is "<<m<<endl;
	
	while(count<m)
		{
			for(int i=0;i<=m-1;i++)
			{
				if(p[i].at<=(c_t+idle) && p[i].flag!=1 && max < p[i].priority)
				{
					max = p[i].priority;
					pos = i;
				}
				
			}	
				
				if((c_t+idle) >= p[n-1].at)
				{
					p[pos].ct = c_t + p[pos].bt + idle;
					p[pos].bt = 0;
					++count;
					p[pos].flag = 1;
				}
				else
				{	
					if(pos!=-1)
					{
					--p[pos].bt;
					p[pos].ct = c_t + 1 + idle;
					if(p[pos].bt == 0)
					{
						++count;
						p[pos].flag = 1;
						}	
							}
				}
				
					
					if(pos==-1)
					    {
						  idle = p[k+1].at - p[k].ct;
							}
					else
						idle = 0;
						
					c_t = p[pos].ct;
					k = pos;
					max = -1; 
					pos = -1;
				
				
		}
		
		//cout<<"After while loop"<<m<<endl;
		//cout<<"after while n is "<<n<<endl;
		
		//display();
				
		for(int i=0;i<=m-1;i++)
		{
			p[i].tat = p[i].ct - p[i].at;
			p[i].wt = p[i].tat - p2[i];
			total_tat = total_tat + p[i].tat;
			total_wt = total_wt + p[i].wt;
			
			}
		avg_tat = (double)total_tat/m;
		avg_wt = (double)total_wt/m;
			
		
		
}

void PRIORITY_PE::display()
{
	//cout<<"Value of n in display is"<<n<<endl;
	cout<<"ProcessId  Arrival_Time  Burst_Time  Complete_Time  TAT_Time  Waiting_Time "<<endl;
	
	for(int j=0;j<=n-1;j++)
		cout<<p[j].pid<<"\t \t"<<p[j].at<<"\t \t"<<p2[j]<<"\t    "<<p[j].priority<<"\t"<<p[j].ct<<"\t \t"<<p[j].tat<<"\t \t"<<p[j].wt<<endl;
		
	cout<<"Average Turn Around Time  "<<avg_tat<<endl;
	cout<<"Average Waiting Time  "<<avg_wt<<endl;
}
	
int main()
{
	PRIORITY_PE P;
	P.sorting();
	P.display();
	
}




