class node{
    int info;
    node next, prev;
    node(int info){
        this.info = info;
        next = prev = null;
    }
}

class dllDeletion{
    node head=null, tail=null;

    void addFromTail(int el){
        node newNode = new node(el);
        if(head == null){
            newNode.prev = newNode.next = null;
            head = tail = newNode;
        }
        else{
            tail.next = newNode;
            newNode.prev= tail;
            newNode.next=null;
            tail = newNode;
        }
    }
    int traverse(){
        node temp = head;
        int count = 0;
        while(temp != null){
            count++;
            temp = temp.next;
        }
        return count;
    }


    void deleteFromHead(){
        if(head==null) System.out.println("Empty List");
        else{
            System.out.println(head.info + " is removed from head");
            if(head == tail) head = tail = null;
            else{
                head = head.next;
                head.prev=null;
            }
        }
    }

    void deleteFromTail(){
        if(head==null) System.out.println("Empty List");
        else{
            System.out.println(tail.info + " is removed from tail");
            if(head==tail) head=tail=null;
            else{
                tail=tail.prev;
                tail.next=null;
            }
        }
    }

    void deleteAtPos(int pos){
        int size=traverse();
        if(head==null) System.out.println("Empty List");
        else if(pos<=0 || pos>size) System.out.println("Position Invalid");
        else{
            if(pos == 1) deleteFromHead();
            else if(pos == size) deleteFromTail();
            else{
                node temp = head;
                int count = 2;
                while(count!=pos){
                    temp=temp.next;
                    count++;
                }
                System.out.println(temp.next.info + " is removed from pos: " + pos);
                temp.next = temp.next.next;
                temp.next.prev=temp;
            }
        }
    }

    void display(){
        if(head==null) System.out.println("Empty List");
        else{
            System.out.println("Current Item on list:");
            node temp = head;
            while(temp != null){
                System.out.print(temp.info + "\t");
                temp = temp.next;
            }
            System.out.println("\n");
        }
    }
}

class dllDeletionImplement{
    public static void main(String[] args) {
        dllDeletion d = new dllDeletion();

        d.deleteFromHead();
        
        d.addFromTail(5);
        d.addFromTail(8);
        d.addFromTail(4);
        d.addFromTail(5);
        d.addFromTail(3);
        d.display();
        
        d.deleteFromHead(); 
        d.display();
        d.deleteFromTail(); 
        d.display();
        d.deleteAtPos(2);
        d.display();
    }
}