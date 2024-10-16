//{ Driver Code Starts
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

public class Main {
    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while (t-- > 0) {
            List<Integer> arr = new ArrayList<>();
            String input = sc.nextLine();
            Scanner ss = new Scanner(input);

            while (ss.hasNextInt()) {
                arr.add(ss.nextInt());
            }

            Node head = new Node(arr.get(0));
            Node tail = head;

            for (int i = 1; i < arr.size(); ++i) {
                tail.next = new Node(arr.get(i));
                tail = tail.next;
            }

            Solution ob = new Solution();
            Node[] result = ob.alternatingSplitList(head);
            printList(result[0]);
            printList(result[1]);
        }

        sc.close();
    }
}

// } Driver Code Ends


// User function Template for Java
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
    // Function to append a new node with newData at the end of a linked list
    private void createAltList(Node head, Node x) {
        Node tmp=head;
        while(tmp!=null && tmp.next!=null && tmp.next.next!=null) {
            x.next=new Node(tmp.next.next.data);
            tmp=tmp.next.next;
            x=x.next;
        }
    }
    Node[] alternatingSplitList(Node head) {
        Node[] ans=new Node[2];
        Node head1=new Node(head.data);
        Node head2=null;
        createAltList(head,head1);
        if(head.next!=null) {
            head2=new Node(head.next.data);
            createAltList(head.next,head2);
        }
        ans[0]=head1;
        ans[1]=head2;
        return ans;
    }
}
