#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t global_start;
clock_t global_cpu_start;

int chec(int paramInt1, int paramInt2);

int check1(int paramInt1, int paramInt2)
{
    int j = 1;
    int i = paramInt1;
    paramInt1 = j;
    while (paramInt1 < 100)
    {
        i += paramInt1;
        paramInt1 += 1;
    }
    return chec(i, paramInt2);
}

int check2(int paramInt1, int paramInt2)
{
    int j = 1;
    int i = paramInt1;
    if (paramInt2 % 2 == 0)
    {
        j = 1;
        i = paramInt1;
        paramInt1 = j;
        while (paramInt1 < 1000)
        {
            i += paramInt1;
            paramInt1 += 1;
        }
        return chec(i, paramInt2);
    }
    j = 1;
    i = paramInt1;
    paramInt1 = j;
    while (paramInt1 < 1000)
    {
        i -= paramInt1;
        paramInt1 += 1;
    }
    return chec(i, paramInt2);
}

int check3(int paramInt1, int paramInt2)
{
    int j = 1;
    int i = paramInt1;
    paramInt1 = j;
    while (paramInt1 < 10000)
    {
        i += paramInt1;
        paramInt1 += 1;
    }
    return chec(i, paramInt2);
}

int chec(int paramInt1, int paramInt2)
{
    int result = 0;
    if (paramInt2 - 1 <= 0)
    {
        return paramInt1;
    }
    else
    {
        int temp = paramInt2 - 1;
        switch (paramInt2 * 2 % 3)
        {
        case 0:
            result = check1(paramInt1, temp);
            break;
        case 1:
            result = check2(paramInt1, temp);
            break;
        case 2:
            result = check3(paramInt1, temp);
            break;

        default:
            fprintf(stderr, "Error");
            exit(-1);
            break;
        }
    }
    return result;
}

int check(int paramInt1, int paramInt2)
{
    return chec(paramInt1, paramInt2);
}

int main()
{
    puts("start");
    global_cpu_start = clock();
    global_start = time(NULL);
    int i;
    for (i = 0; i < 0x7fffffff; i++)
    {
        if (i % 0x1000000 == 0)
        {
            printf("Now i is %d\n", i);
        }
        if (check(i, 99) == 1835996258)
        {
            printf("Succeed, the value is %d\n", i);
            printf("Time of CPU taken: %lf seconds.\n",
                (double)(clock() - global_cpu_start) / (double)CLOCKS_PER_SEC);
            printf("Time of process taken: %ld seconds.\n",
                (time(NULL) - global_start));
            exit(0);
        }
    }
}
