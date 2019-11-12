#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int ammount_of_words(char(&s)[512])
{
	int count = 0;
	bool prov = false;
	for (int i = 0; i < strlen(s); i++)
	{
		if (!prov)
		{
			if (isalnum(s[i])) prov = true;
		}
		else
		{
			if (isspace(s[i]) || ispunct(s[i]) || i == strlen(s) - 1)
			{
				prov = false;
				count++;
			}
		}
	}
	return count;
}

void alphabet(char(&s)[512])
{
	bool prov = false;
	int j = 0, count = 0, povtor = 0;
	int n = ammount_of_words(s);
	char** a = new char* [n];
	for (int i = 0; i < n; i++) a[i] = new char[512];
	for (int i = 0; i < strlen(s); i++)
	{
		if (!prov)
		{
			if (isalnum(s[i]))
			{
				prov = true;
				j = 0;
				a[count][j] = s[i];
				j++;
			}
		}
		else
		{
			if (isspace(s[i]) || ispunct(s[i]) || i == strlen(s) - 1)
			{
				if (i == strlen(s) - 1 && isalnum(s[i]))
				{
					a[count][j] = s[i];
					a[count][j + 1] = '\0';
				}
				else
				{
					a[count][j] = '\0';
					prov = false;
					count++;
				}
			}
			else
			{
				a[count][j] = s[i];
				j++;
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
		for (int i1 = i + 1; i1 < n; i1++)
		{
			if ((int)a[i][0] > (int)a[i1][0]) swap(a[i], a[i1]);
		}
	cout << endl << "Слова у порядку зростання: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << "Слова у порядку спадання: " << endl;
	for (int i = n - 1; i >= 0; i--)
	{
		cout << a[i] << " ";
	}
}

void length(char(&s)[512])
{
	bool prov = false;
	int j = 0, count = 0, povtor = 0;
	int n = ammount_of_words(s);
	char** a = new char* [n];
	for (int i = 0; i < n; i++) a[i] = new char[512];
	for (int i = 0; i < strlen(s); i++)
	{
		if (!prov)
		{
			if (isalnum(s[i]))
			{
				prov = true;
				j = 0;
				a[count][j] = s[i];
				j++;
			}
		}
		else
		{
			if (isspace(s[i]) || ispunct(s[i]) || i == strlen(s) - 1)
			{
				if (i == strlen(s) - 1 && isalnum(s[i]))
				{
					a[count][j] = s[i];
					a[count][j + 1] = '\0';
				}
				else
				{
					a[count][j] = '\0';
					prov = false;
					count++;
				}
			}
			else
			{
				a[count][j] = s[i];
				j++;
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
		for (int i1 = i + 1; i1 < n; i1++)
		{
			if (strlen(a[i]) > strlen(a[i1])) swap(a[i], a[i1]);
		}
	cout << endl << "Слова у порядку зростання: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << "Слова у порядку спадання: " << endl;
	for (int i = n - 1; i >= 0; i--)
	{
		cout << a[i] << " ";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char s[512];
	cout << "Enter your text" << endl;
	cin.getline(s, 512);
	alphabet(s);
	length(s);
	return 0;
}