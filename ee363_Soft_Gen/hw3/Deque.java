// package edu.princeton.cs.algs4;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item>
{
  private int n;         // number of elements on queue
  private Node first;    // beginning of queue
  private Node last;     // end of queue

  // helper linked list class
  private class Node {
      private Item item;
      private Node next;
      private Node prev;
  }

  /**
   * Initializes an empty queue.
   */
  public Deque() {
      first = null;
      last  = null;
      n = 0;
      // assert check();
  }

  /**
   * Is this queue empty?
   * @return true if this queue is empty; false otherwise
   */
  public boolean isEmpty() {
      return first == null;
  }

  /**
   * Returns the number of items in this queue.
   * @return the number of items in this queue
   */
  public int size() {
      return n;
  }

  /**
   * Adds the item to this queue.
   * @param item the item to add
   */
  public void pushLeft(Item item) {
    Node oldfirst = first;
    first = new Node();
    first.item = item;
    first.next = oldfirst;
    n++;
  }
  public void pushRight(Item item) {
    Node oldlast = last;
    last = new Node();
    last.item = item;
    last.next = null;

    if (isEmpty()) first = last;
    else           oldlast.next = last;
    last.prev = oldlast;
    n++;
  }

  /**
   * Removes and returns the item on this queue that was least recently added.
   * @return the item on this queue that was least recently added
   * @throws java.util.NoSuchElementException if this queue is empty
   */
  public Item popLeft() {
    if (isEmpty()) throw new NoSuchElementException("Queue underflow L");
    Item item = first.item;
    first = first.next;
    n--;
    if (isEmpty()) last = null;   // to avoid loitering
    // assert check();
    return item;
  }

  public Item popRight() {
      if (isEmpty()) throw new NoSuchElementException("Queue underflow R");
      Item item = last.item;
      last = last.prev;
      last.next = null;
      n--;
      if (isEmpty()) first = null;   // to avoid loitering
      // assert check();
      return item;
  }


  /**
   * Returns a string representation of this queue.
   * @return the sequence of items in FIFO order, separated by spaces
   */
  public String toString() {
      StringBuilder s = new StringBuilder();
      for (Item item : this)
          s.append(item + " ");
      return s.toString();
  }

  public Iterator<Item> iterator()  {
      return new ListIterator();
  }

  // an iterator, doesn't implement remove() since it's optional
  private class ListIterator implements Iterator<Item> {
      private Node current = first;

      public boolean hasNext()  { return current != null;                     }
      public void remove()      { throw new UnsupportedOperationException();  }

      public Item next() {
          if (!hasNext()) throw new NoSuchElementException();
          Item item = current.item;
          current = current.next;
          return item;
      }
  }
}
