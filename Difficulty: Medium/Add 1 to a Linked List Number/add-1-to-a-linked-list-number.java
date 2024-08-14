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

class GfG {
    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data);
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String str[] = read.readLine().trim().split(" ");
            int n = str.length;
            Node head = new Node(Integer.parseInt(str[0]));
            Node tail = head;
            for (int i = 1; i < n; i++) {
                tail.next = new Node(Integer.parseInt(str[i]));
                tail = tail.next;
            }
            Solution obj = new Solution();
            head = obj.addOne(head);
            printList(head);
        }
    }
}
// } Driver Code Ends


/*
class Node{
    int data;
    Node next;

    Node(int x){
        data = x;
        next = null;
    }
}
*/

class Solution {
    public Node addOne(Node head) {
        String x="",res="";
        Node temp=head,nhead;
        while(temp!=null) {
            x+=Integer.toString(temp.data);
            temp=temp.next;
        }
        int n=x.length(),carry=1;
        for(int i=n-1;i>=0;i--) {
            int dig=x.charAt(i)-'0',sum=dig+carry;
            if(sum>=10) carry=Integer.toString(sum).charAt(0)-'0';
            else carry=0;
            res=Integer.toString(sum%10)+res;
        }
        if(carry>0) res=Integer.toString(carry)+res;
        n=res.length();
        nhead=new Node(res.charAt(0)-'0');
        temp=nhead;
        for(int i=1;i<n;i++) {
            temp.next=new Node(res.charAt(i)-'0');
            temp=temp.next;
        }
        return nhead;
    }
}
