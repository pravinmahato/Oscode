#include<stdio.h>
#include<stdlib.h>
int abs(int n){
    return n < 0 ? -n : n;
}
void sort(int arr[],int n){
    int i,j,temp;
    for(int i=0;i<n-1;i++){
        for(int j;j<n-i-1;j++){
            if(arr[i] > arr[j + 1]){
                temp =arr[j];
                arr[j] =arr[j+1];
                arr[j + 1] = temp;
            }
        }
    }
}
void fcfs(int data[],int n,int head){
    int movement =0,current=head;
    printf("seek sequence(fcfs):%d",current);
    for(int i=0;i<n;i++){
        movement += abs(current - data[i]);
        current=data[i];
        printf("->%d",current);
    }

printf("movement%d\n",movement);

}
void sstf(int data[],int n,int head){
    int seen[100]={0},movement = 0,current=head;
    printf("seek sequence(sstf):%d",current);
    for(int i=0;i<n;i++){
        
        int index = -1,min = 9999;
        
            for(int j=0;j<n;j++){
                if(!seen[j] && abs(current - data[j]) < min){
                    min =abs(current-data[j]);
                    index=j;
                    
                }
            }
    
            movement += min;
            current=data[index];
            seen[index]=1;
            printf("->%d",current);
    }
    printf("movement %d\n",movement);
    
}
void scan(int data[],int n,int head,int x,int y,int direction){
    int movement=0,current=head;
    sort(data,n);
    
    printf("seek sequence:%d",current);
    if(direction == 1){
        for(int i=0;i<n;i++){
            if(data[i]>=current){
                movement +=abs(current - data[i]);
                current =data[i];
                printf("-> %d",current);
            }
        }
        if(current!=y){
            movement +=abs(current -y);
            current=y;
        }
        for(int i=n-1;i>=0;i--){
            if(data[i]<head){
                movement +=abs(current -data[i]);
                current =data[i];
                printf("-> %d",current);
            }
        }
        
    }else{
        for(int i=n-1;i>0;i--){
            if(data[i] <=current){
                movement +=abs(current - data[i]);
                current =data[i];
                printf("->%d",current);
            }
        }
        if(current!=x){
            movement +=abs(current - x);
            current = x;
        }
        for(int i=0;i<n;i++){
            if(data[i]>head){
                movement +=abs(current -data[i]);
                current =data[i];
                printf("-> %d",current);
            }
        }
    }
    printf("\n Total Head Movement (SCAN):%d\n",movement);
}

int main(){
  int data[100],n,head,direction,x,y;
  printf("enter number of disk request:");
  scanf("%d",&n);
  printf("enter disk request queue:\n");
  for(int i=0;i<n;i++){
   scanf("%d",&data[i]);
  }
  
  printf("Enter initial head position: ");
  scanf("%d",&head);
  
  printf("enter direction(1 for right,0 for left:");
  scanf("%d",&direction);
  
  printf("enter the lower disk");
  scanf("%d",&x);
  
  printf("enter the upper disk");
  scanf("%d",&y);
  
  
  fcfs(data,n,head);
  sstf(data,n,head);
  scan(data,n,head,direction,x,y);
  return 0;
}
