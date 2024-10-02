//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // Consume the newline character

        while (t-- > 0) {
            String s = sc.nextLine();
            String[] parts = s.split(" ");
            List<Integer> nums = new ArrayList<>();
            for (String part : parts) {
                nums.add(Integer.parseInt(part));
            }
            Solution ob = new Solution();
            List<Integer> ans = ob.findMajority(nums);
            for (int num : ans) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
// } Driver Code Ends


class Solution {
    // Function to find the majority elements in the array
    public List<Integer> findMajority(List<Integer> nums) {
        int n=nums.size();
        List<Integer> ans=new ArrayList<>();
        int cnt1=0,cnt2=0,x=-1,y=-1;
        for(int i:nums) {
            if(i==x) cnt1++;
            else if(i==y) cnt2++;
            else if(cnt1==0) {
                x=i;
                cnt1++;
            }
            else if(cnt2==0) {
                y=i;
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i:nums) {
            if(i==x) cnt1++;
            else if(i==y) cnt2++;
        }
        if(cnt1>n/3) ans.add(x);
        if(cnt2>n/3) ans.add(y);
        if(ans.size()==0) ans.add(-1);
        return ans;
    }
}
