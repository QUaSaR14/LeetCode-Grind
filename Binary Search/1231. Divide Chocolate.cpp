#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool divideChocolate(vector<int>& sweetness, int minSum, int K) {
        int sum = 0, cnt = 0;
        for(auto& sweet : sweetness) {
            sum += sweet;
            if(sum >= minSum) {
                sum = 0;
                cnt++;
            }
        }

        return (cnt >= K);
    }
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {

        int low = *min_element(sweetness.begin(), sweetness.end());
        int high = accumulate(sweetness.begin(), sweetness.end(), 0);

        int ans = low;

        while(low <= high) {
            int mid = low + ((high - low) >> 1);

            if(divideChocolate(sweetness, mid, K)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};