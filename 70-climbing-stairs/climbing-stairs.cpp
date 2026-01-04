class Solution {
public:
    int climbStairs(int n) {
        //vector<int> memArray(n+1);

        if ( n==2 || n==1){
            return n;
        }

        // memArray[0] = 0;
        // memArray[1] = 1;
        // memArray[2] = 2;
        // for(int i=3 ; i<=n; i++) {
        //     memArray[i] = memArray[i-1] + memArray[i-2];
        // }
        // return memArray[n];
        //further optimization we need only two values i-1 and i-2
        int a = 1;
        int b = 2;
        int c = 3;
        for(int i=3; i<=n ;i++){
            c = a+b;
            a=b;
            b=c;
        }
        return c;
    }
};