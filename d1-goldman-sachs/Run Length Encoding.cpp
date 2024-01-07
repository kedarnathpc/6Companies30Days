string encode(string src)
{
    // Your code here
    int n = src.size();
    int i = 0;
    int j = 1;
    int count = 1;
    while (j < n)
    {
        if (src[j] != src[j - 1])
        {
            src = src.substr(0, i + 1) + to_string(count) + src.substr(j);
            j = i + 2;
            i = j;
            count = 1;
        }
        else
        {
            count += 1;
        }
        n = src.size();
        j += 1;
    }
    src = src.substr(0, i + 1) + to_string(count);
    return src;
}