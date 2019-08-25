#include <iostream>
#include <string>

using namespace std;

string L(string s)
{
    int n = s.length();
    bool **arr = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        bool *row = new bool[n];
        for (int j = 0; j < n; j++)
        {
            row[j] = false;
        }
        arr[i] = row;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= i; j--)
        {
            if (i == j)
            {
                arr[i][j] = true;
                continue;
            }
            if (i - j == -1)
            {
                arr[i][j] = s[i] == s[j];
                continue;
            }
            arr[i][j] = (s[i] == s[j]) && arr[i + 1][j - 1];
        }
    }
    int m = 0, start = 0, end = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i][j])
            {
                if (j - i > m)
                {
                    m = j - i;
                    start = i;
                    end = j;
                }
            }
        }
    }
    return s.substr(start, m + 1);
}
string longestPalindrome(string s)
{
    return L(s);
}

int main()
{
    string s;
    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}
