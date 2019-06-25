#include <stdio.h>
#include<time.h>

void insertionsort(long int arr[],long int n)
{
long int i,key,j;
for(i=1;i<n;i++)
	{
	key=arr[i];
	j=i-1;
	
	while(j>=0 && arr[j]>key)
	{
		arr[j+1]=arr[j];
		j=j-1;
	}
	arr[j+1]=key;
	}	
}

int main () 
{
	
clock_t t; 

  
 FILE *fp;
 FILE *fp2;
 fp2 = fopen("insertion-sort.txt","w");
 fp = fopen("data.txt","r");
 long int n;
 fscanf(fp,"%ld",&n);
 long int arr[n];
 long int i;
 
 for(i=0;i<n;i++)
 {
 	fscanf(fp,"%ld",&arr[i]);
 }
printf("Destination File : insertion-sort.txt\n");
t = clock(); 
insertionsort(arr,n); 
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
