import java.util.NoSuchElementException;
public class Test<T> {
    private Node head;
    private Node tail;
    private int size;
 
    public Test() {
        size = 0;
    }
 
    private class Node {
        T element;
        Node next;
        Node prev; 
        public Node(T element, Node next, Node prev) {
            this.element = element;
            this.next = next;
            this.prev = prev;
        }
    }
 
    public int size() {
    	return size; 
    }     
 
    public boolean isEmpty() {
    	return size == 0; 
    }
 
    public void addFirst(T element) {
        Node tmp = new Node(element, head, null);
        if(head != null ) {
        	head.prev = tmp;
        }
        head = tmp;
        if(tail == null) {
        	tail = tmp;
       }
        size++;
        System.out.println("Adding element: "+element);
    }
 
    public void addLast(T element) {         
        Node tmp = new Node(element, null, tail);
        if(tail != null) {
        	tail.next = tmp;
        }
        tail = tmp;
        if(head == null) {
        	head = tmp;
        }
        size++;
        System.out.println("Adding element: "+element);
    }
 
    public void iterateForward(){         
        System.out.println("Iterating forward.");
        Node tmp = head;
        while(tmp != null){
            System.out.println(tmp.element);
            tmp = tmp.next;
        }
    }
 
 
    public void iterateBackward(){         
        System.out.println("Iterating backword.");
        Node tmp = tail;
        while(tmp != null){
            System.out.println(tmp.element);
            tmp = tmp.prev;
        }
    }
 
    public T removeFirst() {
        if (size == 0) throw new NoSuchElementException();
        Node tmp = head;
        head = head.next;
        head.prev = null;
        size--;
        System.out.println("Deleted element: "+tmp.element);
        return tmp.element;
    }
 
    public T removeLast() {
        if (size == 0) throw new NoSuchElementException();
        Node tmp = tail;
        tail = tail.prev;
        tail.next = null;
        size--;
        System.out.println("Deleted element: "+tmp.element);
        return tmp.element;
    }
 
	public static void main(String args[]){
		try {
			Test<Integer> linkedlist = new Test<Integer>();
			linkedlist.addFirst(14);
			linkedlist.addFirst(546);
			linkedlist.addLast(36);
			linkedlist.iterateForward();
			linkedlist.removeFirst();
			linkedlist.removeLast();
			linkedlist.iterateBackward();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}