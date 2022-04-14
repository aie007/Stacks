// Nearest Smaller Element to Left

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, i;
    cin >> n;
    
    int arr[n];
    for(i = 0; i < n; i++) 
        cin >> arr[i];

    vector<int> v;
    stack<pair<int, int>> s;

    for(i = 0; i < n; i++) {
        if(s.size() == 0)
            v.push_back(0);
        else if(s.size() > 0 && s.top().first < arr[i])
            v.push_back(s.top().second);
        else if(s.size() > 0 && s.top().first >= arr[i]) {
            while(s.size() > 0 && s.top().first >= arr[i])
                s.pop();
            if(s.size() == 0)
                v.push_back(0);
            else
                v.push_back(s.top().second);
        }
        s.push({arr[i], i+1});
    }
    // Display the index of NSL for each element
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    } cout << endl;
    return 0;
}
