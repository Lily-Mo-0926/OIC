#include<bits/stdc++.h>
using namespace std;
int n,sum;
int read(){//int read
	int f=1,sum=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){f=-1;}
		c=getchar();
	} 
	while(c>='0'&&c<='9'){
		sum=sum*10+(c-'0');
		c=getchar(); 
	}
	return f*sum;
}
int main(){/*
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);*/
	//cin>>n;
	n=read();
	//cout<<n<<endl;
	for(int i=1,x;i<=n;i++){
		//cin>>x;
		x=read();
	//	cout<<x<<' ';
		sum+=x;
		
	}//cout<<endl;
	cout<<sum;
}
