class Solution {
public:
    int totalMoney(int n) {
        int x = n/7;


        int ans = 0;

        if(n <= 7){
            ans += ((n*(1+n))/2);
        }
        else{
            for(int i=x ; i>=1 ; i--){
                ans += ((7*(2*i + 6))/2);
            }

            int y = n%7;
            ans += ((y*(2*x+1+y))/2);

        }
        
        return ans;
    }
};