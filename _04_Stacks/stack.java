package _04_Stacks;

public class stack {
    public static void main(String[] args) {
        stackUsingArray stack = new stackUsingArray(5);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.push(6);
        System.out.println(stack.peek());
        System.out.println(stack.pop());
        System.out.println(stack.peek());
        System.out.println(stack.size());
        System.out.println(stack.isEmpty());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.isEmpty());
    }

    // implement stack using array
    static class stackUsingArray {
        int[] arr;
        int top;
        int capacity;

        stackUsingArray(int capacity) {
            this.capacity = capacity;
            this.arr = new int[capacity];
            this.top = -1;
        }

        void push(int data) {
            if (top == capacity-1) {
                System.out.println("Stack Overflow");
                return;
            }
            arr[++top] = data;
        }

        int pop() {
            if (top == -1) {
                System.out.println("Stack Underflow");
                return -1;
            }
            return arr[top--];
        }

        int peek() {
            if (top == -1) {
                System.out.println("Stack Underflow");
                return -1;
            }
            return arr[top];
        }

        boolean isEmpty() {
            return top == -1;
        }

        int size() {
            return top+1;
        }
    }

}
