// maximum area of histogram (MAH)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i, pseudoindex, width;
    cin >> n;

    int arr[n]; // array of heights
    for(i = 0; i < n; i++) 
        cin >> arr[i];
    
    // NSL
    vector<int> left; // contains NSL indices
    stack<pair<int, int>> s; // first = element, second = index

    pseudoindex = -1; // for NSL, assume height = 0 on -1 position
    for(i = 0; i < n; i++) { // left to right traversal, no need of vector reversal
        if(s.size() == 0)
            left.push_back(pseudoindex);
        else if(s.size() > 0 && s.top().first < arr[i])
            left.push_back(s.top().second);
        else if(s.size() > 0 && s.top().first >= arr[i]) {
            while(s.size() > 0 && s.top().first >= arr[i]) 
                s.pop();
            if(s.size() == 0)
                left.push_back(pseudoindex);
            else
                left.push_back(s.top().second);
        }
        s.push({arr[i], i});
    }

    // NSR
    vector<int> right; // contains NSR indices
    while(s.size() != 0) // empty the above stack for reuse
        s.pop();

    pseudoindex = n; // for NSR, assume height = 0 on nth position
    for(i = n - 1; i >= 0; i--) { // right to left traversal, needs vector reversal
        if(s.size() == 0)
            right.push_back(pseudoindex);
        else if(s.size() > 0 && s.top().first < arr[i])
            right.push_back(s.top().second);
        else if(s.size() > 0 && s.top().first >= arr[i]) {
            while(s.size() > 0 && s.top().first >= arr[i])
                s.pop();
            if(s.size() == 0)
                right.push_back(pseudoindex);
            else
                right.push_back(s.top().second);
        }
        s.push({arr[i], i});
    }
    reverse(right.begin(), right.end());

    int area[n]; // contains max. possible area for all heights
    int maxArea = 0; // stores MAH
    for(i = 0; i < n; i++) {
        width = right[i] - left[i] - 1;
        area[i] = arr[i] * width;
        if(area[i] > maxArea)
            maxArea = area[i];
    }
    cout << maxArea;
    return 0;
}