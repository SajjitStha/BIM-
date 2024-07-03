//Define a Node class representing a node in a linked list
class Node {
    int data;   // Data stored in the node
    Node next;  // Reference to the next node in the list

    // Constructor to initialize a node with given data
    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

// Define a LinkedList class representing a linked list
class LinkedList {
    private Node head;  // Reference to the first node in the list

    // Add a new node to the head of the list
    public void addToHead(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    // Remove the node from the head of the list
    public void removeFromHead() {
        if (head != null) {
            head = head.next;
        } else {
        System.out.println("The list is empty, can't remove from head.");
        }
    }

    // Remove the node from the tail of the list
    public void removeFromTail() {
        if (head == null) {
            System.out.println("The list is empty. Cannot remove from tail.");
            return;
        }

        if (head.next == null) {
            head = null;
            return;
        }

        Node current = head;
        while (current.next.next != null) {
            current = current.next;
        }

        current.next = null;
    }

    // Remove the node at the specified position (0-based index)
    public void removeFromKPos(int k) {
        if (k < 0 || head == null) {
            System.out.println("Invalid position or the list is empty.");
            return;
        }

        if (k == 0) {
            removeFromHead();
            return;
        }

        Node current = head;
        int count = 0;

        while (count < k - 1 && current.next != null) {
            current = current.next;
            count++;
        }

        if (count == k - 1 && current.next != null) {
            current.next = current.next.next;
        } else {
            System.out.println("Invalid position.");
        }
    }

    // Search for a value in the list
    public boolean search(int value) {
        Node current = head;
        while (current != null) {
            if (current.data == value) {
                return true;
            }
            current = current.next;
        }
        return false;
    }

    // Display the elements of the list
    public void display() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }
}

// Main class for testing the LinkedList operations
public class Main {
    public static void main(String[] args) {
        // Create an instance of the LinkedList class
        LinkedList linkedList = new LinkedList();

        // Adding elements to the list
        linkedList.addToHead(8);
        linkedList.addToHead(4);
        linkedList.addToHead(2);
        linkedList.addToHead(1);

        // Displaying the initial list
        System.out.print("Initial List: ");
        linkedList.display();

        // Performing operations
        linkedList.removeFromHead();
        System.out.print("After removing from the head: ");
        linkedList.display();

        linkedList.removeFromTail();
        System.out.print("After removing from the tail: ");
        linkedList.display();

        linkedList.removeFromKPos(1);
        System.out.print("After removing from the position: ");
        linkedList.display();

        // Searching for values in the list
        System.out.println("Search for 2: " + linkedList.search(2));
        System.out.println("Search for 4: " + linkedList.search(4));
    }
}