#include <bits/stdc++.h>
using namespace std;

// nearest greater element to right
int main() {
    int n, i;
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    vector<int> v; // holds o/p
    stack<int> s;  // supplementary data structure

    // arr: 2    1   3   9   4
    // o/p: 3    3    9    -1   -1
    // stack empty: -1

    for(i = n - 1; i >= 0; i--) {
        if(s.size() == 0) {
            v.push_back(-1);
        }
        else if(s.size() > 0 && s.top() > a[i]) {
            v.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() <= a[i]) {
            while(s.size() > 0 && s.top() <= a[i]) {
                s.pop();
            }
            if(s.size() == 0) {
                v.push_back(-1);
            }
            else {
                v.push_back(s.top());
            }
        }
        s.push(a[i]);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    } cout << endl;
    return 0;
}