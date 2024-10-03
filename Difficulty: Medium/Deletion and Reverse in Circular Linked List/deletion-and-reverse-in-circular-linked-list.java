//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class LinkedList {
    // Function to print nodes in a given circular linked list
    static void printList(Node head) {
        if (head == null) {
            System.out.println("empty");
            return;
        }
        Node temp = head;
        do {
            System.out.print(temp.data + " ");
            temp = temp.next;
        } while (temp != head);
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            List<Integer> arr = new ArrayList<>();
            String input = br.readLine();
            StringTokenizer st = new StringTokenizer(input);
            while (st.hasMoreTokens()) {
                arr.add(Integer.parseInt(st.nextToken()));
            }
            int key = Integer.parseInt(br.readLine());
            Node head = new Node(arr.get(0));
            Node tail = head;
            for (int i = 1; i < arr.size(); ++i) {
                tail.next = new Node(arr.get(i));
                tail = tail.next;
            }
            tail.next = head; // Make the list circular
            Solution ob = new Solution();
            Node current = ob.deleteNode(head, key);
            Node rev = ob.reverse(current);
            printList(rev);
        }
    }
}

// } Driver Code Ends


/*class Node
{
    int data;
    Node next;
    Node(int d)
    {
        data=d;next=null;
    }
}*/

class Solution {
    Node reverse(Node head) {
        if(head==null || head.next==head) return head;
        Node curr=head,prev=null;
        do {
            Node next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        } while(curr!=head);
        curr.next=prev;
        return prev;
    }

    Node deleteNode(Node head, int key) {
        if(head==null) return null;
        Node current=head,prev=null;
        if(head.data==key) {
            prev=head;
            while(prev.next!=head) prev=prev.next;
            if(head.next==head) return null;
            prev.next=head.next;
            head=prev.next;
        }
        else {
            do {
                prev=current;
                current=current.next;
            } while(current!=head && current.data!=key);
            if(current.data==key) prev.next=current.next;
        }
        return head;
    }
}