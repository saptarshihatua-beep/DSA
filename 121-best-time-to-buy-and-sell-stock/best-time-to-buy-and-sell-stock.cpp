class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int  minimumprice = prices[0];
        int maximumprofit=0;
        for (int i = 1; i<prices.size(); i++){
            if(minimumprice > prices[i]){
                minimumprice = prices[i];
            }
            int profit = prices[i] - minimumprice;
            if (profit > maximumprofit) {
                maximumprofit = profit;
            }

        }
        return maximumprofit;
        
    }
};