#include<bits/stdc++.h>
using namespace std;
float a,b,c,p,s;
int main(){
	cin>>a>>b>>c;
	p=0.5*(a+b+c);
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.1lf",s);
} 
