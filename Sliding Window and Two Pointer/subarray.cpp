#include<iostream>
#include<vector>
using namespace std;

void solve(int arr[], int n, int k) {
    int sum, maxSum = -100;
    for(int i = 0; i <= n - k; i++) {
        sum = 0;
        for(int j = i; j < i + k; j++) {
            sum += arr[j];
        }
        cout<<sum<<" ";
        maxSum = max(maxSum, sum);
    }
    cout << "\n" << maxSum << "\n";
}

int main() {
    int arr[] = { 1, 2, -3, 4, 5, 6 };
    solve(arr, 6, 3);

}