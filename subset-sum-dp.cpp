#include <iostream>
#include <cstring>
using namespace std;

int n;
int x[105];
int dp[105][10100];

int rec(int level, int sum_left) {

    // Pruning
    if (sum_left < 0) {
        return 0;
    }

    // Base case
    if (level == n) {
        return sum_left == 0;
    }

    // Already calculated
    if (dp[level][sum_left] != -1) {
        return dp[level][sum_left];
    }

    int ans = 0;

    // Don't take x[level]
    if (rec(level + 1, sum_left) == 1) {
        ans = 1;
    }

    // Take x[level]
    if (rec(level + 1, sum_left - x[level]) == 1) {
        ans = 1;
    }

    return dp[level][sum_left] = ans;
}

void printset(int level, int sum_left){
    if(level == n || sum_left < 0 || sum_left == 0){
        return;
    }

    // find the transition

    if(rec(level+1,sum_left)==1){ //don't take options
        // so we gonna explore this options and not take
        printset(level+1,sum_left);
    } else if(rec(level+1, sum_left-x[level])==1){
        cout<<x[level]<<" ";
        printset(level+1, sum_left-x[level]);
    }


}

void solve() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // Calculate DP once
    memset(dp, -1, sizeof(dp));

    // Different queries
    int q;
    cin >> q;

    while (q--) {
        int target;
        cin >> target;
         cout << "Target " << target << ": ";
        if(target >= 0 && target < 10100 && rec(0,target)){
            printset(0,target);
            cout<<endl;
        } else{
            cout<<"No solution";
        }
    }
}

int main() {
    solve();
}