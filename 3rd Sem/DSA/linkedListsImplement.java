class node{
    int info; // the data
    node next; // the next node address

    node(int info){
        this(info, null);
    }
    node(int info, node nextNode){
        this.info = info;
        next = nextNode;
    }
}

class linkedLists {
    node head = null; // initially no data
    node tail = null; 

    void addFromHead(int el){ 
        /*  if head-->|a1|null|<--tail exists then
            now adding |a2| | the location should be head, as head is pointing to the 1st location
            |a2|head|-->|a1|null|, but now new element should be the head
            head-->|a2|a1 add|-->|a1|null|
        */
        node newNode;
        if(head == null){ // if no linked list is formed
            newNode = new node(el, null); // adding the data section
            head = tail = newNode; // 1st element so head and tail is that element
        }
        else{
            newNode = new node(el, head); // if old linked lists exists, head contains old data address
            head = newNode; // but now head is the new list that is formed
        }
    }

    void addFromTail(int el){
        /*  if head-->|a1|null|<--tail exists and new element to be added from tail, 
            tail points to a1 so, 
            head-->|a1|a2-add(tail.next)|-->|a2|null|<--tail
        */
        node newNode;
        if(head == null){ // if no linked list os formed, same as above
            newNode = new node(el);
            head = tail = newNode;
        }
        else{
            newNode = new node(el); // add a new node
            tail.next = newNode; // the old element should point to new so, tail contains old element, tyesko next should contain new element ko address
            tail = newNode; // head remains the same, as adding from tail so new element becomes tail
        }
    }

    void addAtPos(int el, int pos){
        int count=1, flag=0;
        node prev = head;
        node newNode = null;

        if(head==null){
            if(pos == 1){ //if no node and at pos 1, add anew node
                addFromHead(el);
            }
            else System.out.println("No List Found");
        }
        else if(pos==1){ //if at pos 1 just add before 1
            addFromHead(el);
        }
        else{ // else
            while(count<=pos && prev != null){ // loop prev through all nodes or to count
                count++;
                if(count == pos){ // if pos is equal to count
                    newNode = new node(el, prev.next); //add to next
                    prev.next = newNode;
                    flag = 1;
                }
                prev = prev.next;
            }
            if(newNode.next == null){
                tail = newNode;
            }
            if(flag == 0){
                System.out.println("\nIndex Out of Range");
            }
        }
    }

    void deleteFromHead(){
        /*  if head-->|a1|head.next|-->|a2|a3-add|-->|a3|null|<--tail
         *  simply move head to next element i.e. a2-address or head.next
            head-->|a2|a3-add|-->|a3|null|<--tail
         */ 
        if(head == null) System.out.println("No List Found");

        else if(head == tail) head=tail=null; // if only one element exists, null
        
        else head = head.next; // else the next element becomes head
    }

    void deleteFromTail(){
        /* if head-->|a1|a2-add|-->|a2|a3-add|-->|a3|null|<--tail
         * travel from head to a2 (second last element then)
         * a3-add ko satta null, and tail = a2 ko location
         * head-->|a1|a2-add|-->|a2|null|<--tail
         */     
        if(head == null) System.out.println("No List Found");

        if(head == tail) head=tail=null; // if only one element, then null
        
        else{
            node temp = head;
            while(temp.next != tail){ // loop to the second last element
                temp = temp.next;
            }
            temp.next = null; // make the pointer of second last element null
            tail = temp; // the tail should now be the second last element
        }
    }

    void deleteAtPos(int pos){
        if(head == null) System.out.println("No List Found");

        else if(head==tail && pos == 1) head = tail = null;
        
        else if(pos == 1) deleteFromHead();
        
        else{
            int count = 2, flag = 0;
            node prev = head, temp = head.next;
            while(temp != null){
                if(count == pos){
                    prev.next = temp.next;
                    flag = 1; break;
                }
                count++; 
                prev = temp; temp = temp.next;
            }
            if(prev.next == null){
                tail = prev;
            }
            if(flag == 0){
                System.out.println("Position Out of Index");
            }
        }
    }

    void delete(int el){  
        node temp = head; 
        node prev = head; // traverse through one step back
        int flag = 0;

        if(head == tail && head.info == el){ //if one list and that is the element, delete the list 
            head = tail = null;
            flag = 1;
        }

        else if(head.info == el){ // multiple lists, and if head itself contains the element delete the head
            head = head.next;
            flag = 1;
        }   

        else{
            while(temp != null){ // loop through all lists
                if(temp.info == el){ // if element found, |a1|prev.next|-->|a2|temp.next|-->|a3|some address|
                    prev.next = temp.next; //previous points to the next of temp, so a2 gets deleted
                    flag++;
                    break;
                }
                prev = temp; //previous stays one list behind
                temp = temp.next; //temp traverse through the lists
            }
            if(prev.next == null){
                tail = prev;
            }
        }

        if(flag == 0){
            System.out.println("Element not Found");
        }
    }

    void search(int key){
        node temp = head; // start from head
        int flag = 0, count = 1;
        while(temp != null){ // traverse through all nodes
            if(temp.info == key){ //if element found on that node, display
                System.out.println(key + " found at node: " + temp + "at position: " + count);
                flag = 1;
                break;
            }
            count++;
            temp = temp.next;
        }
        if(flag == 0){
            System.out.println(key + " not found on list");
        }
    }

    void display(){
        node temp = head; 
        while(temp != null){ // starting from head traverse through all of the nodes 
            System.out.print(temp.info + " ");
            temp = temp.next;
        }
    }

}

class linkedListsImplement{
    public static void main(String[] args) {
        linkedLists l = new linkedLists();

        //adding elements
        l.addFromHead(10);
        l.addFromHead(12);
        l.addFromHead(44);
        l.addFromTail(22);
        l.addFromTail(5);
        l.addFromTail(25);
        l.addFromTail(102);
        l.addFromTail(56);

        // deleting from head, tail, & paritcular element
        System.out.println("\nBefore Deletion: ");
        l.display();

        l.deleteFromHead();
        l.deleteFromTail();
        l.delete(10);
        System.out.println("\nAfter Deletion: ");
        l.display();

        l.addAtPos(122, 6);
        System.out.println("\nAdding 122 at pos 6");
        l.display();

        l.deleteAtPos(6);
        System.out.println("\nAfter deletion at pos 6");
        l.display();

        //searching for an existing element
        System.out.println("\n\nSearching for element 12:");
        l.search(25);

        //searching for an non-exisiting element
        System.out.println("\nSearching for element 122:");
        l.search(122);
    }
}
