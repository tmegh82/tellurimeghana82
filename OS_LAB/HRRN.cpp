#include<iostream>

using namespace std;

struct hrrn
{
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int flag;
};

class HRRN
{
	public:
		int n;
		struct hrrn h[50];
		double avg_tat,avg_wt;
		//int s2[50];
		
		HRRN()
		{
			cout<<"Enter number of processes:";
			cin>>n;
			
			cout<<"Enter pid,at,bt:"<<endl;
			
			for(int i=0;i<=n-1;i++)
			{
				cin>>h[i].pid;
				cin>>h[i].at;
				cin>>h[i].bt;
			}
			for(int i=0;i<=n-1;i++)
			{
			h[i].flag = 0;
			//s2[i] = s[i].bt;
				}
		}
		
	void sorting();
	void display();
		
};


void HRRN::sorting()
{
	int i,j,k,count = 0,idle = 0;
	int total_tat= 0,total_wt=0;
	int pos = -1,c_t;
	double rr,ws;
	struct hrrn temp;

	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-2-i;j++)
		{
			if(h[j+1].at < h[j].at)
			{
				temp =h[j+1];
				h[j+1] = h[j];
				h[j] = temp;
				}
			/*else
				{
					if(h[j+1].at == h[j].at && h[j+1].bt < h[j].bt)
					{
						temp = h[j+1];
						h[j+1] = h[j];
						h[j] = temp;
					}
				}*/
			}
		}

	h[0].ct = h[0].at + h[0].bt;
	c_t = h[0].ct;
	h[0].flag = 1;
	++count;
	k = 0;
	double  max = -1.0;
//	cout<<"Hello"<<endl;

	while(count<n)
	{
	for(i=0;i<=n-1;i++)
	{
		if(h[i].at<=(c_t + idle) && h[i].flag!=1)
		{
			ws  = double((c_t + idle) - h[i].at)/(h[i].bt);

			rr = 1 + ws;
			if(max < rr)
			{
				max = rr;
				pos = i;	
				}			
			}		

		}
	
//	cout<<"Pos is "<<pos<<endl;

	

	if(pos==-1)
		idle = h[k+1].at - c_t;
	else
		{
			h[pos].ct = h[pos].bt + c_t + idle;
			h[pos].flag =1;	
			++count;
			idle = 0;
			c_t = h[pos].ct;
			}	
	
//	cout<<"Ideal is"<<idle<<endl;
	k = pos;
	pos = -1;
	max = -1.0;
  

	}

	for(i=0;i<=n-1;i++)
	{
		h[i].tat = h[i].ct -  h[i].at;
		total_tat = total_tat + h[i].tat;
		h[i].wt = h[i].tat - h[i].bt;
		total_wt = total_wt + h[i].wt;
			}	
			
		avg_tat = (double)total_tat /n;
		avg_wt = (double)total_wt/n;

}

void HRRN::display()
{
	cout<<"ProcessId  Arrival_Time  Burst_Time  Complete_Time  TAT_Time  Waiting_Time "<<endl;
	
	for(int j=0;j<=n-1;j++)
		cout<<h[j].pid<<"\t \t"<<h[j].at<<"\t \t"<<h[j].bt<<"\t    "<<h[j].ct<<"\t \t"<<h[j].tat<<"\t \t"<<h[j].wt<<endl;
	cout<<"Average Turn Around Time  "<<avg_tat<<endl;
	cout<<"Average Waiting Time  "<<avg_wt<<endl;
}





int main()
{
	HRRN H;
	H.sorting();
	H.display();

	}

