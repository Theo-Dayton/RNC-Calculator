/*
 * got_int.cpp
 *
 *
 * A function that will tell you whether a string can be interpreted
 * as a integer number, and, if so, give the
 * value.  
 *
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

size_t max_length(char *c_strs[], int len);

bool got_int(string s, int *resultp)
{
        /* Holds the first non-whitespace character after the integer */
        char extra;

        return sscanf(s.c_str(), " %d %c", resultp, &extra) == 1;
}


/*
 * Return length of longest C-style string in the array of C strings.
 *
 * Requires len > 0:   it is an unchecked error for len <= 0
 */
size_t max_length(char *c_strs[], int len)
{
        size_t max_so_far = strlen(c_strs[0]);

        for (int i = 1; i < len; ++i)
                max_so_far = max(max_so_far, strlen(c_strs[i]));
        return max_so_far;
}
