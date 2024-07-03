class node {
    int info;
    node next, prev;

    node(int el) {
        info = el;
        next = prev = null;
    }
}

class doublyCircular {
    node head = null, tail = null;

    void addFromHead(int el) {
        node newNode = new node(el);
        System.out.println(el + " added in head");
        if (head == null) {
            newNode.next = newNode.prev = null;
            head = tail = newNode;
        } else {
            newNode.next = head;
            newNode.prev = tail;
            head.prev = newNode;
            head = newNode;
            tail.next = newNode;
        }
    }

    void addFromTail(int el) {
        node newNode = new node(el);
        System.out.println(el + " added in tail");
        if (head == null) {
            newNode.next = newNode.prev = newNode;
            head = tail = newNode;
        } else {
            newNode.next = head;
            newNode.prev = tail;
            head.prev = newNode;
            tail.next = newNode;
            tail = newNode;
        }
    }

    void addAtPos(int el, int pos) {
        int size = traverse();
        if (head == null && pos != 1)
            System.out.println("Invalid Position");
        else if (pos < 0 || pos > size + 1)
            System.out.println("Invalid Position");
        else {
            if (pos == 1)
                addFromHead(el);
            else if (pos == size + 1)
                addFromTail(el);
            else {
                System.out.println(el + " added at pos " + pos);
                node newNode = new node(el);
                int count = 2;
                node temp = head;
                while (count < pos) {
                    temp = temp.next;
                    count++;
                }
                newNode.prev = temp;
                newNode.next = temp.next;
                temp.next = newNode;
                newNode.next.prev = newNode;
            }
        }
    }

    void deleteFromHead() {
        if (head == null)
            System.out.println("Empty List");
        else {
            System.out.println(head.info + " is removed from head");
            head = head.next;
            head.prev = tail;
            tail.next = head;
        }
    }

    void deleteFromTail() {
        if (head == null)
            System.out.println("Empty List");
        else {
            System.out.println(tail.info + " is removed from tail");
            tail = tail.prev;
            tail.next = head;
        }
    }

    void deleteAtPos(int pos) {
        int size = traverse();
        if (head == null)
            System.out.println("Empty List");
        else if (pos <= 0 || pos > size)
            System.out.println("Position Invalid");
        else {
            if (pos == 1)
                deleteFromHead();
            else if (pos == size)
                deleteFromTail();
            else {
                node temp = head;
                int count = 2;
                while (count != pos) {
                    temp = temp.next;
                    count++;
                }
                System.out.println(temp.next.info + " is removed from pos: " + pos);
                temp.next = temp.next.next;
                temp.next.prev = temp;
            }
        }
    }

    void display() {
        if (head == null)
            System.out.println("Empty List");
        else {
            node temp = head;
            System.out.println("Current Items on Lists: ");
            while (temp.next != head) {
                System.out.print(temp.info + "\t");
                temp = temp.next;
            }
            System.out.println(temp.info);
            System.out.println();
        }
    }

    int traverse() {
        node temp = head;
        int count = 0;
        while (temp.next != head) {
            temp = temp.next;
            count++;
        }
        count++;
        return count;
    }
}

class doublyCircularImplement {
    public static void main(String[] args) {
        doublyCircular d = new doublyCircular();
        d.addFromHead(5);
        d.addFromHead(8);

        d.addFromTail(3);
        d.addFromTail(2);
        d.addFromTail(6);

        d.display();

        d.addAtPos(4, 4);

        d.display();

        d.deleteAtPos(2);

        d.display();

        d.deleteFromHead();
       
        d.display();
        
         d.deleteFromTail();
         d.display();
    }

}