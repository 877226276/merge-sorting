#include<iostream>
using namespace std;

//������Ƭ�ν��������������  ����������  ��ʼλ���±�  �м�ֵ�±�  ����λ���±꣩
void Merger(int arr[], int low, int mid, int high)
{
	//iΪ��һ��Ƭ�εĿ�ͷ  jΪ�ڶ���Ƭ�εĿ�ͷ  k��¼�Ž��¿��ٵĶ����ռ�������±�
	int i = low, j = mid + 1, k = 0;
	//���������¿ռ�  ���ڴ洢Ƭ������������
	int* temp = new int[high-low+1]();
	//�ж϶����Ƿ񿪱ٳɹ�
	if (!temp)
	{
		cout << "�����ռ俪�ٳ���" << endl;
	}
	//������Ƭ�ε�����һһ���бȽϣ�������С��ֵ�Ž������¿ռ�  ֱ������һ��Ƭ�ε�����ȫ���������
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
	//��ʣ�µ���һ��Ƭ�ε��������η������
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
	//��������ɵĶ����������η���������
	for (int x = low, y = 0; x <= high && y < k; x++, y++)
	{
		arr[x] = temp[y];
	}
	/*for (int z = low; z <= high; z++)
	{
		cout << arr[z] << " ";
	}
	cout << endl;*/
	//�ͷŶ����ڴ�
	delete[]temp;
}
//�鲢���� ����������  ����ʼλ���±�  �������λ���±꣩
//���õݹ�ʵ�ַ���
void Mergersort(int arr[], int low, int high)
{
	//�жϿ�ʼ�±��Ƿ�С�ڽ����±�
	if (low < high)
	{
		//���õݹ齫�����Ϊ����Ƭ��
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
	int num1 = 0;//����ʼλ���±�
	int num2 = 7;//�������λ���±�
	Mergersort(arr, num1, num2);
	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}