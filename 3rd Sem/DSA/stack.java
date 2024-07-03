class stackImplementation {
    int top = -1;
    int MAX = 10;
    int[] stack = new int[MAX];

    void push(int el) {
        if (top == MAX)
            System.out.println("Stack Overflow");
        else {
            System.out.println(el + " is inserted in stack");
            top++;
            stack[top] = el;
        }
    }

    void pop() {
        if (top == -1)
            System.out.println("Empty Stack");
        else {
            System.out.println(stack[top] + " is removed");
            top--;
        }
    }

    void search(int key) {
        int flag = 0;
        for (int i = top; i >= 0; i--) {
            if (key == stack[i]) {
                System.out.println(key + " is found");
                flag++;
                break;
            }
        }
        if (flag == 0)
            System.out.println(key + " is not found");

    }

    void display() {
        if (top == -1)
            System.out.println("Empty Stack");
        else {
            System.out.println("Current Elements Are:");
            for (int i = top; i >= 0; i--) {
                System.out.println(stack[i]);
            }
            System.out.println();
        }
    }
}

class stack {
    public static void main(String[] args) {
        stackImplementation s = new stackImplementation();
        s.push(1);
        s.push(2);
        s.push(3);
        s.display();
        s.pop();
        s.display();
        s.search(2);
    }
}