#include<iostream>
using namespace std;

int fastPow(int a, int b)
{
    if(b==0)
        return a;

    int smallAns = fastPow(a, b/2);
    smallAns *= smallAns;
    if(b & 1)
         return smallAns*a;

     return smallAns;
}


bool isArmstrong(int n)
{
    int noOfDigits = 0;
    int m = n;
    while (m)
    {
        noOfDigits++;
        m /= 10;
    }

    m = n;
    int sum = 0;
    while (m)
    {
        int r = m % 10;
        sum += fastPow(r, noOfDigits);
        m /= 10;
    }

    return n == sum;
}

int main()
{
	int n;
	cin>>n;
	if (isArmstrong(n))
	{
		cout<<"false";
	}
	else
	{
		cout<<"true";
	}
}
