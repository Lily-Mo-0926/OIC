#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,t,ty[N];
long long ans,tot[30][30][N],cnt[N],a[N];
char s[N];
/*我们说一个串是奇异的当且仅当它的所有子序列在原串中都能找到一模一样的子串
性质：一个串的子序列集合一定包含它的所有子串 

奇异字串判定：
0.单字母是奇异字串 
1.完全由一种字符构成的字符串是奇异字串
2.由两个 符合判定1的字串 拼接成的字串是奇异字串 
3.由两个 符合判定1的字串 中间夹1个0 的字串是奇异字串 
*/
int main(){
    freopen("strange.in","r",stdin);
    freopen("strange.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]!=s[i-1]) ty[++t]=s[i]-'a';
        cnt[t]++;
	}//ty[]用于分块，每个元素表示有cnt[i]个相同的字母t[i]排列在一块（判定0，1） 
	for(int i=1;i<=t;i++){
		a[ty[i]]=max(a[ty[i]],cnt[i]);//（判定0，1）
		for(int j=1;j<=cnt[i];j++){
			tot[ty[i-1]][ty[i]][j]=max(tot[ty[i-1]][ty[i]][j],cnt[i-1]);//某个dp 判定2,3 
		}
	}
	for(int i=0;i<26;i++){//拢共可能有26个字母 
		ans+=a[i];//判定1 
		for(int j=0;j<26;j++){
			if(i==j) continue;//防止退回判定1导致重复统计 
			for(int k=1;k<=n;k++) ans+=tot[i][j][k];//判定2,3累加 
		}
	}
	printf("%lld\n",ans);
	return 0;
}

