#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int r=n*(n-1)/2;
        if(k>=r){
            cout<<1<<endl;
          
        }
        else if(k>=n-1){
            cout<<1<<endl;
            
        }
        else{
            cout<<n<<endl;
        }
    }
}