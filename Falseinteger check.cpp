#include<iostream>
using namespace std;


int invalidIntegerInputCheck()
{
	int n;
	cin >> n;
	while (cin.fail())
	{
		cin.clear();
	    while(cin.get() != '\n')
		{
		}   
	    cout << "\nPlease enter an integer : ";
	    cin >> n;
	}
	return n;
}
int main()
{
	int choice;
	cout << "Enter a number : " ;
	choice = invalidIntegerInputCheck();
	cout<<choice;
}
