#include<iostream>
#include<vector>
using namespace std;

#define MAX 50

void printframe(vector<int>&frames,int f){
    for(int i=0;i<f;i++){
        if(frames[i] == -1)
        cout<<"-";
        else
           cout<<" "<<frames[i]<<"";
    }
    cout<<endl;
}
//FcFC algorithm
void fcfs(vector<int>&pages,int f,int n){
    vector<int>frames(f,-1);
        int faults=0,k=0;
        cout<<"nfcfs page replacement:\n";
        
        for(int i=0;i<n;i++){
            bool found=false;
            for(int j=0;j<f;j++){
                if(frames[j] == pages[i]){
                    found = true;
                    break;
                }
            }
            if(!found){
                frames[k] =pages[i];
                k=(k+1) %f;
                faults++;
            }
            printframe(frames,f);
            
        }
        cout<<"total page faults:"<<faults<<endl;
        
}
int main() {
     int f,n;
     cout<<"enter the number of page";
     cin>>n;
     
     vector<int>pages(n);
     cout<<"enter the page reference string\n";
     for(int i=0;i<n;i++){
         cin>>pages[i];
     }
     cout<<"enter the number of frames:";
     cin>>f;
     
    fcfs(pages,n,f);
    
    return 0;
}
