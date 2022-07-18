// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

int lrs(string s1,int i,int j, vector<vector<int>>&dp){

	// return if we have reached the
	//end of either string
	if(i >= s1.length() || j >= s1.length())
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];
	
	// while dp[i][j] is not computed earlier
	if(dp[i][j] == -1){
	
		// if characters at index m and n matches
		// and index is different
		// Index should not match
		if(s1[i] == s1[j] && i != j)
			dp[i][j] = 1+lrs(s1, i+1, j+1, dp);
		
		// else if characters at index m and n don't match
		else
			dp[i][j] = max(lrs(s1, i, j+1, dp),
								lrs(s1, i+1, j, dp));
	}
	
	// return answer
	return dp[i][j];
}

// Driver Code
int main(){

string s1 = "aabb";
	
// Reversing the same string
string s2 = s1;
reverse(s2.begin(),s2.end());
vector<vector<int>>dp(1000,vector<int>(1000,-1));
cout<<"LENGTH OF LONGEST REPEATING SUBSEQUENCE IS : "<<lrs(s1, 0, 0, dp);

}

// This code is contributed by shinjanpatra
