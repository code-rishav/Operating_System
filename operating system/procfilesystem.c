#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int ch;
	int mem;
	printf("1.Print Kernel version");
	printf("\n2.Print CPU info");
	printf("\n3.Print Memory info");
	printf("\nEnter your choice : ");	scanf("%d",&ch);
	
	if(ch==1) 
	{
		printf("\nKernel version\n");
		system("cat /proc/version|awk '{print $1,$2, $3}'");
	}
	else
	{
		if(ch==2)
		{
			printf("\nCPU Type:\n");			
			system("cat /proc/cpuinfo|awk 'NR==3'");// CPU family
			system("cat /proc/cpuinfo|awk 'NR==8'");// CPU MHz
			system("cat /proc/cpuinfo|awk 'NR==13'");//number of cores
			printf("\nCPU Model:\n");
			system("cat /proc/cpuinfo|awk 'NR==5'|awk ' {print $4,$5,$6,$8,$9}'");
		}
		else
		{
			printf("\n\Configured Memory :\n");
			system("cat /proc/meminfo|awk 'NR==1'|awk '{print $2,$3}'");
			printf("\n mem= %d \n",mem);
			printf("\n\Free Memory :\n");
			system("cat /proc/meminfo|awk 'NR==2'|awk ' {print $2,$3}'");
		}
	}
	return 0;
}
