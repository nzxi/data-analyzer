#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char data;

    FILE *file = fopen("data", "r");

    if (file == NULL)
    {
        printf("Opening file failed!\n");
        return 1;
    }

    int capacity = 10;
    int size = 0;
    int *arr = malloc(capacity * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    int num;
    while (fscanf(file, "%d", &num) == 1)
    {
        if (size == capacity) {
            capacity *= 2;
            arr = realloc(arr, capacity * sizeof(int));
            if (arr == NULL) {
                printf("Memory realllocation failed!\n");
                return 1;
            }
        }

        arr[size] = num;
        size++;
    }

    fclose(file);
    long long sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    double average = (double)sum / size;
    printf("Average number in data: %.2f\n", average);

    printf("\n");
    free(arr);
    return 0;
}