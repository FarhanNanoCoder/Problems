#include <bits/stdc++.h>
using namespace std;
int noOfPainters(vector<int> &boards, int d) {
  int c = 1;
  int sum = 0;
  for (int i = 0; i < boards.size(); i++) {
    if (sum + boards[i] <= d) {
      sum += boards[i];
    } else {
      c++;
      sum = boards[i];
    }
  }
  return c;
}

int findLargestMinDistance(vector<int> &boards, int k) {
  int l = 0, r = 0;
  for (int i = 0; i < boards.size(); i++) {
    l = max(l, boards[i]);
    r += boards[i];
  }
  int ans = r;
  while (l <= r) {
    int m = (l + r) / 2;
    if (noOfPainters(boards, m) <= k) {
      r = m - 1;
      ans = m;
    } else {
      l = m + 1;
    }
  }
  return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> boards(n);
    for(int i=0;i<n;i++){
        cin>>boards[i];
    }
    cout<<findLargestMinDistance(boards,k)<<endl;
    return 0;
}

// https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM