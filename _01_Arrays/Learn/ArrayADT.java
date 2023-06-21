import java.util.Scanner;

public class ArrayADT {
    static class Array {
        int[] p;
        int lenght;
        int size;
    }

    static Array arr1 = new Array();

    public static void printArray(Array arr) {
        System.out.print("Array Elements: ");
        for (int i = 0; i < arr1.lenght; i++) {
            System.out.print(arr1.p[i] + " ");
        }
        System.out.println();
    }

    public static void get(int index) {
        System.out.println(arr1.p[index]);
    }
    
    public static void set(int index, int val) {
        arr1.p[index] = val;
    }
    
    public static void insert(int index, int value) {
        if (arr1.lenght == arr1.size) {
            System.out.println("array full");
        }
        for (int i = arr1.lenght; i > index; i--) {
            arr1.p[i] = arr1.p[i - 1];
        }
        arr1.p[index] = value;
        arr1.lenght++;
    }

    public static void delete(int index) {
        for (int i = index; i < arr1.lenght - 1; i++) {
            arr1.p[i] = arr1.p[i + 1];
        }
        arr1.lenght--;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        arr1.lenght = 0;
        System.out.print("Enter size of the Array: ");
        int size = sc.nextInt();
        arr1.p = new int[size];
        System.out.print("Enter elements: ");
        for (int i = 0; i < size; i++) {
            arr1.p[i] = sc.nextInt();
        }
        arr1.lenght = size;
        printArray(arr1);
        set(2, 8);
        printArray(arr1);
        delete(2);
        printArray(arr1);

        sc.close();
    }
}
