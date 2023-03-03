struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* fast, * slow;//��������ָ��
    fast = slow = head;//�ÿ���ָ��ͬʱ�ӿ�ͷ��
    while (fast != NULL && fast->next != NULL)//��fast��ΪNULL��fast->next��Ϊ��ʱ���ſ��������ߣ�һ����һ��ΪNULL����˵�������������һ����ɡ�
    {
        slow = slow->next;//��ָ��ÿ����һ��
        fast = fast->next->next;//��ָ��ÿ��������
    }
    return slow;//��󲻹ܽ����ż��������������������ֵ������ָ��ָ���λ��

}
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  *
  * @param pListHead ListNode��
  * @param k int����
  * @return ListNode��
  */
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    struct ListNode* fast, * slow;//��������ָ��
    fast = slow = pListHead;//һ��ʼ����ָ�붼ָ��ͷ
    if (fast == NULL)//�������Ϊ���������޷����أ�����NULL
        return NULL;
    int num = k - 1;
    if (k == 0)//����ǵ���0����ôҲ����NULL
    {
        return NULL;
    }
    while (num--)//���ÿ�ָ����k-1��
    {
        if (fast->next == NULL)//����Ҫȷ��k�Ĵ�С���ܴ�������ĳ��ȶ԰ɣ���k�ĳ��ȴ�������ʱ���ͻ����������Խ�磬�����ȸ�fast������ʱ��Ҫע�ⲻ��Խ���ˣ����fast->nextΪNULL,�����k�Ǵ��������ȵģ�֮�䷵��NULL
        {
            return NULL;
        }
        fast = fast->next;
    }
    while (fast->next)//�жϽ����������ǵ�fast->nextΪNULLʱ��������Ҳ����fast�ߵ����һ�����ʱֹͣ����ʱ����ָ��֮��ľ���Ϊk-1�������һ���������ָ����ָ��Ľ��ľ������k-1
    {
        slow = slow->next;//��ָ��Ϳ�ָ��һ����
        fast = fast->next;
    }
    return slow;//��󷵻�slowλ�ü���
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
  * @param pListHead ListNode��
  * @param k int����
  * @return ListNode��
  */
    struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    struct ListNode* fast, * slow;//��������ָ��
    fast = slow = pListHead;
    if (fast == NULL)//������Ϊ��ʱ������NULL
        return NULL;
    while (k--)//��ָ������k��
    {
        //Ҫ����k���������������ʱ�ͷǷ�
        if (fast == NULL)
        {
            return NULL;
        }
        fast = fast->next;//
    }
    while (fast)//����Ϳ�ָ������k-1�Ľ���������һ��ร������������Ӧ���ǿ�ָ���ߵ������ĺ��棬������fastΪNULLѭ������
    {
        slow = slow->next;//����ָ��һ����
        fast = fast->next;
    }
    return slow;//������ָ�����ڵ�λ��
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

    struct ListNode* cur = head;//cur����������������ָ����ǰ���
    struct ListNode* prev = NULL;//һ��ʼprevΪ��
    while (cur)//����cur���б���
    {
        if (cur->val != val)//���������
        {
            prev = cur;//��prev��¼���λ��
            cur = cur->next;//cur������
        }
        else//�������
        {
            if (prev == NULL)//Ҫ�����Ƿ��ǵ�һ��Ҫɾ���ģ���prev==NULLʱ������ɾ����һ�����
            {
                head = cur->next;//��ͷ�����ڶ����������
                free(cur);//�Ƿ�cur
                cur = head;//cur�����ߣ�Ҳ�����ߵ��ڶ������λ��
            }
            else
            {
                prev->next = cur->next;//��ǰ�������������
                free(cur);//ɾ���м��
                cur = prev->next;//cur������
            }
        }
    }
    return head;//����ͷ���
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
    struct ListNode* tail = NULL, * newnode = NULL;//����һ���½��
    while (cur)//��������
    {
        if (cur->val != val)//�������ͬ���ͰѲ���ͬ�Ľ����뵽�µ�������
        {
            //β��
            if (newnode == NULL)//���������϶�Ϊ�գ�����ֱ�ӽ�curָ��Ĳ���ͬ�Ľ����뵽��������
            {
                newnode = tail = cur;
            }
            else
            {
                tail->next = cur;//cur����Ӧ�Ľ����뵽tail����
                tail = tail->next;//tialҪ�����ߣ���¼��һ���������λ��
            }
            cur = cur->next;//curҲҪ������
        }
        else
        {
            struct ListNode* next = cur->next;//���Ԫ����ͬ�����Ȱ����������һ������ַ��¼����
            free(cur);//�ͷ����Ҫɾ���Ľ��
            cur = next;//cur������
        }
    }
    if (tail != NULL)//��tail��Ϊ��ʱ��������Ҫ��tail��next��ΪNULL
        tail->next = NULL;
    return newnode;
}
```
