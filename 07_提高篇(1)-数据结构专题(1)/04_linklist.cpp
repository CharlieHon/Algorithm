#include<cstdio>
#include<cstdlib>

struct node{
    int data;
    node *next;
};

//构建列表
node* create(int Array[], const int n){
    node *p, *pre, *head;
    head = new node;
    head->next = NULL;
    pre = head;
    for(int i=0; i<n; ++i){
        p = new node;
        p->data = Array[i];
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    return head;
}

//查找元素x
int find(node *head, const int x){
    int count = 0;
    node *p = head->next;
    while(p != NULL){
        if(p->data == x)
            ++count;
        p = p->next;
    }
    return count;
}

//在pos位置，插入元素x
void insert(node *head, const int pos, const int x){
    node *pre = head;
    node *p = new node;
    for(int i=0; i<pos-1; ++i){
        pre = pre->next;
    }
    p->next = pre->next;
    p->data = x;
    pre->next = p;
}

//删除元素x
void delete_element(node *head, const int x){
    node *pre = head;
    node *p = head->next;
    while(p != NULL){
        if(p->data == x){
            pre->next = p->next;
            delete(p);
            p = pre->next;
        }else{
            pre = p;
            p = pre->next;
        }
    }
}

//输出打印链表
void print_list(node *head){
    node *p = head->next;
    if(!p)
        printf("Empty.\n");
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


int main()
{
    int Array[] = {5, 3, 6, 8, 7, 6, 7};
    int length = sizeof(Array) / sizeof(int);
    node *L = create(Array, length);     //头节点
    // L = L->next;
    // while(L != NULL){
    //     printf("%d ", L->data);
    //     L = L->next;
    // }

    //输出打印链表
    print_list(L);

    //在位置3处，插入元素10
    insert(L, 3, 10);
    print_list(L);

    //删除元素6
    delete_element(L, 6);
    print_list(L);

    //查找元素7的个数
    int x;
    printf("Find an element in L: ");
    scanf("%d", &x);
    int count = find(L, x);
    printf("The count of %d is %d\n", x, count);

    return 0;
}
