#include<iostream>
template<typename T>

void selectionsort(int n)
{
	int i,j;
	T arr[n];
	T temp;
	std::cout<<"Enter array elements : "<<std::endl;
	for(i=0;i<n;i++)
	{
		std::cin>>arr[i];
	}
	std::cout<<"Unsorted Array elements : "<<std::endl;
	std::cout<<"[ ";
	for(i=0;i<n;i++)
	{
		std::cout<<arr[i]<<"  ";
	}
	std::cout<<"] "<<std::endl;
	
	for(i=0;i<n;i++)
	{

		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
			
		}
	}
	
	std::cout<<"Sorted Array elements : "<<std::endl;
	std::cout<<"[ ";
	for(i=0;i<n;i++)
	{
		std::cout<<arr[i]<<"  ";
	}
	std::cout<<"] "<<std::endl;

}

int main()
{
	int n;
	std::cout<<"Enter number of array elements : "<<std::endl;
	std::cin>>n;
	selectionsort<int>(n);
	selectionsort<float>(n);
	return 0;
}
