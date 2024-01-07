void rev(string &s, int i, int j)
{
    while (i < j)
    {
        swap(s[i], s[j]);
        j--;
        i++;
    }
    return;
}
string printMinNumberForPattern(string s)
{
    int n = s.size();
    string ans = "";
    for (int i = 1; i <= n + 1; i++)
        ans += i + '0';
    for (int i = 0; i < min(9, n); i++)
    {
        int j = i;
        while (s[j] == 'D')
            j++;
        if (i < j)
            rev(ans, i, j);
        i = j;
    }
    while (n > 9)
        ans += ':', n--;
    return ans;
}