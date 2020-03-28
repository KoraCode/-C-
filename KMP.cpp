#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_next(string b)	
{
	vector<int> result;
	int i, j;
	i = 0;
	j = -1;
	result.push_back(-1);	
	while (i < b.size() - 1)
	{
		if (j == -1 || b[i] == b[j])	
		{
			++i;
			++j;
			if (b[i] != b[j])
				result.push_back(j);
			else if (i == 1)
				result.push_back(j);
			else
				result.push_back(result[j]);
		}
		else
			j = result[j];
	}
	return result;
}

int KMP(string a, string b)
{
	vector<int> next = get_next(b);
	int i = 0;
	int j = 0;
	while (i < (int)a.size() && j <(int)b.size())	
	{
		if (j == -1 || a[i] == b[j])
		{
			++i;
			++j;
		}
		else {
			j = next[j];
		}
	}
	if (j == b.size()) {
		return i - j;
	}
	else {
		return -1;
	}
}

int main()
{
	string str;
	cout << "enter the string:";
	cin >> str;
	string pattern;
	cout << "enter the pattern:";
	cin >> pattern;
	int result = KMP(str, pattern);
	cout << result << endl;
