class node{
    int info;
    node next;
    node(int el){
        info = el;
        next = null;
    }
}

class sllimp {
    node head = null,tail = null; 
    void addFromHead(int info)
    {
        node newnode = new node(info);
        if(head==null)
        {
            newnode.next = null;
            head = tail= newnode;
        }
        else{
            newnode.next=head;
            head=newnode;
        }

    }

    void addfromtail(int info)
    {
        node newnode = new node(info);
        if(head==null)
        {
            newnode.next=null;
            head=tail=newnode;
        }
        else{
            tail.next=newnode;
            tail=newnode;
        }

    }
    void display()
    {
        if(head ==null) System.out.print("No list");
        else
        {
            node temp = head;
            while(temp!=null)
            {
                System.out.print(temp.info+"\t");
                temp = temp.next;
            }
        }

    }
    
}
class sll{
    public static void main(String[] args)
    {
        sllimp s = new sllimp();
        s.addFromHead(989);
        s.addFromHead(11);
        s.addFromHead(20);
        s.addfromtail(10);
        s.addfromtail(23);
        s.display();
    }
}

