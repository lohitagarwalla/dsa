https://practice.geeksforgeeks.org/problems/find-sum-of-different-corresponding-bits-for-all-pairs4652/1/?track=mdcq-bitmagic&batchId=184#


int MAX = 1000000007;

int multiply(int a, int b) {
    if(b == 0) return 0;
    
    long long int ans = multiply(a, b/2);
    if(b%2 == 0) {
        return (ans + ans) % MAX;
    }
    if(b%2 == 1) {
        return (ans + ans +a) % MAX;
    }
}

class Solution{
public:
    int countBits(int N, long long int A[])
    {
        int ones[33];
        
        for(int i=0; i<33; i++) {
            ones[i] = 0;
        }
        
        for(int i = 0; i<N; i++) {
            int x = A[i];
            
            int j = 0;
            while(x > 0) {
                if(x&1) {
                    ones[j]++;
                }
                x = x>>1;
                j++;
            }
        }
        
        long long int ans = 0;
        
        for(int i=0; i<33; i++) {
            int zeros = N-ones[i];
            long long int c = multiply(zeros, ones[i]);
            c %= MAX;
            ans += c;
            ans %= MAX;
        }
        
        ans *= 2;
        ans %= MAX;
        return ans;
    }
};