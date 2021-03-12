#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int a,b,c,D,r1,r2;
	cin>>a>>b>>c;
	D=((b*b)-4*a*c);
	if(D>=0)
	{
		if(D==0)
		{
			r1=sqrt(c);
			r2=r1;
			cout<<"Real and Equal"<<endl;
			cout<<r1<<" "<<r2;
		}
		else
		{
			r1=(-b+(sqrt(D)))/2*a;
			r2=c/r1;
			if(r1<r2)
		{
			cout<<"Real and Distinct"<<endl;
			cout<<r1<<" "<<r2;
		}
		else
		{
			cout<<"Real and Distinct"<<endl;
			cout<<r2<<" "<<r1;
		}
		}
	}
	else
	{
		cout<<"Imaginary";
	}
}
