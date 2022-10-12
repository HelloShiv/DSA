public class arrayReoccur {
    public static void main(String[] args) {
        int[] arr = {12,14,16,17,19,34,35,35,35,35,56,67};
        int target = 35;
        int[] ans ={-1,-1};
        ans[0] = binarySearch(arr,target,true);
        ans[1] = binarySearch(arr,target,false);
        System.out.println("{ "+ans[0] + "," + ans[1]+" }");
    }

    public static int binarySearch(int[] arr, int target,boolean isStart){
        int ans = -1;
        int start =0;
        int end = arr.length - 1 ;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(arr[mid]<target){
                start = mid + 1;
            }
            else if(arr[mid]>target){
                end = mid -1;
            }else{
                ans = mid;
            if(isStart) end = mid - 1;
            else start = mid + 1;
            
        }
    }
        return ans;
    
    }
}
