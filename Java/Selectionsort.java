package lecture04;

public class Selectionsort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int min,minv,i,j=0;
		int[]arr= {10,34,76,25,67,54};
		for(i=1;i<arr.length-1;i++)
		{
			min=i-1;
			minv=arr[min];
			for(j=i;j<arr.length;j++)
			{
				if(arr[j]<minv)
				{
					min=j;
					minv=arr[j];
				}
			}
			int temp=minv;
			arr[min]=arr[i-1];
			arr[i-1]=temp;
		}
		for(i=0;i<arr.length;i++)
		{
			System.out.println(arr[i]);
		}
		
	}
}
