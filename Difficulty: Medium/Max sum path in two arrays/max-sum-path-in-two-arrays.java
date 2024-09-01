//{ Driver Code Starts
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // consume the remaining newline

        for (int k = 0; k < t; k++) {
            List<Integer> arr1 = new ArrayList<>();
            String input = sc.nextLine();
            Scanner lineScanner = new Scanner(input);
            while (lineScanner.hasNextInt()) {
                arr1.add(lineScanner.nextInt());
            }
            lineScanner.close();

            List<Integer> arr2 = new ArrayList<>();
            input = sc.nextLine();
            lineScanner = new Scanner(input);
            while (lineScanner.hasNextInt()) {
                arr2.add(lineScanner.nextInt());
            }
            lineScanner.close();

            Solution ob = new Solution();
            int ans = ob.maxPathSum(arr1, arr2);
            System.out.println(ans);
        }

        sc.close();
    }
}

// } Driver Code Ends



class Solution {
    public int maxPathSum(List<Integer> arr1, List<Integer> arr2) {
        int i=0,j=0,m=arr1.size(),n=arr2.size(),rsum1=0,rsum2=0,ans=0;
        while(i<m && j<n) {
            if(arr1.get(i)>arr2.get(j)) rsum2+=arr2.get(j++);
            else if(arr1.get(i)<arr2.get(j)) rsum1+=arr1.get(i++);
            else {
                ans+=Math.max(rsum1,rsum2)+arr1.get(i++);
                j++;
                rsum1=0;
                rsum2=0;
            }
        }
        while(i<m) rsum1+=arr1.get(i++);
        while(j<n) rsum2+=arr2.get(j++);
        return ans+Math.max(rsum1,rsum2);
    }
}