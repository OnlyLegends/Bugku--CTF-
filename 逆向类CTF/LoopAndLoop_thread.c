#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#ifdef __GNUC__
#include <pthread.h>
#endif

// 设置线程数，具体的数值看个人机器
#define THREAD 10

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

#ifdef _WIN32
DWORD WINAPI run(LPVOID p)
#else
void run(void *p)
#endif
{
    int i;
    for (i = *(int *)p ; i < 0x7fffffff; i+=THREAD)
    {
        if (i % 0x1000000 == 0)
        {
            printf("Now i is %d\n", i);
        }
        // printf("Now i is %d\n", i);
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

int main()
{
    int i, arg[THREAD];
#ifdef __GNUC__
    pthread_t thread[THREAD];
#endif

#ifdef _WIN32
    //HANDLE thread[THREAD];
#endif
    puts("start");
    global_cpu_start = clock();
    global_start = time(NULL);

#ifdef __GNUC__
    // 启动线程
    for(i =0 ;i < THREAD; i++)
    {
        arg[i] = i;
        pthread_create(&thread[i], NULL, (void *)&run, (void *)&arg[i]);
    }

    // 等待线程
    for(i = 0;i < THREAD; i++)
    {
        pthread_join(thread[i],NULL);
    }
#endif
}
