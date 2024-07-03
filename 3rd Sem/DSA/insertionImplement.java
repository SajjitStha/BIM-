class node{
    int info;
    node next;
    node(int el){
        info = el;
        next = null;
    }
}

class SLLInsertion{
    node head = null, tail = null;
    
    void addFromHead(int info){
        node newNode = new node(info);
        if(head == null){
            newNode.next = null;
            head = tail = newNode;
        }
        else{
            newNode.next = head;
            head = newNode;
        }
    }

    void addFromTail(int info){
        node newNode = new node(info);
        if(head == null){
            newNode.next = null;
            head = tail = newNode;
        }
        else{
            tail.next = newNode;
            tail = newNode;
        }
    }

    void addAtPos(int info, int pos){
        node newNode = new node(info);
        if(head == null){
            if(pos == 1) addFromHead(info);
            else System.out.println("No List Found and Invalid Position");
        }
        else if(pos == 1) addFromHead(info);

        else{
            int count = 2, flag = 0;
            node temp = head;
            while(temp!=null && count<=pos){
                if(count == pos){
                    newNode.next = temp.next;
                    temp.next = newNode;
                    flag = 1;
                }
                temp = temp.next;
                count++;
            }
            if(newNode.next == null) tail = newNode;

            if(flag == 0) System.out.println("Invalid Position");
        }
    }

    void display(){
        if(head == null) System.out.println("No List Found");
        else{
            node temp = head;
            while(temp != null){
                System.out.print(temp.info + "\t");
                temp = temp.next;
            }
            System.out.println();
        }
    }
}

public class insertionImplement {
    public static void main(String[] args) {
        SLLInsertion ins = new SLLInsertion();

        ins.addFromHead(1);
        ins.addFromHead(0);
        ins.addFromTail(2);
        ins.addAtPos(4, 3);
        ins.addAtPos(4, 6);
        ins.addAtPos(3, 3);
        ins.display();
    }    
}