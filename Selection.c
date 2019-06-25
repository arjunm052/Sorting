#include <stdio.h>
#include<time.h>

void swap(long int*,long int*);


void selectionsort(long int arr[],long int n)
{
	long int i,j,min;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			min=j;
		}
		swap(&arr[min],&arr[i]);
	}
}

void swap(long int *x,long int *y)
{
	long 
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main () 
{
	
clock_t t; 

  
 FILE *fp;
 FILE *fp2;
 fp2 = fopen("selection-sort.txt","w");
 fp = fopen("data.txt","r");
 long int n;
 fscanf(fp,"%ld",&n);
 long int arr[n];
 long int i;
 
 for(i=0;i<n;i++)
 {
 	fscanf(fp,"%ld",&arr[i]);
 }
printf("Destination File : selection-sort.txt\n");
t = clock(); 
selectionsort(arr,n); 
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
