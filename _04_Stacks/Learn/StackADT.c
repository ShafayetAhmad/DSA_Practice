#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int *arr;
};

struct Stack st;

void printStack()
{
    printf("Elements in stack: ");
    for (int i = 0; i < st.size; i++)
    {
        printf("%d ", st.arr[i]);
    }
    printf("\n");
}

void push(int value)
{
    st.arr[++st.top] = value;
    printf("%d %d\n", st.top, st.size);
    if (st.top >= st.size)
    {
        printf("%d %d", st.top, st.size);
        printf("Stack Overflow");
        return;
    }
}

void pop()
{
    if (st.top == -1)
    {
        printf("Stack Underflow");
        return;
    }
    st.top--;
}

int isEmpty()
{
    if (st.top == -1)
    {
        return 1;
    }
    return 0;
}

void peek()
{
    if(isEmpty()){
        printf("Stack is empty");
        return;

    }
    printf("%d", st.arr[st.top]);
}

int pop(){
    if(isEmpty()){
        printf("Stack is empty");
        return -1;
    }
    return st.arr[st.top--];
}

int main()
{
    int size;
    st.top = -1;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    st.arr = (int *)malloc(size * sizeof(int));
    st.size = size;

    for (int i = 0; i < size; i++)
    {
        int value;
        printf("Enter value to push: ");
        scanf("%d", &value);
        push(value);
    }

    printStack();

    return 0;
}