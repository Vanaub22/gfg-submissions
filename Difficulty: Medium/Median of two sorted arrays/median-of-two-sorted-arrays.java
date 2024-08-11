//{ Driver Code Starts
// Initial Template for Java

import java.util.*;


// } Driver Code Ends
// User function Template for Java

class Solution {
    public int sumOfMiddleElements(int arr1[], int arr2[]) {
        int n1=arr1.length,n2=arr2.length,n=n1+n2;
        int i=0,j=0;
        ArrayList<Integer> temp=new ArrayList<>();
        while(i<n1 && j<n2) {
            if(arr1[i]<arr2[j]) temp.add(arr1[i++]);
            else temp.add(arr2[j++]);
        }
        while(i<n1) temp.add(arr1[i++]);
        while(j<n2) temp.add(arr2[j++]);
        return temp.get(n/2-1)+temp.get(n/2);
    }
}

//{ Driver Code Starts.
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // Consume newline
        while (t-- > 0) {
            String[] input1 = sc.nextLine().split(" ");
            int[] arr = new int[input1.length];
            for (int i = 0; i < input1.length; i++) {
                arr[i] = Integer.parseInt(input1[i]);
            }

            String[] input2 = sc.nextLine().split(" ");
            int[] brr = new int[input2.length];
            for (int i = 0; i < input2.length; i++) {
                brr[i] = Integer.parseInt(input2[i]);
            }

            Solution ob = new Solution();
            int res = ob.sumOfMiddleElements(arr, brr);
            System.out.println(res);
        }
    }
}

// } Driver Code Ends