#include <iostream>

int StringCount(const char* const _Str)
{
    int Count = 0;

    while (_Str[Count])
    {
        Count++;
    }

    return Count;
}

int main()
{
    // [B][B][B][B][0]

    int Count = StringCount("BBBB");

    // cout << Count;

    return 0;
}
