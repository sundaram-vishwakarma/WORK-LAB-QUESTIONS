#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "Enter a number: ";
    cin >> n;

    while (n != 0) {
        sum += n % 10;  // Add last digit to sum
        n /= 10;  // Remove last digit
    }

    cout << "The sum of the digits is: " << sum << endl;
    return 0;
}
