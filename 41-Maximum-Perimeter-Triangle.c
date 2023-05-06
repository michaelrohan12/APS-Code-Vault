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

char *readline();
char *ltrim(char *);
char *rtrim(char *);
char **split_string(char *);

int parse_int(char *);

/*
 * Complete the 'maximumPerimeterTriangle' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY sticks as parameter.
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
int triplets(int a, int b, int c)
{
    if ((a + b > c) && (b + c > a) && (c + a > b))
        return 1;
    else
        return 0;
}

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int *maximumPerimeterTriangle(int sticks_count, int *sticks, int *result_count)
{
    int *result = malloc(3 * sizeof(int));
    *result_count = 1;
    qsort(sticks, sticks_count, sizeof(int), cmpfunc);
    int k, per, res_per = 0, check, flag = 1;
    for (int i = 0; i < sticks_count - 2; i++)
    {
        check = triplets(sticks[i], sticks[i + 1], sticks[i + 2]);
        if (check)
        {
            per = sticks[i] + sticks[i + 1] + sticks[i + 2];
            if (flag || (per > res_per))
            {
            re_enter:
                k = i;
                flag = 0;
                *result_count = 3;
                for (int j = 0; j < 3; j++)
                {
                    result[j] = sticks[k++];
                }
                res_per = per;
            }
            else if (per == res_per)
            {
                if (sticks[i + 2] > result[2])
                {
                    goto re_enter;
                }
                else if (sticks[i] > result[0])
                {
                    goto re_enter;
                }
            }
        }
    }
    if (*result_count == 1)
        result[0] = -1;
    return result;
}

int main()
{
    FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char **sticks_temp = split_string(rtrim(readline()));

    int *sticks = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int sticks_item = parse_int(*(sticks_temp + i));

        *(sticks + i) = sticks_item;
    }

    int result_count;
    int *result = maximumPerimeterTriangle(n, sticks, &result_count);

    for (int i = 0; i < result_count; i++)
    {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1)
        {
            fprintf(fptr, " ");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char *readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char *data = malloc(alloc_length);

    while (true)
    {
        char *cursor = data + data_length;
        char *line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line)
        {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
        {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data)
        {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data)
        {
            data = '\0';
        }
    }
    else
    {
        data = realloc(data, data_length + 1);

        if (!data)
        {
            data = '\0';
        }
        else
        {
            data[data_length] = '\0';
        }
    }

    return data;
}

char *ltrim(char *str)
{
    if (!str)
    {
        return '\0';
    }

    if (!*str)
    {
        return str;
    }

    while (*str != '\0' && isspace(*str))
    {
        str++;
    }

    return str;
}

char *rtrim(char *str)
{
    if (!str)
    {
        return '\0';
    }

    if (!*str)
    {
        return str;
    }

    char *end = str + strlen(str) - 1;

    while (end >= str && isspace(*end))
    {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char **split_string(char *str)
{
    char **splits = NULL;
    char *token = strtok(str, " ");

    int spaces = 0;

    while (token)
    {
        splits = realloc(splits, sizeof(char *) * ++spaces);

        if (!splits)
        {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char *str)
{
    char *endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0')
    {
        exit(EXIT_FAILURE);
    }

    return value;
}
