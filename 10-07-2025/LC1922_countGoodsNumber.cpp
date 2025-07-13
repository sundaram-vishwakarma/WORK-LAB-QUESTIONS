class Solution {
public:
    static const int M = 1e9 + 7;  // Modulo constant

    // Function to compute (a^b) % M using fast exponentiation
    long long findPower(long long a, long long b) {
        if (b == 0) {
            return 1;
        }

        long long half = findPower(a, b / 2);
        long long result = (half * half) % M;

        if (b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2;  // Count of even positions
        long long oddPositions = n / 2;         // Count of odd positions

        long long result = (findPower(5, evenPositions) * findPower(4, oddPositions)) % M;
        return static_cast<int>(result);
    }
};
