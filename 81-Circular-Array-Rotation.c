#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long n, k, q;
    scanf("%ld%ld%ld", &n, &k, &q);
    long *a = malloc(n * sizeof(long));
    long r = k % n;
    for (int i = r; i < n; i++)
    {
        scanf("%ld", &a[i]);
    }
    for (int i = 0; i < r; i++)
    {
        scanf("%ld", &a[i]);
    }
    long *queries = malloc(q * sizeof(long));
    long *ar = malloc(q * sizeof(long));
    for (int i = 0; i < q; i++)
    {
        scanf("%ld", &queries[i]);
        ar[i] = a[queries[i]];
    }
    for (int i = 0; i < q; i++)
    {
        printf("%ld\n", ar[i]);
    }
    return 0;
}
