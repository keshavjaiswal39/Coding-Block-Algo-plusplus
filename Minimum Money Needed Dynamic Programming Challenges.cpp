#include <bits/stdc++.h>
using namespace std;
int arr[1005];
int val[1005];
int dp[1005][1005];

int min_money(int n,int w){
    if(w==0){
        return 0;
    }
    if(n==-1){
        return 1000;
    }

    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    if(val[n]==-1){
        return min_money(n-1,w);
    }

    int a=INT_MAX,b=INT_MAX;
    if(w>=arr[n]){
        a=val[n]+min_money(n,w-arr[n]);
    }
    b=min_money(n-1,w);
    dp[n][w]=min(a,b);
    return dp[n][w];
}

int main() {
    int n,w;
    cin>>n>>w;
    for(int i=0;i<w;i++){
        arr[i]=i+1;
    }
    for(int i=0;i<w;i++){
        cin>>val[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<min_money(w-1,w)<<'\n';
    return 0;
}

