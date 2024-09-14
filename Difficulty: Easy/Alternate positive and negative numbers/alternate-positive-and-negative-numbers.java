//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String input = br.readLine();
            String[] inputArray = input.split("\\s+");
            ArrayList<Integer> arr = new ArrayList<>();

            for (String s : inputArray) {
                arr.add(Integer.parseInt(s));
            }

            new Solution().rearrange(arr);
            for (int num : arr) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    void rearrange(ArrayList<Integer> arr) {
        ArrayList<Integer> pos=new ArrayList<>(),neg=new ArrayList<>();
        for(int i:arr) if(i>=0) pos.add(i);
        else neg.add(i);
        int i=0,k1=0,k2=0,n=arr.size(),p=pos.size(),q=neg.size();
        while(k1<p && k2<q) {
            if(i%2==0) arr.set(i++,pos.get(k1++));
            else arr.set(i++,neg.get(k2++));
        }
        while(k1<p) arr.set(i++,pos.get(k1++));
        while(k2<q) arr.set(i++,neg.get(k2++));
    }
}