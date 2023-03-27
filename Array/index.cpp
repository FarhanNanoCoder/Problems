#include <bits/stdc++.h>
using namespace std;
int solution(vector<int>& cards){
    map<int,int> counts;
    for(int i=0;i<cards.size();i++){
        counts[cards[i]] = ++counts[cards[i]];
    }
    for(auto it=counts.begin();it!=counts.end();it++){
        if(it->second ==1){
            return it->first;
        }
    }
}
int main(){
    vector<int> cards = {8, 5, 8, 4, 4};
    cout<<solution(cards);
}