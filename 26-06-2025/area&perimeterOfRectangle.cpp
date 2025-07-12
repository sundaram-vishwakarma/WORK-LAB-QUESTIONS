#include <iostream>
using namespace std;

int main() {
    float length, width;
    cout << "Enter length and width of rectangle: ";
    cin >> length >> width;

    float area = length * width;
    float perimeter = 2 * (length + width);

    cout << "Area of rectangle: " << area << endl;
    cout << "Perimeter of rectangle: " << perimeter << endl;

    return 0;
}
