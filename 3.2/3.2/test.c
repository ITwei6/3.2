struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* fast, * slow;//设置两个指针
    fast = slow = head;//让快慢指针同时从开头走
    while (fast != NULL && fast->next != NULL)//当fast不为NULL和fast->next不为空时，才可以正常走，一旦有一个为NULL，则说明两种情况中有一个完成。
    {
        slow = slow->next;//慢指针每次走一步
        fast = fast->next->next;//快指针每次走两步
    }
    return slow;//最后不管结点是偶数个还是奇数个，返回值都是慢指针指向的位置

}
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  *
  * @param pListHead ListNode类
  * @param k int整型
  * @return ListNode类
  */
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    struct ListNode* fast, * slow;//定义两个指针
    fast = slow = pListHead;//一开始快慢指针都指向开头
    if (fast == NULL)//如果链表为空链表则无法返回，返回NULL
        return NULL;
    int num = k - 1;
    if (k == 0)//如果是倒数0个那么也返回NULL
    {
        return NULL;
    }
    while (num--)//先让快指针走k-1步
    {
        if (fast->next == NULL)//我们要确保k的大小不能大于链表的长度对吧，当k的长度大于链表时，就会让链表访问越界，所以先给fast往后走时，要注意不能越界了，如果fast->next为NULL,则表明k是大于链表长度的，之间返回NULL
        {
            return NULL;
        }
        fast = fast->next;
    }
    while (fast->next)//判断结束的条件是当fast->next为NULL时，结束，也就是fast走到最后一个结点时停止，这时快慢指针之间的距离为k-1，而最好一个结点与慢指针所指向的结点的距离就是k-1
    {
        slow = slow->next;//慢指针和快指针一起走
        fast = fast->next;
    }
    return slow;//最后返回slow位置即可
}
```
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  *
  * @param pListHead ListNode类
  * @param k int整型
  * @return ListNode类
  */
    struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    struct ListNode* fast, * slow;//定义两个指针
    fast = slow = pListHead;
    if (fast == NULL)//当链表为空时，返回NULL
        return NULL;
    while (k--)//快指针先走k步
    {
        //要考虑k如果大于链表本身长度时就非法
        if (fast == NULL)
        {
            return NULL;
        }
        fast = fast->next;//
    }
    while (fast)//这个和快指针先走k-1的结束条件不一样喔，这个结束条件应该是快指针走到最后结点的后面，所以是fast为NULL循环结束
    {
        slow = slow->next;//快慢指针一起走
        fast = fast->next;
    }
    return slow;//返回慢指针所在的位置
}
```/**
* Definition for singly - linked list.
* struct ListNode {
    *int val;
    *struct ListNode* next;
    *
};
*/


struct ListNode* removeElements(struct ListNode* head, int val) {

    struct ListNode* cur = head;//cur用来遍历链表，首先指向最前面的
    struct ListNode* prev = NULL;//一开始prev为空
    while (cur)//利用cur进行遍历
    {
        if (cur->val != val)//如果不等于
        {
            prev = cur;//让prev记录这个位置
            cur = cur->next;//cur往后走
        }
        else//如果等于
        {
            if (prev == NULL)//要考虑是否是第一个要删除的，当prev==NULL时，就是删除第一个结点
            {
                head = cur->next;//将头结点与第二个结点链接
                free(cur);//是否cur
                cur = head;//cur往后走，也就是走到第二个结点位置
            }
            else
            {
                prev->next = cur->next;//将前面的与后面的链接
                free(cur);//删除中间的
                cur = prev->next;//cur往后走
            }
        }
    }
    return head;//返回头结点
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val) {

    struct ListNode* cur = head;
    struct ListNode* tail = NULL, * newnode = NULL;//创建一个新结点
    while (cur)//遍历链表
    {
        if (cur->val != val)//如果不相同，就把不相同的结点插入到新的链表中
        {
            //尾插
            if (newnode == NULL)//最初新链表肯定为空，可以直接将cur指向的不相同的结点放入到新链表中
            {
                newnode = tail = cur;
            }
            else
            {
                tail->next = cur;//cur所对应的结点插入到tail后面
                tail = tail->next;//tial要往后走，记录下一个插入结点的位置
            }
            cur = cur->next;//cur也要往后走
        }
        else
        {
            struct ListNode* next = cur->next;//如果元素相同，那先把这个结点的下一个结点地址记录下来
            free(cur);//释放这个要删除的结点
            cur = next;//cur往后走
        }
    }
    if (tail != NULL)//当tail不为空时，我们需要将tail的next置为NULL
        tail->next = NULL;
    return newnode;
}
```
