#include<bits/stdc++.h>
using namespace std;

// Optimal
bool isAllZero(vector<int>& counter) {
    for(int &value : counter) {
        if(value != 0) return false;
    }
    return true;
}
void count_occurrences_of_anagrams(string str, string pat) {
    int n = str.length(), k = pat.length();
    int i = 0, j = 0, ans = 0;
    vector<int> counter(26, 0);
    for(int i = 0; i < k; i++) counter[pat[i] - 'a']++;
    while(j < n) {
        counter[str[j] - 'a']--;
        if(j - i + 1 < k) {
            j++;
        }
        else if(j - i + 1 == k) {
            if(isAllZero(counter)) {
                ans++;
            }
            counter[str[i] - 'a']++;
            i++;
            j++;
        }
    }
    cout << ans << "\n";
}

int main() {
    string str = "forxfor", pat = "for";
    count_occurrences_of_anagrams(str, pat);

    return 0;
}