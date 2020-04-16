#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int a=0;
void *func(void *var)
{
	int i;
	for( i=1;i<a;i++)
	{
		int count=0;
		int j;
		for( j=1;j<a;j++)
		{
			if(i%j==0)
			{
				count++;
			}
		}
		if(count==2)
		{
			printf("%d ",i);		
		}

	}
}

int main()
{
	printf("Enter NUmber:- ");
	scanf("%d",&a);
	pthread_t th_id;//initialization of thread variable
	pthread_create(&th_id,NULL,func,NULL);
	pthread_join(th_id,NULL);
	printf("prime number less than equal to your entered number will be printed");
	exit(0);
}
