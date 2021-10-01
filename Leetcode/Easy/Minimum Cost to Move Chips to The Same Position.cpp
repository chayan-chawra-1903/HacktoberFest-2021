class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd=0;
        int even=0;
        for(auto it=position.begin();it!=position.end();it++)
            *it%2?odd++:even++;
        return min(odd,even);
    }
};