#include<iostream>
#define ll long long
using namespace std;
void prime_sieve(int *p){
    for(ll i=3;i<=1000000;i+=2){
        p[i]=1;
    }
    for(ll i=3;i<=1000000;i+=2){
        if(p[i]==1){
            for(ll j=i*i;j<=1000000;j+=i){
                p[j]=0;
            }
        }
    }
    p[2]=1;
    p[1]=p[0]=0;
    
 }
int main(){
    int p[1000005]={0};
    prime_sieve(p);

    int c[1000005] ={0};
    for(int i=1;i<=1000000;i++){
        c[i]=c[i-1]+p[i];
    }
    int t;
    cin>>t;
    while(t--){
        int b,m;
        cin>>b>>m;
        cout<<c[m]-c[b-1]<<endl;
    }
}
