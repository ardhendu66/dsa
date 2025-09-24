#include<bits/stdc++.h>
using namespace std;

void printAllSubarray(int arr[], int n, int k) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            for(int k = i; k <= j; k++) {
                cout << arr[k] << "  ";
                sum += arr[k];
            }
            cout<<"["<<sum<<"]"<<endl;
            sum = 0;
        }
    }
}

void largestSubarraySumKPositiveNumbers(int arr[], int n, int k) {
    int i = 0, j = 0, ans = -1, sum = 0;
    while(j < n) {
        sum += arr[j++];
        while(sum > k) {
            sum = sum - arr[i++];
        }
        if(sum == k) {
            ans = max(ans, j - i + 1);
        }
    }
    cout << ans <<"\n";
}

void longestSubarraySumKAllNumbers(int arr[], int n, int k) {
    int i = 0, j = 0, sum = 0;
    map<int, int> mp;
}

int main() {
    int arr[6] = { 1, 2, 3, 4, 5, 6 };

    largestSubarraySumKPositiveNumbers(arr, 6, 3);

    return 0;
}