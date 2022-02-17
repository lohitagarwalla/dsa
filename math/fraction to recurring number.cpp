//leetcode https://leetcode.com/explore/interview/card/top-interview-questions-medium/113/math/821/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long n = numerator;
        long long d = denominator;
        string s = "";
        
        bool is_negative = false;
        if(numerator < 0 && denominator >=0 || numerator >=0 && denominator < 0) {
            is_negative = true;
            s += '-';
        }
        
        n = n<0 ? n*(-1) : n;
        d = d<0 ? d*(-1) : d;
        
        if(n/d == 0 && n%d == 0) return "0";
        
        vector<int> pre;
        long long x = n/d;
        while(1) {
            pre.push_back(x%10);
            x = x/10;
            if(x == 0) break;
        }
        
        while(pre.empty() == false) {
            int i = (int)'0';
            i += pre.back();
            s += i;
            pre.pop_back();
        }
        
        n = n%d;
        
        if(n == 0) return s;
        
        s += ".";
        
        vector<vector<int>> vec;
        unordered_map<int, int> mp;
        
        int repeating_rem = -1;
        
        int r = n%d;
        while(r > 0 && n > 0) {
            cout << "hi" << endl;
            n = n*10;
            int q = n/d;
            
            auto it = mp.find(r);
            if(it == mp.end() || q == 0) {
                vector<int> v;
                v.push_back(r);
                v.push_back(q);
                vec.push_back(v);
                
                mp[r] = q;
            } else {
                repeating_rem = r;
                break;
            }
            r = n%d;
            n = n%d;
        }
        
        for(auto e : vec) {
            if(e[0] == repeating_rem && repeating_rem >= 0) {
                s += '(';
            }
            int i = (int)'0';
            i += e[1];
            s += (char)i;
        }
        if(repeating_rem >= 0) {
            s += ')';
        }
        
        return s;
    }
};