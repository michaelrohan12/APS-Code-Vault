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
/*
 * Complete the 'closestNumbers' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */
void insertion_sort(int *a, int n)
{
    int i, j, v;
    for (i = 1; i <= n - 1; i++)
    {
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
}

int *closestNumbers(int arr_count, int *arr, int *result_count)
{
    insertion_sort(arr, arr_count);
    int i, min = arr[1] - arr[0];
    int *result = malloc(200000 * sizeof(int));
    *result_count = 0;
    for (i = 1; i < arr_count - 1; i++)
    {
        if (min > arr[i + 1] - arr[i])
        {
            min = arr[i + 1] - arr[i];
            (*result_count) = 0;
            result[(*result_count)++] = i;
        }
        else if (min == arr[i + 1] - arr[i])
        {
            result[(*result_count)++] = i;
        }
    }
    return result;
}

int main()
{
    FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n;

    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int result_count;
    int *result = closestNumbers(n, arr, &result_count);

    for (int i = 0; i < result_count; i++)
    {
        fprintf(fptr, "%d %d", arr[result[i]], arr[result[i] + 1]);

        if (i != result_count - 1)
        {
            fprintf(fptr, " ");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}
