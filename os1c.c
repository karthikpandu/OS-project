#include<stdio.h>
 
int main()
{
    int bt[20],p[20],wa_t[20],ta_t[20],pr[20],i,j,n,total=0,pos,temp,t,avg_wa_t,avg_ta_t;
    printf("Enter Number of Process:");
    scanf("%d",&n);
    printf("Enter the quantum time");
    scanf("%d",&t);
 
    printf("\nEnter Burst Time and Priority of the respective process\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;           //contains the process number
    }
 
    //sorting burst time, priority and process number in ascending order using selection sort
     for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
	
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
	}
 
    wa_t[0]=0;	//waiting time for first process is zero
 
    //calculation of waiting time
    for(i=1;i<n;i++)
    {
        wa_t[i]=0;
        for(j=0;j<i;j++)
            wa_t[i]+=bt[j];
 
        total+=wa_t[i];
    }
 
    avg_wa_t=total/n;      //average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        ta_t[i]=bt[i]+wa_t[i];     //calculate turnaround time
        total+=ta_t[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wa_t[i],ta_t[i]);
    }
 
    avg_ta_t=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wa_t);
    printf("\nAverage Turnaround Time=%d\n",avg_ta_t);
 
	return 0;
}
