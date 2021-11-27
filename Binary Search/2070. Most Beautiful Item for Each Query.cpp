#include<bits/stdc++.h>
using namespace std;

// Approach 1:
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        int n = items.size();
        
        sort(items.begin(), items.end());
        
        vector<int> maxBeautyTillNow(n, 0);
        
        for(int i=0; i<n; i++) {
            maxBeautyTillNow[i] = (i == 0) ? items[i][1] : max(maxBeautyTillNow[i-1], items[i][1]);
        }
        
        vector<int> answer;
        for(auto& query : queries) {
            int idx = upper_bound(items.begin(), items.end(), vector<int>({query, INT_MAX})) - items.begin();

            if(idx >= n || items[idx][0] > query) idx--;
            
            if(idx < 0) answer.push_back(0);
            else answer.push_back(maxBeautyTillNow[idx]);
        }
        
        return answer;
    }
};

// Approach 2:
class Solution {
    // Offline Query SOlving
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        int n = items.size();
        int m = queries.size();
        
        sort(begin(items), end(items));
        
        vector<pair<int, int>> newQueries;
        int i=0; 
        for(auto& q : queries) {
            newQueries.push_back({q, i++});
        }
        
        sort(begin(newQueries), end(newQueries));
        
        int idx = 0, maxBeauty = 0;
        vector<int> answer(m, 0);
        
        for(auto& [query, index] : newQueries) {
            
            while(idx < n && items[idx][0] <= query) {
                maxBeauty = max(maxBeauty, items[idx][1]);
                idx++;
            }
            
            answer[index] = maxBeauty;
        }
        
        return answer;
    }
};