#include <cstdio>

#define ElementType int
#define do_question(func_question)   \
    printf("%s:\n", #func_question); \
    func_question()
#define printList(list)                    \
    printf("%s (%d):\n", #list, list.len); \
    listPrint(list)

struct ListNode
{
    ElementType data;
    ListNode *next;
};

struct LinkList
{
    ListNode *head;
    int len;
};

LinkList newLinkList()
{
    LinkList list;
    list.len = 0;
    list.head = new ListNode();
    list.head->next = NULL;
    return list;
}

LinkList *newNoHeadLinkList()
{
    LinkList *list = new LinkList();
    list->len = 0;
    list->head = NULL;
    return list;
}

// insert element to index i (1<=i<=list.len)
bool listInsert(LinkList &list, int i, ElementType e)
{
    if (i < 1)
        return false;
    ListNode *p = list.head;
    int k = 0;
    while (p && k < i - 1)
    {
        p = p->next;
        k++;
    }
    if (!p)
        return false;
    ListNode *newNode = new ListNode();
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    list.len++;
    return true;
}

// remove element at i (1<=i<=list.len)
bool listRemoveAt(LinkList &list, int i)
{
    if (i < 1)
        return false;
    ListNode *p = list.head;
    int k = 0;

    while (p->next && k < i - 1)
    {
        p = p->next;
        k++;
    }
    if (!p->next)
        return false;
    ListNode *s = p->next;
    p->next = s->next;
    delete s;
    list.len--;
    return true;
}

void listAppend(LinkList &list, LinkList list2)
{
    ListNode *p = list.head;
    while (p->next)
    {
        p = p->next;
    }
    p->next = list2.head->next;
    list.len += list2.len;
}

void listDistinct(LinkList &list)
{
    ListNode *p = list.head->next, *tmp;
    int cnt = 0;
    while (p)
    {
        if (p->next == NULL)
        {
            break;
        }
        if (p->data == p->next->data)
        {
            tmp = p->next;
            p->next = tmp->next;
            delete tmp;
            cnt++;
            continue;
        }
        p = p->next;
    }
    list.len -= cnt;
}

void mergeOrderList(LinkList &la, LinkList &lb)
{
    ListNode *p1 = la.head->next;
    ListNode *p2 = lb.head->next;
    ListNode *last = la.head;
    while (p1 && p2)
    {
        if (p1->data < p2->data)
        {
            last->next = p1;
            last = p1;
            p1 = p1->next;
        }
        else
        {
            last->next = p2;
            last = p2;
            p2 = p2->next;
        }
    }
    last->next = (p1 == NULL) ? p2 : p1;
    la.len = la.len + lb.len;
    delete lb.head;
}

void listPrint(LinkList list)
{
    ListNode *p = list.head->next;
    while (p)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void noHeadLinkListRemoveAll(ListNode *&node, ElementType data)
{
    // 此处*&node意为指针变量的引用
    // 也就是说指针变量的地址可以被修改
    // node是上一个节点的next变量
    // 将next的地址修改为next->next既 node=node->next
    // 即可完成删除操作

    // if(node==NULL) return;
    // noHeadLinkListRemoveAll(node->next,data);
    // ListNode *s = node->next;
    // if (s&&s->data==data){
    //     node->next=s->next;
    //     delete s;
    // }
    ListNode *p;
    if (node == NULL)
        return;
    if (node->data == data)
    {
        p = node;
        node = node->next;
        delete p;
        noHeadLinkListRemoveAll(node, data);
    }
    else
    {
        noHeadLinkListRemoveAll(node->next, data);
    }
}

void listRemoveAll(LinkList &list, ElementType data)
{
    ListNode *p = list.head;
    ListNode *tmp;
    int cnt = 0;
    while (p && p->next)
    {
        if (p->next->data == data)
        {
            tmp = p->next;
            p->next = tmp->next;
            delete tmp;
            cnt++;
        }
        p = p->next;
    }
    list.len -= cnt;
}

void listReverse(LinkList &list)
{
    ListNode *p = list.head->next;
    ListNode *tmp;
    list.head->next = NULL;
    while (p)
    {
        tmp = p;
        p = p->next;
        tmp->next = list.head->next;
        list.head->next = tmp;
    }
    // way2:

    // ListNode *tmp,*last=NULL;
    // while(p){
    //     tmp=p->next;
    //     p->next=last;
    //     last=p;
    //     p=tmp;
    // }
    // list.head->next=last;
}

void q1()
{
    ListNode *first = new ListNode();
    first->data = 2;
    ListNode *p = first;
    for (int i = 0; i < 10; i++)
    {
        ListNode *newNode = new ListNode();
        newNode->data = i % 3;
        newNode->next = NULL;
        p->next = newNode;
        p = newNode;
    }
    p = first;
    noHeadLinkListRemoveAll(p, 0);
    p = first;
    while (p)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
void q2()
{
    LinkList list = newLinkList();
    for (int i = 1; i <= 10; i++)
    {
        listInsert(list, i, i % 3);
    }
    printList(list);
    listRemoveAll(list, 1);
    printList(list);
}
// 反转链表
void q5()
{
    LinkList list = newLinkList();
    for (int i = 1; i <= 10; i++)
    {
        listInsert(list, i, i);
    }
    printList(list);
    listReverse(list);
    printList(list);
}
// 寻找第一个公共元素
void q8()
{
    LinkList list3 = newLinkList();
    for (int i = 1; i <= 5; i++)
    {
        listInsert(list3, i, 10 + i);
    }
    printList(list3);

    LinkList list1 = newLinkList();
    for (int i = 1; i <= 2; i++)
    {
        listInsert(list1, i, i);
    }
    listAppend(list1, list3);
    printList(list1);
    LinkList list2 = newLinkList();
    for (int i = 1; i <= 5; i++)
    {
        listInsert(list2, i, i * 2);
    }
    listAppend(list2, list3);
    printList(list2);
    // 寻找第一个相同元素
    ListNode *longList = list1.head->next;
    ListNode *shortList = list2.head->next;
    int distance = list1.len - list2.len;

    if (list2.len > list1.len)
    {
        longList = list2.head->next;
        shortList = list1.head->next;
        distance = -distance;
    }
    while (distance--)
        longList = longList->next;
    while (longList)
    {
        if (longList == shortList)
        {
            break;
        }
        longList = longList->next;
        shortList = shortList->next;
    }

    if (longList != NULL)
    {
        printf("first common element: %p %d\n", longList, longList->data);
        return;
    }
    printf("first common element (none)");
}

// 递增输出并删除
void q9()
{
    LinkList list = newLinkList();
    for (int i = 1; i <= 5; i++)
    {
        listInsert(list, i, i * 2);
    }
    printList(list);
    ListNode *p = list.head, *minpre = list.head;
    while (list.head->next != NULL)
    {
        p = list.head;
        minpre = list.head;
        while (p->next)
        {
            if (p->next->data < minpre->next->data)
            {
                minpre = p;
            }
            p = p->next;
        }
        if (minpre->next != NULL)
        {
            printf("%d ", minpre->next->data);
            ListNode *tmp = minpre->next;
            minpre->next = tmp->next;
            delete tmp;
        }
    }
    printf("\n");
}

// 有序去重
void q12()
{
    LinkList list = newLinkList();
    for (int i = 1; i <= 10; i++)
    {
        listInsert(list, i, i / 3);
    }
    printList(list);
    listDistinct(list);
    printList(list);
}

// 合并有序链表
void q13()
{
    LinkList listA = newLinkList();
    LinkList listB = newLinkList();

    for (int i = 1; i <= 5; i++)
    {
        listInsert(listA, i, i * 2 - 1);
    }
    for (int i = 1; i <= 3; i++)
    {
        listInsert(listB, i, i * 2);
    }

    printList(listA);
    printList(listB);
    mergeOrderList(listA, listB);
    printList(listA);
}

// 求有序链表交集
void q15()
{
    LinkList listA = newLinkList();
    LinkList listB = newLinkList();

    for (int i = 1; i <= 5; i++)
    {
        listInsert(listA, i, i);
    }
    for (int i = 1; i <= 7; i++)
    {
        listInsert(listB, i, i+3);        
    }
    //listInsert(listB, 1,);

    printList(listA);
    printList(listB);

    ListNode *pa=listA.head;
    ListNode *pb=listB.head->next;
    listA.len=0;
    while(pa->next&&pb){
        if(pa->next->data>pb->data){
            pb=pb->next;
        }else if(pa->next->data<pb->data){
            ListNode *tmp=pa->next;
            pa->next=tmp->next;
            delete tmp;
        }else{
            pa=pa->next;
            pb=pb->next;
            listA.len++;
        }
    }
    
    if (pb==NULL) {
        pa->next=NULL;
    }
    // free掉A和B
    printList(listA);

}

int findLastK(ListNode *list,int k){
    ListNode *p1=list->next,*p2=list->next;
    while(p2&&k>0){
        p2=p2->next;
        k--;
    }
    if(k!=0) return 0;
    while(p2){
        p1=p1->next;
        p2=p2->next;
    }
    printf(": %d\n",p1->data);
    return 1;
}

// 求倒数第K个元素
void q21(){
    LinkList list = newLinkList();
    for (int i = 1; i <= 10; i++)
    {
        listInsert(list, i, i);
    }
    
    for(int k = 1; k <= 15; k++)
    {
        printf("find last %d result %d\n",k,findLastK(list.head,k));
    }
    
}
int main(int argc, char const *argv[])
{
    LinkList list = newLinkList();

    for (int i = 1; i <= 10; i++)
    {
        listInsert(list, i, i * 2);
    }
    printList(list);
    listRemoveAt(list, 10);
    printList(list);
    do_question(q1);
    do_question(q2);
    do_question(q5);
    do_question(q8);
    do_question(q9);
    do_question(q12);
    do_question(q13);
    do_question(q15);    
    do_question(q21);    
    return 0;
}
