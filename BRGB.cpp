#include<bits/stdc++.h>
using namespace std;
string s;
int m,n,lg,ng;
int ls[2525],rs[2525],l[2525],r[2525];
long long a[2525][2525],ans,suf,t1,t2,t3,sum; 
int main(){
	cin>>s>>m;
	n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++){
		ls[i]=(s[i]=='G')?ls[i-1]+1:0;
	}for(int i=n;i>=1;i--){
		rs[i]=(s[i]=='G')?rs[i+1]+1:0;
	} 
	for(int i=1;i<=n;i++){
		if(ls[i]>=m)lg=i-m+1;
		l[i]=lg;
	}
	ng=n+1;
	for(int i=n;i>=1;i--){
		if(rs[i]>=m)ng=i+m-1;
		r[i]=ng;
	} 
	for(int c=1;c<=n;c++){
		int de=r[c]-1;
		int ld=de-c+1;
		if(ld<=0)continue;
		int maxy=min({rs[c],ld,m-1});
		if(maxy==0)continue;
		for(int k=1;k<=m;k++){
			suf=(k<=maxy)?(ld-k+1):0;
			a[c][k]=a[c][k-1]+suf;
		}
	}
	for(int b=1;b<=n;b++){
		for(int c=b+1;c<=n;c++){
			t1=1ll*l[b]*(n-c+1);
			t2=1ll*b*(n-r[c]+1);
			t3=1ll*l[b]*(n-r[c]+1);
			sum=0;
			int at=l[b]+1;
			int la=b-at+1;
			if(la>0){
				int maxx=min({ls[b],la,m-1});
				if(maxx>0){
					if(m-maxx+1<=m-1){
						sum+=a[c][m-1]-a[c][m-maxx];
					}
					int k=m-maxx;
					long long sk=(k>=1)?(a[c][k]-a[c][k-1]):0;
					sum+=1ll*(la-maxx+1)*sk;
				}
			}
			ans+=t1+t2-t3+sum;
		}
	}
	cout<<ans<<endl;
} 
