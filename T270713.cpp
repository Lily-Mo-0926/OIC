#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
int n,a[7],cnt;
ll tot;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=6;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=0;
		cin>>x;
		cnt=(cnt+x)*x;
		if(cnt>=365){
			tot+=a[6];
		}else if(cnt>=120){
			tot+=a[5];
		}else if(cnt>=30){
			tot+=a[4];
		}else if(cnt>=7){
			tot+=a[3];
		}else if(cnt>=3){
			tot+=a[2];
		}else if(cnt>=1){
			tot+=a[1];
		}else{
			tot+=a[0];
		}
	}
	cout<<tot<<endl; 
} 
