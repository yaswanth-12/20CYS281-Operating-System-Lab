#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void *factorial(void *a)
{

    int *p = (int *)a;
    int fact = 1;
    for (int i = *p; i >= 1; i--)
    {
        fact = fact * i;
    }
    printf("factorial is %d\n", fact);
}

int main()
{

    pthread_t threads;
    int t;
    scanf("%d", &t);
    pthread_create(&threads, NULL, factorial, (void *)&t);
    pthread_join(threads, NULL);
}