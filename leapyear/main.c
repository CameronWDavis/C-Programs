#include<stdio.h>
int main()
{
    int year, sum=0;
    printf("Enter a year:");
    scanf("%d",&year);
    if(year%4==0)
	{
		if(year%100==0)
		{
			if(year%400==0){


				printf("%d is a leap year.\n", year);

			    while(year!=0){
				    sum=sum+(year%10);
				    year=year/10;
			    }
				printf("%d", sum);
			}
			else
				printf("%d is not a leap year.\n", year);
		}
		else{
			printf("%d is a leap year.\n", year);
		    while(year!=0){
				    sum=sum+(year%10);
			    	year=year/10;
		    }
			printf("Sum of digits is: %d\n", sum);
	    }
	}
	else
		printf("%d is not a leap year.\n", year);
	return 0;
}
