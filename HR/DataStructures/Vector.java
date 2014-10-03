import java.util.*;

public class Vector<T> {
    private T [] a;
    private int size;
    private int capacity;
	public Vector() {
		a = (T [])(new Object[10]);
        size = 0;
        capacity = 10;
	}
    public void push_back(T x) {
        if (size == capacity) {
            capacity *= 2;
            T [] A = (T [])(new Object[capacity]);
            for (int i = 0 ; i < size ; i ++)
                A[i] = a[i];
            A[size ++] = x;
            a = A;
        } else {
            a[size ++] = x;
        }
    }
    public void pop_back() throws Exception {
        if (size == 0) throw new Exception("popping empty vector");
        size --;
        if (capacity > 10 && 2*size <= capacity) {
            capacity /= 2;
            T [] A = (T [])(new Object [capacity]);
            for (int i = 0 ; i < size ; i ++)
                A[i] = a[i];
            a = A;
        }
    }
    public T back() throws Exception {
        if (size == 0) throw new Exception("vector is empty");
        return a[size - 1];
    }
    public int size() {
        return size;
    }
    public int capacity() {
        return capacity;
    }
    public void clear() {
        capacity = 10;
        size = 0;
        a = (T [])(new Object[capacity]);
    }
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0 ; i < size - 1 ; i ++)
            sb.append(a[i].toString() + ", ");
        if (size >= 1)
            sb.append(a[size - 1].toString());
        sb.append("]");
        return sb.toString();
    }
    public T get(int index) {
        if (index < 0 || index >= size)
            throw new ArrayIndexOutOfBoundsException("Vector out of bounds");
        return a[index];
    }
    public static void main(String args[]) throws Exception {
        Vector<Integer> v = new Vector<Integer>();
        for (int i = 1 ; i <= 45 ; i ++) {
            v.push_back(i);
            System.out.println(v);
        }
        for (int i = 0 ; i < v.size() ; i ++)
            System.out.print(v.get(i) + " " ) ;
        System.out.println();
        System.out.println("Capacity:" + v.capacity());
        for (int i = 1 ; i <= 45 ; i ++) {
            v.pop_back();
            System.out.println(v);
        }
        System.out.println("Capacity:" + v.capacity());
    }
}
