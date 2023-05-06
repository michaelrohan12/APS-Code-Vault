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
 * Complete the 'luckBalance' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. 2D_INTEGER_ARRAY contests
 */

void insertion_sort(int **a, int n)
{
    int i, j, u, v;
    for (i = 1; i <= n - 1; i++)
    {
        v = a[i][0];
        u = a[i][1];
        j = i - 1;
        while (j >= 0 && a[j][0] > v)
        {
            a[j + 1][0] = a[j][0];
            a[j + 1][1] = a[j][1];
            j--;
        }
        a[j + 1][0] = v;
        a[j + 1][1] = u;
    }
}

int luckBalance(int k, int contests_rows, int contests_columns, int **contests)
{
    insertion_sort(contests, contests_rows);
    int i, sum = 0, diff = 0, count = 0;
    for (i = 0; i < contests_rows; i++)
    {
        sum += contests[i][0];
    }
    for (i = 0; i < contests_rows; i++)
    {
        if (contests[i][1] == 1)
        {
            count++;
        }
    }
    count -= k;
    for (i = 0; i < contests_rows && count > 0; i++)
    {
        if (contests[i][1] == 1)
        {
            diff += contests[i][0];
            --count;
        }
    }
    int result = sum - (2 * diff);
    return result;
}

int main()
{
    FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char **first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int k = parse_int(*(first_multiple_input + 1));

    int **contests = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        *(contests + i) = malloc(2 * (sizeof(int)));

        char **contests_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 2; j++)
        {
            int contests_item = parse_int(*(contests_item_temp + j));

            *(*(contests + i) + j) = contests_item;
        }
    }

    int result = luckBalance(k, n, 2, contests);

    fprintf(fptr, "%d\n", result);

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
