#include <bits/stdc++.h>
using namespace std;
void BruteForceMethod(){
     int n=5;
    int arr[n]={1,2,3,4,5};
    for(int st=0;st<n;st++){
        for(int end=st;end<n;end++){
            for(int i=st;i<=end;i++){
                cout<<arr[i];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

void SubArray(){
    int n=5;
    int Arr[n]={1,2,3,4,5};
    int maxSum=INT_MIN;
    int st,end,i;
    for ( st = 0; st<n; st++){
        int current__sum=0;
        for ( end =st; end<n; end++){
            current__sum+=Arr[end];
            maxSum=max(current__sum,maxSum);
        }
        
    }
    cout<<"max-sub array"<<" "<<maxSum<<endl;
    
}

//{3,-4,5,4,-1,7,-8}
void Kadanes_algorithoms(){
  int current_sum=0;
  int maxSum=INT_MIN;
  int i;
  int N=7;
  int Arr[N]={3,-4,5,4,-1,7,-8};
  for(i=0;i<N;i++){
    current_sum=current_sum+Arr[i];
    maxSum=max(current_sum,maxSum);
    if(current_sum<0){
        current_sum=0;
    }
  }
  cout<<"MaxSum"<<" "<<maxSum<<endl;
}
vector<int>PairOfSum(vector<int>nums,int target){
    vector<int>ans;
    int n=nums.size();
    int i,j;
    for ( i = 0;i<n; i++){
        for(j=0;j<n;j++){
            if(nums[i]+nums[j]==target){
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                return ans;
            }
        } 
    }
    return ans;
}
vector<int>UsingTwoPointerApproch(vector<int>nums,int target){
    //ps>target
    //ps<<target
    //ps==target
    vector<int>ans;
    int n=nums.size();
    int i=0,j=n-1;
    while(i<j){
       int PairSum=nums[i]+nums[j]; 
       if(PairSum>target){
        j--;
       }else if(PairSum<target){
        i++;
       }else{
        ans.push_back(nums[i]);
        ans.push_back(nums[j]);
        return ans;
       }
    }
}


int main() {
   BruteForceMethod();
   SubArray();
   Kadanes_algorithoms();
   vector<int>nums={2,7,11,15};
   int target=9;
   vector<int>ans=PairOfSum(nums,target);
   cout<<ans[0]<<" "<<ans[1]<<endl;
   vector<int>ans1=UsingTwoPointerApproch(nums,target);
   cout<<ans1[0]<<" "<<ans1[1]<<endl;
}