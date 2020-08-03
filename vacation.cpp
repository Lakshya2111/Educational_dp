#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>happy(n,vector<int>(3));
    for(int i=0;i<n;i++)for(int j=0;j<3;j++) cin>>happy[i][j];
    vector<vector<int>>dp(n+1,vector<int>(3));
	for(int i=0;i<n;i++){
		dp[i+1][0]=max(dp[i][1]+happy[i][1],dp[i][2]+happy[i][2]);
		dp[i+1][1]=max(dp[i][0]+happy[i][0],dp[i][2]+happy[i][2]);
		dp[i+1][2]=max(dp[i][0]+happy[i][0],dp[i][1]+happy[i][1]);
	}
	cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;;


    return 0;
}
