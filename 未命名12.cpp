#include<iostream>
int n,cnt;
unsigned long long k;
int main(){
   	std::cin>>n>>k;
    k^=k>>1;
    std::cout<<k<<std::endl;
    while(~--n)cnt++,std::cout<<(k>>n&1);
    std::cout<<std::endl<<cnt;
}

