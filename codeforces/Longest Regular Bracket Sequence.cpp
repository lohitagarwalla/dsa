// https://codeforces.com/problemset/problem/5/C

#define MOD 1000000007
 
#include <iostream>
 
using namespace std;
 
 
int main() {
    string str;
    
    cin >> str;
    
    int len = str.length();
    
    int *a = new int[len+5]; // bracket
    int *b = new int[len+5]; // index
    
    for(int i = 0; i<len+5; i++) a[i] = 0;
    for(int i = 0; i<len+5; i++) b[i] = 0;
    
    int max = 0;
    int mcount = 0;
    
    int ai = 0;
    int bi = 1;
    b[0] = -1;
    for(int i = 0; i<len; i++) {
        if(str[i] == '(') {
            a[ai] = 1;
            ai++;
            b[bi] = i;
            bi++;
        } else {
            if(ai == 0) {
                a[ai] = -1;
                ai++;
                b[bi] = i;
                bi++;
            } else if(a[ai-1] == 1) {
                ai--;
                bi--;
                int len = i - b[bi-1];
                if(len > max) {
                    max = len;
                    mcount = 1;
                } else if (len == max) {
                    mcount++;
                }
            } else {
                a[ai] = -1;
                ai++;
                b[bi] = i;
                bi++;
            }
        }
    }
    if(mcount == 0) {
        cout << "0 1" << endl;
    } else cout << max << " " << mcount << endl;
}