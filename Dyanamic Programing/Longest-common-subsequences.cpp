#include<bits/stdc++.h>
using namespace std;

//for sublime to take input and output
void sublimestarter()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

// function for finding lcs
int lcs(string a,string b,int n,int m)
{
	    /*
    We create a 2D vector containing "n+1"
    elements each having the value "vector<int> (m+1, 0)".
    "vector<int> (m+1, 0)" means a vector having "m"
    elements each of value "0".
    Here these elements are vectors.
    */

	vector<vector<int>> dp(n+1,vector<int> (m+1,0));

	for (int i = 1; i<=n; ++i)
	{
		for (int j = 1; j<=m; ++j)
		{
			if(a[i-1]==b[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}	
		}
	}
	return dp[n][m];
}
int main()
{
	sublimestarter();

	//taking string A ana string B as input

	string a;
	string b;

	cin>>a>>b;

	//finding the length of string() 
	int l1=a.length();
	int l2=b.length();

	//calling function lcs

	cout<<"longest common subsequence :- "<<lcs(a,b,l1,l2);
	return 0;
}

