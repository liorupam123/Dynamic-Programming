// Recursion -> T.C == O(2^n)(Exponential)
// S.C == O(n) --> Recursion Stack Space
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int fibo(int n){
	if(n<=1)	return n;
	return fibo(n-1)+fibo(n-2);
}

int main() {
	int n;	cin>>n;
	cout<<fibo(n);

	return 0;
}

// memoization -> T.C == O(n)
// S.C == O(n) + O(n) --> Recursion Stack Space + dp vector/array
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int fibo(int n,vector<int> &dp){
	if(n<=1)	return n;
	if(dp[n]!=-1)	return dp[n];
	return dp[n] = fibo(n-1,dp)+fibo(n-2,dp);
}

int main() {
	int n;	cin>>n;
	vector<int> dp(n+1,-1);
	// int arr[n+1];
	// memset(arr,-1,sizeof arr);
	cout<<fibo(n,dp);

	return 0;
}

// Tabulation -> T.C == O(n)
// S.C == O(n) --> dp vector/array
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;	cin>>n;
	int dp[n+1];
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	cout<<dp[n];

	return 0;
}

// Space optimisation -> T.C == O(n)
// S.C == O(1)
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;	cin>>n;
	int prev2=0;
	int prev=1;
	for(int i=2;i<=n;i++){
		int curr = prev+prev2;
		prev2=prev;
		prev=curr;
	}
	cout<<prev;

	return 0;
}
