import java.util.HashMap;
//import java.util.Map;

public class longgestSonString {

	public int longest(int []nums)
	{
		HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
		//第一个参数为数组的元素值 第二个参数为1表示其使用过
		int longest =0;
		for(int i = 0; i<nums.length;i++)
		{
			map.put(nums[i], 0);//假设都没用过
		}
			 
		for(int i = 0; i<nums.length;i++) // {1,3,4, 5,6,80,81,82,83 ,84 };
		{			
			if(map.containsKey(nums[i])&& map.get(nums[i])==1)//这个元素 已经参加了某个最长子串  不能再进入其它子串的统计
				 continue;
			int length =1;
			map.put(nums[i], 1);
			int j;
			for(j = nums[i]+1; map.containsKey(j); j++)
			{ 
				map.replace(j, 1);//更改
				++length;		 
			}
			for(j = nums[i]-1; map.containsKey(j); j--)
			{ 
				map.replace(j, 1);
				++length;			 
			}
			longest = longest>length?longest:length;		
		}		
			
		return longest;
	}			
	
	public static void main(String[] args) {
		 int a[] = {1,3,4, 5,6,80,81,82,83 ,84 };
		 longgestSonString l = new longgestSonString();
		 System.out.println(l.longest(a));		 

	}

}
