#include<bits/stdc++.h>
using namespace std;

class TimeMap {
    unordered_map<string,vector<pair<int, string>>> mp;
public: 
    
    static bool compare(const int& val, const pair<int, string>& a) {
        return a.first > val;
    }

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& vec = mp[key];
        auto itr = upper_bound(vec.begin(), vec.end(), timestamp, compare);
        
        return itr == vec.begin() ? "" : prev(itr)->second;
    }
};