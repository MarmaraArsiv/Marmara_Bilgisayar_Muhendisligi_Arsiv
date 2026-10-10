public class DoubleLL {
    Node head;
    public void baslat(int id){
        head=new Node(id);
    }
    public void SonaElemanEkle(int id){
        Node newNode=new Node(id);
        Node temp=head;
        while (temp.next!=null){
            temp=temp.next;
        }
        temp.next=newNode;
        newNode.prev=temp;
    }
    public void yazdir(){
        if (head==null){
            System.out.println("Liste bos.");
        }
        Node temp=head;
        while (temp!=null){
            System.out.println("Sayi: " + temp.id);
            temp=temp.next;
        }
    }
    public void elemanAra(int id){
        Node temp=head;
        while (temp!=null){
            if (temp.id==id){
                System.out.println( id + " elemani listede bulunuyor.");
                return;
            }
            temp=temp.next;
        }
        System.out.println("Eleman bulunamadi.");
    }

    public void sayici(){
        if(head==null){
            System.out.println("Liste bos.");
        }
        int sayac=0;
        Node temp=head;
        while (temp!=null){
            sayac=sayac+1;
            temp=temp.next;
        }
        System.out.println("Bagli listede " + sayac + " tane eleman bulunuyor.");
    }
    public void basaElemanEkle(int id){
        Node newNode=new Node(id);
        newNode.next=head;
        head.prev=newNode;
        head=newNode;
    }
    public void sil(int id){
        if(head==null){
            System.out.println("Liste bos.");
        }
        if(head.id==id){
            head.next.prev=null;
            head=head.next;
            return;
        }
        Node temp=head;
        while (temp!=null){
            if (temp.next.id==id){
                temp.next=temp.next.next;
                temp.next.prev=temp;
                return;
            }
            temp=temp.next;
        }

    }
    public void yazdirDetayli() {
        if (head == null) {
            System.out.println("Liste bos.");
            return;
        }
        Node temp = head;
        while (temp != null) {
            String prevValue = (temp.prev != null) ? String.valueOf(temp.prev.id) : "null";
            String nextValue = (temp.next != null) ? String.valueOf(temp.next.id) : "null";
            System.out.println("Önceki: " + prevValue + " | Mevcut: " + temp.id + " | Sonraki: " + nextValue);
            temp = temp.next;
        }
    }

}
