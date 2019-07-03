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

int main (int argc,char *argv[]) 
{
	
clock_t t; 

  
 FILE *fp;
 FILE *fp2;
 
 fp = fopen(argv[1],"r");
 fp2 = fopen(argv[2],"w");
 
 long int count = 0;
 char c;

 c = getc(fp);

    // Extract characters from file and store in character c 
    for (c = getc(fp); c != EOF; c = getc(fp)) 
        if (c == '\n') // Increment count if this character is newline 
            count = count + 1;

rewind(fp);		

printf("Linecount: %d\n",count);
 long int size = count;
 long int arr[size];
 long int i;
 
 for(i=0;i<size;i++)
 {
 	fscanf(fp,"%ld",&arr[i]);
 }
 
printf("Destination File : %s\n",argv[2]);
t = clock(); 
selectionsort(arr,size); 	
t = clock() - t; 
double time_taken = ((double)t)/CLOCKS_PER_SEC; 
printf("Sorting took %f seconds to execute \n", time_taken); 

 t = clock();
 
 for(i=0;i<size;i++)
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
