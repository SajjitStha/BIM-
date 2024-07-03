class cQueueImplement {
    int MAX = 5;
    int[] queue = new int[MAX];
    int front = -1;
    int rear = -1;

    void enQueue(int el) {
        if (!isFull()) {
            System.out.println(el + " is added to Queue");
            if (front == -1)
                front = 0;
            rear = (rear + 1) % MAX;
            queue[rear] = el;
        }
    }

    void deQueue() {
        if (!isEmpty()) {
            System.out.println(queue[front] + " is removed from Queue");
            if (front == rear)
                front = rear = -1;
            else
                front = (front + 1) % MAX;
        }
    }

    void display() {
        if (!isEmpty()) {
            int i;
            for (i = front; i != rear; i = (i + 1) % MAX) {
                System.out.print(queue[i] + "\t");
            }
            System.out.println(queue[i] + "\n");
        }
    }

    void search(int key) {
        if (!isEmpty()) {
            int i, pos = 1;
            for (i = front; i != rear; i = (i + 1) % MAX) {
                if (queue[i] == key) {
                    System.out.println(key + " is found at Pos: " + pos);
                    return;
                }
                pos++;
            }
            if (queue[i] == key) {
                System.out.println(key + " is found at Pos: " + pos);
                return;
            }
            System.out.println(key + " not found in Queue");
        }
    }

    boolean isFull() {
        if ((rear + 1) % MAX == front) {
            System.out.println("Queue is Full!");
            return true;
        }
        return false;
    }

    boolean isEmpty() {
        if (front == -1) {
            System.out.println("Empty Queue!");
            return true;
        }
        return false;
    }
}

public class circularQueue {
    public static void main(String[] args) {
        cQueueImplement q = new cQueueImplement();
        q.enQueue(1);
        q.enQueue(2);
        q.enQueue(3);
        q.enQueue(4);
        q.enQueue(5);

        q.display();

        q.deQueue();
        q.display();

        q.enQueue(56);
        q.display();

        q.search(5);
        q.search(16);
    }
}