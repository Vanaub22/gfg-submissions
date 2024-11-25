//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            String[] inputLine = br.readLine().split(" ");
            int n = inputLine.length;
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }
            System.out.println(new Solution().maxProduct(arr));
        }
    }
}

// } Driver Code Ends


class Solution {
    // Function to find maximum product subarray
    int maxProduct(int[] arr) {
        int currMax=arr[0],currMin=arr[0],n=arr.length,ans=arr[0];
        for(int i=1;i<n;i++) {
            if(arr[i]<0) {
                int tmp=currMin;
                currMin=currMax;
                currMax=tmp;
            }
            currMin=Math.min(arr[i],currMin*arr[i]);
            currMax=Math.max(arr[i],currMax*arr[i]);
            ans=Math.max(ans,currMax);
        }
        return ans;
    }
}