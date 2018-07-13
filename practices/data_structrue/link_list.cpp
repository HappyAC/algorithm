#include<cstdio>

#define ElementType int

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


LinkList newLinkList(){
    LinkList list;
    list.len=0;
    list.head=new ListNode();
    list.head->next=NULL;
    return list;
}

LinkList* newNoHeadLinkList(){
    LinkList *list = new LinkList();
    list->len=0;
    list->head=NULL;
    return list;
}

// insert element to index i (1<=i<=list.len)
bool listInsert(LinkList &list,int i,ElementType e){  
    if (i<1) return false;
    ListNode *p = list.head;
    int k = 0;   
    while(p&&k<i-1){
        p=p->next;
        k++;
    }
    if (!p) return false;
    ListNode *newNode = new ListNode();
    newNode->data=e;
    newNode->next=p->next;
    p->next=newNode;
    list.len++;
    return true;
}

// remove element at i (1<=i<=list.len)
bool listRemoveAt(LinkList &list,int i){
    if (i<1) return false;
    ListNode *p = list.head;
    int k=0;
    
    while(p->next&&k<i-1){
        p=p->next;
        k++;
    }
    if(!p->next) return false;
    ListNode *s = p->next;
    p->next=s->next;
    delete s;
    list.len--;
    return true;
}

void printList(LinkList list){
    ListNode *p = list.head->next;
    while(p){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL\n");  
}

void noHeadLinkListRemoveAll(ListNode *&node,ElementType data){
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
    if(node==NULL) return;
    if(node->data==data){
        p=node;
        node=node->next;
        delete p;
        noHeadLinkListRemoveAll(node,data);
    }else{
        noHeadLinkListRemoveAll(node->next,data);
    }
}

void q1(){
    ListNode *first=new ListNode();
    first->data=2;
    ListNode *p=first;
    for(int i = 0; i < 10; i++)
    {
        ListNode *newNode=new ListNode();
        newNode->data=i%3;
        newNode->next=NULL;
        p->next=newNode;
        p=newNode;
    }
    p=first;
    noHeadLinkListRemoveAll(p,0);
    p=first;
    printf("q1:\n");
    while(p){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL\n");  
}

 
int main(int argc, char const *argv[])
{
    LinkList list = newLinkList();
    
    for(int i = 1; i <= 10; i++)
    {
        listInsert(list,i,i*2);
    }
    printList(list);
    listRemoveAt(list,10);
    printList(list);
    q1();
    return 0;
}

