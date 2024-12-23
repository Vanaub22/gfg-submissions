//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t > 0) {
            int rows = sc.nextInt();
            int columns = sc.nextInt();

            int matrix[][] = new int[rows][columns];

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    matrix[i][j] = sc.nextInt();
                }
            }
            int target = sc.nextInt();

            Solution x = new Solution();

            if (x.searchRowMatrix(matrix, target))
                System.out.println("true");
            else
                System.out.println("false");
            t--;

            System.out.println("~");
        }
    }
}
// } Driver Code Ends




class Solution {
    // Function to search a given number in row-column sorted matrix.
    public boolean searchRowMatrix(int[][] matrix, int x) {
        int m=matrix.length,n=matrix[0].length;
        for(int[] row:matrix) if(row[0]<=x && row[n-1]>=x && binarySearch(row,x)) return true;
        return false;
    }
    public boolean binarySearch(int[] arr, int target) {
        int left=0,right=arr.length-1;
        while(left<=right) {
            int mid=left+(right-left)/2;
            if(arr[mid]==target) return true;
            else if(arr[mid]<target) left=mid+1;
            else right=mid-1;
        }
        return false;
    }
}
