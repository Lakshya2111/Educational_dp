#include<bits/stdc++.h>
using namespace std;

const long long INF=1e18l+5;
int main(){
	int n,w;
	cin>>n>>w;
  vector<int>weights(n);
  vector<int>values(n);
  int sum_ans=0;
  for(int i=0;i<n;i++) {
    cin>>weights[i]>>values[i];
    sum_ans+=values[i];
  }
  vector<long long>dp(sum_ans+1,INF);
  dp[0]=0;
  for(int i=0;i<n;i++){
    for(int j=sum_ans-values[i];j>=0;j--){
      dp[j+values[i]]=min(dp[j+values[i]],dp[j]+weights[i]);
    }
  }

  int ans=0;
  for(int i=0;i<=sum_ans;i++){
    if(dp[i]<=w) ans=max(ans,i);
  }
  cout<<ans<<endl;
	return 0;
}
