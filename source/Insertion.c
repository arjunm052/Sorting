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
 
 long int arr[count];
 long int i;
 
 for(i=0;i<count;i++)
 {
 	fscanf(fp,"%ld",&arr[i]);
 }
 
printf("Destination File: %s\n",argv[2]);
t = clock(); 
insertionsort(arr,count); 	
t = clock() - t; 
double time_taken = ((double)t)/CLOCKS_PER_SEC; 
printf("Sorting took %f seconds to execute \n", time_taken); 

 t = clock();
 
 for(i=0;i<count;i++)
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
