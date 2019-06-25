#include <stdio.h>
#include<time.h>

void bubblesort(long int arr[],long int n)
{
	long int i,j,temp,flag=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				flag=1;
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
		if(flag==0)
		return;
	}
}

int main () 
{
	
clock_t t; 

  
 FILE *fp;
 FILE *fp2;
 fp2 = fopen("bubble-sort.txt","w");
 fp = fopen("data.txt","r");
 long int n;
 fscanf(fp,"%ld",&n);
 long int arr[n];
 long int i;
 
 for(i=0;i<n;i++)
 {
 	fscanf(fp,"%ld",&arr[i]);
 }
printf("Destination File : bubble-sort.txt\n");
t = clock(); 
bubblesort(arr,n); 
t = clock() - t; 
double time_taken = ((double)t)/CLOCKS_PER_SEC; 
printf("Sorting took %f seconds to execute \n", time_taken); 

 t = clock();
 for(i=0;i<n;i++)
 {
 	fprintf(fp2,"%ld\n",arr[i]);
 }
 t = clock() - t;
 double time_taken2 = ((double)t)/CLOCKS_PER_SEC; 
 printf("Writing took %f seconds to execute \n", time_taken2); 
 fclose(fp);
 fclose(fp2);
 
 return 0;
 
}
