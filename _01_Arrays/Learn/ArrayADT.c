#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *p;
    int size;
    int length;
};

struct Array arr1;

void printArray(struct Array arr)
{
    printf("Array Elements: ");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.p[i]);
    }
    printf("\n");
}

void get(int index)
{
    printf("%d",arr1.p[index]);
}

void set(int index, int value)
{
    arr1.p[index] = value;
}

void insert(int index, int value)
{
    if(arr1.length == arr1.size){
        printf("array full");
    }
    for (int i = arr1.length; i > index; i--)
    {
        arr1.p[i] = arr1.p[i - 1];
    }
    arr1.p[index] = value;
    arr1.length++;
}

void delete(int index)
{
    for (int i = index; i < arr1.length; i++)
    {
        arr1.p[i] = arr1.p[i + 1];
    }
    arr1.length--;
}

int main()
{
    int size;
    arr1.length = 0;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    arr1.p = (int *)malloc(arr1.size * sizeof(int));
    printf("Enter numbers: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr1.p[i]);
    }
    arr1.length = size;

    // insert(2,8);
    delete(2);
    printArray(arr1);
    return 0;
}