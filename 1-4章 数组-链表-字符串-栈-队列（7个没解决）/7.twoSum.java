import java.util.HashMap;

public class twoSum {

	public int[] twosum(int []arr, int target)
	{
	HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
	int a[]  = new int[2];
	for(int i=0;i<arr.length; i++)
	{
		map.put(arr[i], i);//key为元素数值   value为下标
	}
	for(int j =0; j<arr.length; j++)
	{
		int gap = target-arr[j];
		if(map.containsKey(gap) && map.get(gap) > j)//index1 must be less than index2.
		{
			a[0] = j+1;
			a[1] = map.get(gap)+1;//返回的是下标+1
		}				
	}
	
	return a;
	}
	
	
	
	
	
	
	public static void main(String[] args) {
		twoSum t = new twoSum();
		int arr[] = {1,2,4,5};
		System.out.println(t.twosum(arr, 5)[0]+"  "+t.twosum(arr, 5)[1]);

	}

}
