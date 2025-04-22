//Write a program to implement Banker’s Algorithm for deadlock avoidance.
#include<stdio.h>
#include<stdbool.h>

int main()
int n,m;

printf("enter the number of the process:");
scanf("%d",&n);

printf("enter the number of the resources:");
scanf("%d",&m);

int allocation[n][m],max[n][m],need[n][m],available[m];
bool finish[n];
//input allocation matrix
printf("enter the allocation matrix:\n");
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        scanf("%d",&allocation[i][j]);
    }
}
//input max matrix
 printf("enter the maximum matrix:\n");
 for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
         scanf("%d",&max[i][j]);
     }
 }
//input available resources
printf("enter the available resources:\n");
for(int i=0;i<m;i++){
    scanf("%d", &available[i]);
}
//calculate need matrix
 for(int i=0;i<n;i++){
     finish[i] =false;
     for(j=0;j<m;j++){
     need[i][j] =max[i][j] - allocation[i][j];
     }
 }
 int work[m],safesequence[n],count =0;
 //initialize work = available
  for(int i=0;i<m;i++){
      work[i] = available[i];
  }
  //safe algorithm
  while(count < n){
      bool found =false;
      for(int i=0;i<n;i++){
          if(!finish[i]){
              int j;
              for(j=0;j<m;j++){
                  if(need[i][j] > work[j])
                  break;
              }
              if(j==m){
                  for(int k=0;k<m;k++){
                      work[k] +=allocation[i][k];
                  }
                  safesequence[count++] =i;
                  finish[i] = true;
                  found = true;
              }
          }
      }
      if(!found){
          printf("system is not in a safe state.\n");
          return 0;
      }
      
  }
  //output  safe sequence
   printf("system is in safe state.\nsafe sequence is:");
   for(int i=0;i<n;i++){
       printf("p%d",sequence[i]);
       if(i != n -1) printf(" ->");
       
   }
   printf("\n");
   return 0;
   }
   
