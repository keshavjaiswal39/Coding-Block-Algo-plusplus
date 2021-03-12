#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int r,c;
	cin>>r>>c;
	int **arr;
	arr=new int*[r];
	for(int i=0;i<r;i++)
	{
		arr[i]=new int[c];
	}
	int count=0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			arr[i][j]=count;
			count++;
		}
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl<<endl;
	}
}
