// package hw3.p1;

import edu.princeton.cs.algs4.StdOut;
import java.util.StringJoiner;

public class QDriver {
        public static void main(String[] args) {

        test1();
        test2();
        test3();
        test4();
    }

    public static  void test1() {
        StdOut.println("Test1:");

        Deque<String> deque = new Deque<>();
        deque.pushLeft("a");
        deque.pushLeft("b");
        deque.pushLeft("c");

        StringJoiner dequeItems = new StringJoiner(" ");
        for (String item : deque) {
            dequeItems.add(item);
        }

        StdOut.println("Deque items: " + dequeItems.toString());
        StdOut.println("Expected: c b a");
    }

    public static  void test2() {
        StdOut.println("\nTest2:");
        Deque<Double> deque = new Deque<>();
        deque.pushRight(-87.50);
        deque.pushRight(100.0);
        deque.pushRight(234.02);

        StringJoiner dequeItems = new StringJoiner(" ");
        for (double item : deque) {
            dequeItems.add(String.valueOf(item));
        }

        StdOut.println("Deque items: " + dequeItems.toString());
	StdOut.println("Expected:  -87.50 100.0 234.02");
    }

    public static  void test3() {
        StdOut.println("\nTest3:");

        Deque<String> deque = new Deque<>();
        deque.pushRight("the");
        deque.pushRight("time");
        deque.pushRight("has");

        deque.popLeft();
        deque.popLeft();

        StringJoiner dequeItems = new StringJoiner(" ");
        for (String item : deque) {
            dequeItems.add(item);
        }

        StdOut.println("Deque items: " + dequeItems.toString());
        StdOut.println("Expected: has");
    }

    public static  void test4() {
        StdOut.println("\nTest4:");

        Deque<Integer> deque = new Deque<>();
        deque.pushRight(312);
        deque.pushRight(100);
        deque.pushRight(-89);

        deque.popRight();
        deque.popRight();

        StringJoiner dequeItems = new StringJoiner(" ");
        for (int item : deque) {
            dequeItems.add(String.valueOf(item));
        }

        StdOut.println("Deque items: " + dequeItems.toString());
        StdOut.println("Expected: 312");
    }
}
