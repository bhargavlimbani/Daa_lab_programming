#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int wt, val;
    float ratio;
};

bool cmp(Item a, Item b){
    return a.ratio > b.ratio;
}

float greedyKnapsack(int capacity, int wt[], int val[], int n){
    Item items[n];
    
    for(int i=0;i<n;i++){
        items[i].wt = wt[i];
        items[i].val = val[i];
        items[i].ratio = (float)val[i]/wt[i];
    }

    sort(items, items+n, cmp);

    float totalValue = 0.0;

    for(int i=0;i<n;i++){
        if(items[i].wt <= capacity){
            capacity -= items[i].wt;
            totalValue += items[i].val;
            cout << "Take full item: (" << items[i].wt << "," << items[i].val << ")\n";
        }
        else{
            totalValue += items[i].ratio * capacity;
            cout << "Take fraction of item: (" << items[i].wt << "," << items[i].val << ")\n";
            break;
        }
    }
    return totalValue;
}

int main(){
    int wt[] = {2,3,1,4,3,2};
    int val[] = {10,5,3,2,8,7};
    int capacity = 7;
    int n = 6;

    cout << "\nTotal Value = " << greedyKnapsack(capacity, wt, val, n);
    return 0;
}
