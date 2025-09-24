#include<bits/stdc++.h>
using namespace std;

int largest2(vector<int>& arr) {
    map<int, int> mp;
    for(int i = 0; i < arr.size(); i++) mp[arr[i]]++;
    int maxi = -1, maxi2 = -1;
    for(auto &i : mp) {
        if(i.second == 1 && maxi < i.first) {
            maxi = i.first;
            // cout << maxi << "  ";
        }
    }
    for(auto &i : mp) {
        if(i.second == 1 && maxi2 < i.first && maxi != i.first && maxi2 < maxi) {
            maxi2 = i.first;
            cout << maxi2 << " " << (maxi2 < maxi) << "\n";
        }
    }
    return maxi2;
}

vector<int> second_smallest_and_largest_element(vector<int>& arr, int n) {
    // finding second largest element
    int maximum_element = INT_MIN, sec_max = INT_MIN;
    for(int i = 0; i < n; i++) maximum_element = max(maximum_element, arr[i]);
    for(int i = 0; i < n; i++) {
        if(arr[i] > sec_max && arr[i] != maximum_element) sec_max = arr[i];
    }

    // finding second smallest element
    int minimum_element = INT_MAX, sec_min = INT_MAX;
    for(int i = 0; i < n; i++) minimum_element = max(minimum_element, arr[i]);
    for(int i = 0; i < n; i++) {
        if(arr[i] < sec_min && arr[i] != minimum_element) sec_min = arr[i];
    }

    return { sec_min, sec_max };
}

int main() {
    vector<int> v = { 12, 35, 1, 10, 34, 2 };
    vector<int> ans = second_smallest_and_largest_element(v, v.size());
    cout << ans[0] << "  " << ans[1] << endl;
}