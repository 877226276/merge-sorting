#include<iostream>
using namespace std;

//将若干片段进行有序排列组合  参数（数组  开始位置下标  中间值下标  结束位置下标）
void Merger(int arr[], int low, int mid, int high)
{
	//i为第一个片段的开头  j为第二个片段的开头  k记录放进新开辟的堆区空间的数据下标
	int i = low, j = mid + 1, k = 0;
	//堆区开辟新空间  用于存储片段排序后的数据
	int* temp = new int[high-low+1]();
	//判断堆区是否开辟成功
	if (!temp)
	{
		cout << "堆区空间开辟出错" << endl;
	}
	//将两个片段的数据一一进行比较，并将较小的值放进堆区新空间  直至其中一个片段的数据全部放入堆区
	while (i <= mid && j <= high)
	{

		if (arr[i] < arr[j])
		{
			temp[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = arr[j];
			k++;
			j++;
		}
	}
	//将剩下的另一个片段的数据依次放入堆区
	while (i <= mid)
	{
		temp[k] = arr[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		temp[k] = arr[j];
		k++;
		j++;
	}
	//将排序完成的堆区数据依次放入数组中
	for (int x = low, y = 0; x <= high && y < k; x++, y++)
	{
		arr[x] = temp[y];
	}
	/*for (int z = low; z <= high; z++)
	{
		cout << arr[z] << " ";
	}
	cout << endl;*/
	//释放堆区内存
	delete[]temp;
}
//归并排序 参数（数组  排序开始位置下标  排序结束位置下标）
//运用递归实现分治
void Mergersort(int arr[], int low, int high)
{
	//判断开始下标是否小于结束下标
	if (low < high)
	{
		//运用递归将数组分为若干片段
		int mid = (low + high) / 2;
		Mergersort(arr, low, mid);
		Mergersort(arr, mid + 1, high);
		Merger(arr, low, mid, high);
		/*for (int i = low; i <= mid; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;*/
	}
}
int main()
{
	int arr[8] = { 6,5,3,1,0,7,4,2};
	int num1 = 0;//排序开始位置下标
	int num2 = 7;//排序结束位置下标
	Mergersort(arr, num1, num2);
	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}