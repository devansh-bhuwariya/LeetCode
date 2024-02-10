class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int ans = __gcd(targetX, targetY);

        // Continue dividing GCD by 2 until it's no longer even.
        while (ans % 2 == 0) {
            ans = ans / 2;
        }

        // Check if the final GCD is 1, indicating reachability.
        return ans == 1;
    }
};