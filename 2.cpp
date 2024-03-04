#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=200002;
int n;
long double ans;
long double a[maxn],b[maxn],s[maxn];
bool check(long double now)
{
	long double tmp=0;
	for(int i=1;i<=n;i++)
	{
		tmp=max(a[i],tmp+s[i]/now);
		if(tmp>b[i]) return false;
	}
	return true;
}
signed main()
{
	scanf("%lld",&n);
	long double l=1e9+7,r=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%Lf%Lf%Lf",&a[i],&b[i],&s[i]);
		l=min(l,s[i]/(a[i]-b[i-1]));
		r=max(r,s[i]/(a[i]-b[i-1]));
	}
	l=0,r=1e9+7;
	while(abs(l-r)>=0.000001)
	{
		long double mid=(l+r)/2;
		if(check(mid)==true) { r=mid; ans=mid; }
		else l=mid;
		//printf("%lf %lf %lf\n",l,r,mid);
	}
	printf("%.2Lf",ans);
	return 0;
}