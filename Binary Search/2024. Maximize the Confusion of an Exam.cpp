#include<bits/stdc++.h>
using namespace std;

class Solution {
private:  
    bool canReplace(string& s, int len, int k) {
        int f_count = 0, t_count = 0;
        for(int i=0; i<len; i++) {
            t_count += (s[i] == 'T');
            f_count += (s[i] == 'F'); 
        }
        
        if(t_count <= k || f_count <= k) return true;
        
        int lo = 0, hi = len-1;
        while(hi < s.size()-1) {
            t_count -= (s[lo] == 'T');
            f_count -= (s[lo] == 'F');
            
            lo++, hi++;
            
            t_count += (s[hi] == 'T');
            f_count += (s[hi] == 'F');
            
            if(t_count <= k || f_count <= k) return true;
        }
        
        return false;
    }
        
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int lo = 1, hi = n, ans = 1;
        
        while(lo <= hi) {
            int mid = (hi+lo) >> 1;
            
            if(canReplace(answerKey, mid, k)) {
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        
        return ans;
    }
};