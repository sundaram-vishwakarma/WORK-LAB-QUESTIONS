
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, original, sum = 0, remainder;
    cout << "Enter a number: ";
    cin >> n;

    original = n;
    while (n != 0) {
        remainder = n % 10;
        sum += pow(remainder, 3);  // Cube the digit and add it to sum
        n /= 10;
    }

    if (sum == original)
        cout << original << " is an Armstrong number." << endl;
    else
        cout << original << " is not an Armstrong number." << endl;

    return 0;
}
