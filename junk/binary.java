
public class BinarySearch{
    public static void main(String[] args) {
        int[] arr = {12,13,14,15,16,17,18,19};
        new BinarySearch();
        System.out.println( BinarySearch.binarySearch(arr,21));

    }

    public static int binarySearch(int[] arr , int target){
        int start =0;
        int end = arr.length - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] == target) return arr[mid];
            else if(arr[mid] >= target) end = mid - 1;
            else if(arr[mid] <= target) start = mid + 1;
        } 

        return -1;
    }
}
