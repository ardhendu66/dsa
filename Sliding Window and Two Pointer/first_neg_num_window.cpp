#include<bits/stdc++.h>
using namespace std;

// Find first negetive number in every window of size k in an array

void findFirstNegetiveNumber(int arr[], int n, int k) {
    for(int i = 0; i <= n - k; i++) {
        for(int j = i; j < i + k && j < n; j++) {
            if(arr[j] < 0) {
                cout << arr[j] << "  ";
                break;
            }
        }
    }
}

void firstNegative(int arr[], int n, int k) {
	vector<int> ans;
	queue<int> q;
	int i = 0, j = 0;
	while(j < n) {
		if(arr[j] < 0) q.push(arr[j]);
		if(j-i+1 < k) {
			j++;
		}
		else if(j-i+1 == k) {
            q.empty() ? ans.push_back(0) : ans.push_back(q.front());
            if(arr[i] == q.front()) {
                q.pop();
            }
            i++;
            j++;
		}
	}
    for(auto &ele : ans) {
        cout << ele << "  ";
    }
    cout << "\n";
}

int main() {
    int arr[] = { -2, -1, -3, -4, -7, -10 };
    int n = 6, k = 3;
    // findFirstNegetiveNumber(arr, n, k);
    firstNegative(arr, n, k);

    return 0;
}