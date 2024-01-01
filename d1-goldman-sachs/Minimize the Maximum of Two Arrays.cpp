#define ll long long
class Solution {
public:
    int gcd(int a, int b){
        return !b ? a : gcd(b , a % b);
    }

    int lcm(ll a, ll b){
        ll temp = (a / gcd(a, b)) * b;
        return temp > INT_MAX ? INT_MAX : temp;
    }

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int left = 1, right = INT_MAX;
        int LCM = lcm(divisor1, divisor2);
        
        while(left <= right){
            int mid = left + (right - left)/2;
            int a = mid/divisor1, b = mid/divisor2;
            if(uniqueCnt1 <= mid-a and uniqueCnt2 <= mid-b and uniqueCnt1+uniqueCnt2 <= (mid - (mid/LCM)))
                right = mid - 1;
            else   
                left = mid + 1;
        }

        return left;
    }
};