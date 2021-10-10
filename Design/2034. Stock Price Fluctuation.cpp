#include<bits/stdc++.h>
using namespace std;

class StockPrice {
    unordered_map<int, int> stocks;
    map<int, int> prices;
    pair<int, int> currentStock = {-1, -1};
public:
    
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(timestamp >= currentStock.first) {
            currentStock = {timestamp, price};
        }
        
        if(stocks.find(timestamp) != stocks.end()) {
            int old_price = stocks[timestamp];
            
            prices[old_price]--;
            if(prices[old_price] == 0) prices.erase(old_price);
        }
        
        prices[price]++;
        stocks[timestamp] = price;
        
    }
    
    int current() {
        return currentStock.second;
    }
    
    int maximum() {
        return prices.rbegin()->first;
    }
    
    int minimum() {
        return prices.begin()->first;
    }
};