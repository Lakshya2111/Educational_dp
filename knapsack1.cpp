#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,w;
	cin>>n>>w;
	vector<vector<long long>>dp(n+1,vector<long long> (w+1));
  vector<pair<int,int>>weights(n);
  for(int i=0;i<n;i++) {
    int x,y;
    cin>>x>>y;
    weights[i]={x,y};
  }

  for(int i=1;i<n+1;i++){
    for(int j=1;j<w+1;j++){
      dp[i][j]=dp[i-1][j];
      if (j-weights[i-1].first>=0){
        dp[i][j]=max(dp[i][j],dp[i-1][j-weights[i-1].first]+weights[i-1].second);
      }
    }
  }
  cout<<dp[n][w]<<endl;
	return 0;
}
