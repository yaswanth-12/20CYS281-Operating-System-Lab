#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void *fibinocci(void *a)
{

    int *p = (int *)a;
    int fact0 = 0;
    int fact1 = 1;
    int tmp;
    printf("0\n");
    printf("1\n");
    for (int i = *p; i > 2; i--)
    {
        tmp = fact1;
        fact1 = fact0 + fact1;
        fact0 = tmp;
        printf("%d\n", fact1);
    }
}

int main()
{

    pthread_t threads;
    int t;
    printf("Enter the sequencelength : ");
    scanf("%d", &t);
    pthread_create(&threads, NULL, fibinocci, (void *)&t);
    pthread_join(threads, NULL);
}