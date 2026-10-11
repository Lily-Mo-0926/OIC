#include<bits/stdc++.h>
using namespace std;
#define int long long
//im going to write something that going to be bufenfenÈ»¶øACÁË 
int n,a,b,w,h;
bool check(int x){
    int u=a+2*x,v=b+2*x,cnt=0;
    //hengpai-> u:w v:h
    cnt=max(cnt,(w/u)*(h/v));
    //shupai -> u:h v:w
    cnt=max(cnt,(h/u)*(w/v));
    return cnt>=n;
}
void File(string s){
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
signed main(){
    File("settle");
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>a>>b>>w>>h;
    int l=0,r=1e18;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)){
            l=mid;
        }else{r=mid-1;}
    }
    cout<<l;
}

