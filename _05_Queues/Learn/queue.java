package _05_Queues.Learn;

public class queue {
    public static void main(String[] args) {
        queueUsingArray queue = new queueUsingArray(5);
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        queue.enqueue(5);

        System.out.println(queue.peek());
        System.out.println(queue.dequeue());
        System.out.println(queue.peek());
        System.out.println(queue.size());
        System.out.println(queue.isEmpty());
        System.out.println(queue.dequeue());
        System.out.println(queue.dequeue());
        System.out.println(queue.dequeue());
        System.out.println(queue.dequeue());
        System.out.println(queue.isEmpty());
    }

    // implement queue using array
    static class queueUsingArray {
        int[] arr;
        int front;
        int rear;
        int capacity;

        queueUsingArray(int capacity) {
            this.capacity = capacity;
            this.arr = new int[capacity];
            this.front = -1;
            this.rear = -1;
        }

        void enqueue(int data) {
            if (rear == capacity-1) {
                System.out.println("Queue Overflow");
                return;
            }
            if (front == -1) {
                front++;
            }
            arr[++rear] = data;
        }

        int dequeue() {
            if (front == -1 || front > rear) {
                System.out.println("Queue Underflow");
                return -1;
            }
            return arr[front++];
        }

        int peek() {
            if (front == -1 || front > rear) {
                System.out.println("Queue Underflow");
                return -1;
            }
            return arr[front];
        }

        int size() {
            if (front == -1 || front > rear) {
                return 0;
            }
            return rear-front+1;
        }

        boolean isEmpty() {
            if (front == -1 || front > rear) {
                return true;
            }
            return false;
        }
    }
}
