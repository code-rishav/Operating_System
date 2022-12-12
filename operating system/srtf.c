#include<stdio.h>
#define nl printf("\n")
#define max 10
typedef struct
{
	int id;
	int btm;
} process;

int main()
{
	process tmp,p[max];
	int n,i,j,tbt,t,btm;

	printf("Enter no. of processes : ");	scanf("%d",&n);
	nl;

	i=0,tbt=0;
	while(i<n)
	{
		nl;
		printf("For process %d",i+1);
		nl;
		printf("Enter burst time : ");		scanf("%d",&btm);
		
		tbt+=btm;

		p[i].id=i+1;
		p[i].btm=btm;
		
		i++;		
	}

        
	i=0,j=i+1;
	while(i<n)
	{
		while(j<n)
		{
			if(p[i].btm > p[j].btm)
			{
				tmp=p[i];
				p[i]=p[j];
				p[j]=tmp;
			}
			j++;
		}
		i++;
		j=i+1;
	}

	printf("\nTime\t\tProcess");
	nl;
	t=i=btm=0;
	j=i+1;
	while(t<tbt)
	{	
		printf("%d\t\t\t%d",t+1,p[btm].id);	p[btm].btm--;
		nl;
		if(p[btm].btm==0)btm++;
		i=btm,j=btm+1;
		while(i<n)
		{
			while(j<n)
			{
				if(p[i].btm > p[j].btm)
				{
					tmp=p[i];
					p[i]=p[j];
					p[j]=tmp;
				}
				j++;
			}
			i++;
			j=i+1;
		}
		t++;
	}
	return 0;
}
