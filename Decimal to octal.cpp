#include <iostream>
#include <cmath>
using namespace std;

int convertDecimalToOctal(int decimalNumber);
int main()
{
    int decimalNumber;

    cin>>decimalNumber;

    cout<<convertDecimalToOctal(decimalNumber);

    return 0;
}

int convertDecimalToOctal(int decimalNumber)
{
    int octalNumber = 0, i = 1;

    while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }

    return octalNumber;
}
