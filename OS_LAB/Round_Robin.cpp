#include<iostream>

using namespace std;

struct robin
{
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int flag;
	};

class Round_Robin
{

	public:
	struct robin r[50];
	int n;
	int time;
	double avg_tat,avg_wt;
	int r2[50];

	Round_Robin()
	{
		 cout<<"Enter number of processes:";
		 cin>>n;
		
		cout<<"Enter pid,at,bt:"<<endl;
		
		for(int i=0;i<=n-1;i++)
		{
			cin>>r[i].pid;
			cin>>r[i].at;
			cin>>r[i].bt;
				}
		cout<<"Enter time slice of processes:";
		cin>>time;

		for(int i=0;i<=n-1;i++)
		{
			r[i].flag = 0;		
			r2[i] = r[i].bt;
		}

	}

	void sorting();
	void display();
};



void Round_Robin::sorting()
{
	int i,j,k,c_t;
	struct robin temp;
	int swap;
	int head=-1,tail = -1;
	int q[n],pos,flag2=0;
	int total_tat = 0,total_wt = 0;
	int count = 0,idle = 0;

	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-2-i;j++)
		{
			if(r[j+1].at < r[j].at)
			{
				temp =r[j+1];
				r[j+1] = r[j];
				r[j] = temp;
				}
			else
				{
					if(r[j+1].at == r[j].at && r[j+1].pid < r[j].pid)
					{
						temp = r[j+1];
						r[j+1] = r[j];
						r[j] = temp;
					}
				}
			}
		}
	if(r[0].bt > time)
	{
		r[0].bt = r[0].bt - time;
		r[0].ct = r[0].at + time + idle;
		}
	else
	{
		r[0].ct = r[0].at + r[0].bt + idle;
		r[0].bt = 0;
		r[0].flag = 1;
		++count;
		}

	c_t = r[0].ct;

	q[++head] = 0;
	tail = head;
	
	pos = 0;
	//pre_pro = 0;

	while(count<n)
	{
		
			for(i=pos+1;i<=n-1;i++)
			{
				if(r[i].at<=(c_t) && r[i].flag!=1)
				{
					if(head==-1 && tail==-1)
					{
						q[++tail] = i;
						head = tail;
						pos = i;
						}
					else
					{
						q[++tail] = i;
						pos = i;
						}		
				}			
			}
	cout<<"Pos is "<<pos<<endl;

	cout<<"Before"<<endl;
	cout<<"Head is"<<head<<endl;
		cout<<"Q of Head is"<<q[head]<<endl;
	
		cout<<"Tail :"<<tail<<endl;
		cout<<"Q of tail"<<q[tail]<<endl;

	if(head!=-1)
	swap = q[head];
	

	
	if(head!=tail && flag2!=1)
	{
	for(k=head;k<=tail-1;k++)
		q[k] = q[k+1];
		}

	
	
	if(r[swap].flag!=1  && flag2!=1)
		q[tail] = swap;
	else
	{
		if(flag2!=1)
		{
			tail = tail - 1;
			if(tail==-1)
			head = tail;	
			}	
	}

		cout<<"Head is"<<head<<endl;
		cout<<"Q of Head is"<<q[head]<<endl;
	
		cout<<"Tail :"<<tail<<endl;
		cout<<"Q of tail"<<q[tail]<<endl;

	cout<<"Swap "<<swap<<endl;

	if(r[pos+1].at > (c_t) && head==-1 && pos!=n-1)
	{
		idle = r[pos+1].at - c_t;
		cout<<"Hello"<<endl;
		c_t = c_t + idle;
		flag2 = 1;
		}
	else
		{
			idle =  0;
			flag2 = 0;
			
			}

	cout<<"Flag2"<<flag2<<endl;

	

	if( head!=-1 && r[q[head]].bt > time)
	{
		r[q[head]].bt = r[q[head]].bt - time;
		r[q[head]].ct = c_t + time;
		}
	else
	{	if(head!=-1)
		{
		r[q[head]].ct = c_t + r[q[head]].bt;
		r[q[head]].bt = 0;
		r[q[head]].flag = 1;
		++count;
		}
	}

	if(head!=-1)	
	c_t = r[q[head]].ct;
	cout<<"Completion time is "<<c_t<<endl;

	

	}
	
		for(int i=0;i<=n-1;i++)
			{
			r[i].tat = r[i].ct -  r[i].at;
			total_tat = total_tat + r[i].tat;
			r[i].wt = r[i].tat - r2[i];
			total_wt = total_wt + r[i].wt;
			}	
			
			avg_tat = (double)total_tat /n;
			avg_wt = (double)total_wt/n;			

}

void Round_Robin::display()
{
	cout<<"ProcessId  Arrival_Time  Burst_Time  Complete_Time  TAT_Time  Waiting_Time "<<endl;
	
	for(int j=0;j<=n-1;j++)
		cout<<r[j].pid<<"\t \t"<<r[j].at<<"\t \t"<<r2[j]<<"\t    "<<r[j].ct<<"\t \t"<<r[j].tat<<"\t \t"<<r[j].wt<<endl;
	cout<<"Average Turn Around Time  "<<avg_tat<<endl;
	cout<<"Average Waiting Time  "<<avg_wt<<endl;
}

int main()
{
	Round_Robin R;
	R.sorting();
	R.display();

	}























