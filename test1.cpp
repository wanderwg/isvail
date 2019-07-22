#include<iostream>
#include<string>
using namespace std;
bool Isvail(const char* str1, const char* str2)
{
	if (*str1 == '\0'&&*str2 == '\0')
		return true;
	else if (*str1 == '\0' || *str2 == '\0')
		return false;
	if (*str1 == '?')
	{
		return Isvail(str1 + 1, str2 + 1);
	}
	else if (*str1 == '*')
		return Isvail(str1 + 1, str2) || Isvail(str1 + 1, str2 + 1) || Isvail(str1 + 1, str2 + 1);
	else if (*str1 == *str2)
		return Isvail(str1 + 1, str2 + 1);
	return false;
}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (Isvail(str1.c_str(), str2.c_str()))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}