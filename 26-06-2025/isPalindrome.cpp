
#include <iostream>
using namespace std;

int main() {
    int n, reverse = 0, original, remainder;
    cout << "Enter a number: ";
    cin >> n;

    original = n;
    while (n != 0) {
        remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n /= 10;
    }

    if (original == reverse)
        cout << original << " is a palindrome number." << endl;
    else
        cout << original << " is not a palindrome number." << endl;

    return 0;
}
