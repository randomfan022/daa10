#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
void heapBottomUp(int a[],int n) 
{ 
 int i,heap,k,j,v; 
 for(i=n/2;i>=0;i--) 
 { 
 k=i; 
 v=a[k]; 
 heap=0; 
 while(!heap && (2*k)<=n) 
 { 
 j=2*k; 
 if(j<n) 
 if(a[j]<a[j+1]) 
 j=j+1; 
 if(v>=a[j]) 
 heap=1; 
 else 
 { 
 a[k]=a[j]; 
 k=j; 
 a[k]=v; 
 } 
 
 } 
 } 
} 
void heapsort(int a[],int n) 
{ 
 int last=n,i,temp; 
 if(n<=1) 
 return ; 
 else 
 { 
 heapBottomUp(a,n); 
 temp=a[last]; 
 a[last]=a[1]; 
 a[1]=temp; 
 last--; 
 heapsort(a,n-1); 
 } 
} 
void main() 
{ 
 int a[1000],i,n; 
 double clk; 
 clock_t start,end; 
 
 printf("ENTER N\n"); 
 scanf("%d",&n); 
 
 for(i=1;i<=n;i++) 
 a[i]=rand()%100; 
 
 printf("ARRAY ELEMENTS ARE\n"); 
 for(i=1;i<=n;i++) 
 printf("%d ",a[i]); 
 
 printf("\n"); 
 
 start=clock(); 
 heapsort(a,n); 
 end=clock(); 
 
 printf("SORTED ARRAY IS\n"); 
 for(i=1;i<=n;i++) 
 printf("%d ",a[i]); 
 
 printf("\n"); 
 
 clk=(double)(end-start)/CLOCKS_PER_SEC; 
 
 printf("TIME REQUIRED IS:%f\n",clk); 
 
} 
