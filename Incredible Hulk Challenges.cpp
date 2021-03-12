#include <iostream>
using namespace std;


long long convertDecimalToBinary(unsigned long long int);


int main ()
{
    unsigned long long int n;
 // Number of test case
    cin >> n;
    
    unsigned long long int arr[n], i;
// Input for each test case

    for (i = 1; i <= n; i++)
        cin >> arr[i-1];

    for (i = 0; i < n; i++)
    {
        unsigned long long int binaryNumber, sum = 0;
        
     //Function to convert binary to decimal
        binaryNumber = convertDecimalToBinary(arr[i]);

        while (binaryNumber != 0)
        {
            unsigned long long int t;
            t = binaryNumber%2;
            sum = sum + t;
            binaryNumber = binaryNumber/10;
        }
        cout << sum << endl;
    }
    return 0;
}


//Function to convert Binary to decimal
long long convertDecimalToBinary(unsigned long long int n)
{
    long long binaryNumber = 0;
    unsigned long long int remainder, i = 1, step = 1;

    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}


