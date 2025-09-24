#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int maximumSubarraySum(int arr[], int n, int k)
{
    int low = 0, high = k - 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        int temp_sum = 0;
        // window of length [k = high - low + 1]
        for (int j = low; j <= high && high < n; j++)
        {
            temp_sum += arr[j];
        }
        // cout<<temp_sum<<"  ";
        sum = max(sum, temp_sum);
        low++;
        high++;
    }
    // cout<<endl;
    return sum;
}

int maximumSubarraySumInLinearTimeComplexity(int arr[], int n, int k)
{
    ll left = 0, right = 0, sum = 0, max_sum = INT_MIN;
    while (right < n)
    {
        sum += arr[right];
        if (right - left + 1 < k)
        {
            right++;
        }
        else if (right - left + 1 == k)
        {
            max_sum = max(max_sum, sum);
            sum = sum - arr[left];
            left++;
            right++;
        }
    }
    return max_sum;
}

int main()
{
    int arr[] = {-1, 2, 3, 3, 4, 5, -1};
    int brr[] = {1, 2, 3, 4, 5, 6};
    cout << "Answer : " << maximumSubarraySum(brr, 6, 4);
    cout << "\nAnswer : " << maximumSubarraySumInLinearTimeComplexity(brr, 6, 4);

    return 0;
}