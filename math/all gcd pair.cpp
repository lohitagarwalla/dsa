int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

// void insert(vector<int> &a, int index, vector<int> &ans, unordered_map<int, int> &mp) {
// }

vector<int> Solution::solve(vector<int> &a) {
    sort(a.begin(), a.end());
    unordered_map<int, int> mp;
    for(auto e : a) {
        mp[e]++;
    }

    int n = a.size();
    vector<int> ans;
    ans.push_back(a[n-1]);
    mp[a[n-1]]--;

    for(int i = n-2; i>=0; i--) {
        int num = a[i];

        if(mp[num] <=0) continue;
        int s = ans.size();
        for(int j = 0; j<s; j++) {
            int g = gcd(num, ans[j]);
            if(mp[g] >=2) {
                mp[g] -= 2;
            } else break;
        }
        ans.push_back(num);
        mp[num]--;
    }

    return ans;
}
