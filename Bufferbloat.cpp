#include<stdio.h>
int checkbuffer(int n,int max,int z)
{

int count1=0;
int f = max-100;
if(n<f)
{
	printf("No bufferbloat,low latency\n");
	
}
else if((n>=max-100)&&(n<=max))
{
	printf("Bufferbloat,high latency\n");
	count1++;
}
else if(n>max)
{
	printf("Buffer capacity overloaded\n");
}
return count1;
}
int main()
{
	int a[20],b[20],c[20],d[20],la,lb,lc,ld,max,select,h,ha,hb,hc,hd;
	int s[20],temp,buffer[20],g[20];
	int pa=0,pb=0,pc=0,pd=0,n=0;
	int p=0,q=0,r=0,t=0,asum=0,bsum=0,csum=0,dsum=0,i=0,j=0,k=0;
	printf("Enter no of packets for queue 1\n");
	scanf("%d",&la);
	printf("Enter number of bits for each packet\n");
	for(i=0;i<la;i++)
	{
		scanf("%d",&a[i]);
		asum = asum + a[i];
	}
	s[0]=asum;
	printf("Enter no of packets for queue 2\n");
	scanf("%d",&lb);
	printf("Enter number of bits for each packet\n");
	for(i=0;i<lb;i++)
	{
		scanf("%d",&b[i]);
		bsum = bsum + b[i];
	}
	s[1]=bsum;
	printf("Enter no of packets for queue 3\n");
	scanf("%d",&lc);
	printf("Enter number of bits for each packet\n");
	for(i=0;i<lc;i++)
	{
		scanf("%d",&c[i]);
		csum = csum + c[i];
	}
	s[2]=csum;
	printf("Enter no of packets for queue 4\n");
	scanf("%d",&ld);
	printf("Enter number of bits for each packet\n");
	for(i=0;i<ld;i++)
	{
		scanf("%d",&d[i]);
		dsum = dsum + d[i];
	}
	s[3]=dsum;
	printf("Enter the maximum capacity of buffer\n");
	scanf("%d",&max);
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<4;j++)
		{
			if(s[i]>=s[j])
			{
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
	i=0;
	for(i=0;i<4;i++)
	{
		if(s[i]==asum)
		{
			pa = i+1;
			g[0]=pa;
		}
	}
	i=0;
	for(i=0;i<4;i++)
	{
		if(s[i]==bsum)
		{
			pb = i+1;
			g[1]=pb;
		}
	}
	i=0;
	for(i=0;i<4;i++)
	{
		if(s[i]==csum)
		{
			pc = i+1;
			g[2]=pc;
		}
	}
	i=0;
	for(i=0;i<4;i++)
	{
		if(s[i]==dsum)
		{
			pd = i+1;
			g[3]=pd;
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<4;j++)
		{
			if(g[i]==g[j])
			{
				g[j]=g[j]-1;
			}
		}
	}
	
	
	printf("priority of queue a = %d\n priority of queue b =%d\n priority of queue c=%d\n priority of queue d=%d\n",g[0],g[1],g[2],g[3]);
	for(k=0;k<4;k++)
	{   
		printf("Enter priority number\n");
		scanf("%d",&select);
		if(select==g[0])
		{
			for(p=0;p<la;p++)
			{
				buffer[p] = a[p];
				
			}	
		
			for(i=0;i<la;i++)
			{
			
				printf("|%d|\t",buffer[i]);
			}
		ha = checkbuffer(asum,max,la);
			
		}
		else if(select==g[1])
		{
			for(q=0;q<lb;q++)
			{
				buffer[q] = b[q];
				
			}
			for(i=0;i<lb;i++)
			{
				printf("|%d|\t",buffer[i]);
			}
			hb =checkbuffer(bsum,max,lb);
		}
		else if(select==g[2])
		{
			for(r=0;r<lc;r++)
			{
				buffer[r] = c[r];
				
			}
			for(i=0;i<lc;i++)
			{
				printf("|%d|\t",buffer[i]);
			}
			hc =checkbuffer(csum,max,lc);
		}
		else if(select==g[3])
		{
			for(t=0;t<ld;t++)
			{
				buffer[t] = d[t];
				
			}
			
			for(i=0;i<ld;i++)
			{
				printf("|%d|\t",buffer[i]);
			}
			hd = checkbuffer(dsum,max,ld);
		}
		else
		{
			printf("Invalid input");
		}
		
	}
	h = ha+hb+hc+hd;
	printf("Number of times bufferbloat occured %d",h);

}
