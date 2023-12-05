#inlcude<bits/stc++.h>

using namespace std;

int coinChange(vector<int>& coins, int amount){
    vector<int> res;		
    res.push_back(0);
    sort(coins.begin(),coins.end());
    for(int i=1;i<=amount;i++){	
        res.push_back(9999999);
        for(int j=0;j<coins.size() && coins[j]<=i;j++){
            res[i] = min(res[i], 1+res[i-coins[j]]);	
        }
        
    }
    return res[amount]==9999999?-1:res[amount];
}


int main(){
	vector<int> coins={1,2,5};
	cout<< coinChange(coins,11);
}