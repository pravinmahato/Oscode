#include<iostream>
#include<vector>
using namespace std;

 void fcfs(vector<int>blocksize,vector<int>processsize){
     vector<int>allocation(processsize.size(),-1);
     
for(int i=0; i<processsize.size();i++){
    for(int j=0;j<blocksize.size();j++){
        if(blocksize[j] >= processsize[i]){
            allocation[i] =j;
            allocation[j] -=processsize[i];
            break;
        }
    }
}
cout<<"enter processer";
for(int i=0;i<processsize.size();i++){
    cout<<"process"<<i+1<<":"<<processsize[i]<<"kb->";
    if (allocation[i] != -1)
    cout<<"Block"<<allocation[i] +1<<"\n";
    else
    cout<<"Not allocation";
    
}
 }
 int main(){
     int nBlock,nprocess;
     cout<<"number of memory block\n:";
     cin>>nBlock;
     vector<int>blocksize(nBlock);
     cout<<"enter size of each block\n";
     for(int i=0;i<nBlock;i++){
         cout<<"block:\n"<<i+1;
         cin>>blocksize[i];
     }
     cout<<"number of memory process\n";
     cin>>nprocess;
     vector<int>processsize(nprocess);
     for(int i=0;i<nprocess;i++){
         cout<<"process:\n"<<i+1;
         cin>>processsize[i];
     }
     fcfs(blocksize,processsize);
     return 0;
 }
