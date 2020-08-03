#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int>h(n);
	for(int i=0;i<n;i++) cin>>h[i];
	vector<int> dp(n,INT_MAX);
	dp[0]=0;
	// dp[1]=abs(h[0]-h[1]);
	for(int i=1;i<n;i++){
		for(int j=i-1;j>max(i-k-1,-1);j--){
			dp[i]=min(dp[j]+abs(h[i]-h[j]),dp[i]);
		}
	}
	cout<<dp.back()<<endl;


	return 0;
}
