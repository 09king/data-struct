#include <stdio.h>
#include <stdlib.h>

//1. 结构体定义
typedef struct Listnode
{
    int data;
    struct Listnode* next;
} Listnode;

//2. 初始化（带头结点）
Listnode* List_Init()
{
    Listnode* newlist = (Listnode*)malloc(sizeof(Listnode));
    if (newlist == NULL)
    {
        printf("Memory allocation failed (Init)\n");
        return NULL;
    }
    newlist->data = 0;
    newlist->next = NULL;
    return newlist;
}

//3. 打印（方便调试）
void List_Print(Listnode* list)
{
    if (list == NULL) return;
    Listnode* p = list->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//4. 头插法建表
void List_Insert_Head(Listnode* list, int value)
{
    if (list == NULL) return;
    Listnode* newlist = (Listnode*)malloc(sizeof(Listnode));
    if (newlist == NULL)
    {
        printf("Memory allocation failed (Head Insert)\n");
        return;
    }
    newlist->data = value;
    newlist->next = list->next;
    list->next = newlist;
}

//5. 尾插法建表
void List_Insert_Tail(Listnode* list, int value)
{
    if (list == NULL) return;
    Listnode* newlist = (Listnode*)malloc(sizeof(Listnode));
    if (newlist == NULL)
    {
        printf("Memory allocation failed (Tail Insert)\n");
        return;
    }
    newlist->data = value;
    newlist->next = NULL;

    Listnode* p = list;
    while (p->next != NULL)
        p = p->next;
    p->next = newlist;
}

//6. 按位查找
int Find_By_Index(Listnode* list, int index)
{
    if (list == NULL || index < 1)
    {
        printf("index is error\n");
        return -1;
    }

    Listnode* p = list->next;
    for (int i = 1; i < index; i++)
    {
        if (p == NULL)
        {
            printf("index is error\n");
            return -1;
        }
        p = p->next;
    }

    if (p == NULL)
    {
        printf("index is error\n");
        return -1;
    }

    printf("Value at position %d is %d\n", index, p->data);
    return p->data;
}

//7. 按值查找
int Find_By_Value(Listnode* list, int value)
{
    if (list == NULL) return -1;
    int count = 1;
    Listnode* p = list->next;

    while (p != NULL && p->data != value)
    {
        count++;
        p = p->next;
    }

    if (p == NULL)
    {
        printf("Value %d not found\n", value);
        return -1;
    }

    printf("Value %d is at position %d\n", value, count);
    return count;
}

//8. 指定位置插入（后插法）
void List_Insert_By_Index(Listnode* list, int index, int value)
{
    if (list == NULL || index < 1)
    {
        printf("index is error\n");
        return;
    }

    Listnode* newlist = (Listnode*)malloc(sizeof(Listnode));
    if (newlist == NULL)
    {
        printf("Memory allocation failed (Index Insert)\n");
        return;
    }

    Listnode* p = list;
    newlist->data = value;

    for (int i = 1; i < index; i++)
    {
        if (p == NULL)
        {
            printf("index is error\n");
            free(newlist);
            return;
        }
        p = p->next;
    }

    newlist->next = p->next;
    p->next = newlist;
}

//9. 指定位置删除
void List_Delete_By_Index(Listnode* list, int index)
{
    if (list == NULL || index < 1)
    {
        printf("index is error\n");
        return;
    }

    Listnode* p = list;
    for (int i = 1; i < index; i++)
    {
        if (p->next == NULL)
        {
            printf("index is error\n");
            return;
        }
        p = p->next;
    }

    if (p->next == NULL)
    {
        printf("index is error\n");
        return;
    }

    Listnode* temp = p->next;
    int deleted_value = temp->data;
    p->next = temp->next;
    free(temp);
    printf("Deleted value %d at position %d successfully\n", deleted_value, index);
}

//10. 获取表长
int List_Length(Listnode* list)
{
    if (list == NULL) return 0;
    int len = 0;
    Listnode* p = list->next;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

//11. 销毁
void List_Destroy(Listnode** list)
{
    if (list == NULL || *list == NULL) return;
    Listnode* p = *list;
    while (p != NULL)
    {
        Listnode* temp = p;
        p = p->next;
        free(temp);
    }
    *list = NULL;
}

//12. 综合题练手 —— 链表反转（就地逆置）
void List_Reverse(Listnode* list)
{
    if (list == NULL || list->next == NULL) return;

    Listnode* prev = NULL;
    Listnode* curr = list->next;
    Listnode* next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->next = prev;
    printf("List reversed\n");
}

// 测试主函数
int main()
{
    Listnode* mylist = List_Init();
    if (mylist == NULL) return -1;

    // 尾插测试
    List_Insert_Tail(mylist, 10);
    List_Insert_Tail(mylist, 20);
    List_Insert_Tail(mylist, 30);
    printf("After tail insert: ");
    List_Print(mylist);

    // 头插测试
    List_Insert_Head(mylist, 5);
    printf("After head insert: ");
    List_Print(mylist);

    // 按位插入
    List_Insert_By_Index(mylist, 3, 15);
    printf("After inserting 15 at position 3: ");
    List_Print(mylist);

    // 查找测试
    Find_By_Index(mylist, 4);
    Find_By_Value(mylist, 20);

    // 表长
    printf("Current length: %d\n", List_Length(mylist));

    // 删除测试
    List_Delete_By_Index(mylist, 2);
    printf("After deleting position 2: ");
    List_Print(mylist);

    // 综合题：反转
    List_Reverse(mylist);
    printf("After reverse: ");
    List_Print(mylist);

    // 销毁
    List_Destroy(&mylist);
    printf("After destroy, mylist = %p\n", mylist);

    return 0;
}
