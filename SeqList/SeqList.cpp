
// 能手写顺序表结构体定义（静态& 动态）
// 初始化
// 判空 / 判满
// 按位查找（取第i个元素）
// 按值查找（定位元素）
// 指定位置插入（含边界判断）
// 指定位置删除（含边界判断）
// 获取表长
// 遍历打印
// 销毁（动态释放）
// 能说出每个操作的时间复杂度
// 能做1 - 2道综合应用题（如删除重复元素）


#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int* data;
	int size;
	int capacity;
}Dynamicarray; //size从0开始，capacity是数组的容量

void Array_Init(Dynamicarray* Array, int init_Array)
{
	Array->data = (int*)malloc(sizeof(int) * init_Array);
	Array->size = 0;
	Array->capacity = init_Array;
}

void Free_Array(Dynamicarray* Array)
{
	free(Array->data);
	Array->data = 0;
	Array->size = 0;
	Array->capacity = 0;
}

void Array_Append(Dynamicarray* Array, int value)
{
	if (Array->size >= Array->capacity)
	{
		printf("Array is full, cannot append value %d\n", value);
	}

	Array->data[Array->size] = value;
	Array->size = Array->size + 1;
}

//index从1开始，是实际的插入位置，index=1表示在第一个元素前插入，index=size+1表示在最后一个元素后插入
void Array_Insert(Dynamicarray* Array, int index, int value)
{
	if (index<1 || index > Array->size + 1)
	{
		printf("Index out of bounds, cannot insert value %d at index %d\n", value, index);
		return;
	}

	for (int i = Array->size;i >= index;i--)
	{
		Array->data[i] = Array->data[i - 1];
	}
	Array->data[index - 1] = value;
	Array->size = Array->size + 1;
}

void Array_Delete(Dynamicarray* Array, int index)
{
	if (index<1 || index>Array->size)
	{
		printf("Index out of bounds, cannot delete value at index %d\n", index);
		return;
	}
	for (int i = index;i < Array->size;i++)
	{
		Array->data[i - 1] = Array->data[i];
	}
	Array->size = Array->size - 1;
}

//按位查找（取第i个元素）
void Array_Getvalue(Dynamicarray* Array, int index)
{
	if (index < 1 || index > Array->size)
	{
		printf("Index out of bounds!\n");
		return;
	}
	printf("第 %d 个元素的值是: %d\n", index, Array->data[index - 1]);
}

//按值查找（定位元素）
int Array_Getindex(Dynamicarray* Array, int value)
{
	for (int i = 0;i < Array->size;i++)
	{
		if (Array->data[i] == value)
			return i + 1;
	}
	printf("No value!\n");
	return -1;
}

void Array_Print(Dynamicarray* Array)
{
	if (Array->size == 0)
	{
		printf("顺序表为空\n");
		return;
	}
	for (int i = 0; i < Array->size; i++)
	{
		printf("%d ", Array->data[i]);
	}
	printf("\n");  // 最后换行
}

int main()
{

	return 0;
}


