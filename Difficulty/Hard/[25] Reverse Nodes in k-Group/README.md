# 问题描述
给定一个链表，每次反转链表k的节点并返回其修改后的链表。

k是一个正整数，小于或等于链表的长度。如果节点的数量不是k的倍数，那么最后遗漏的节点应该保持原样。

# 例子
Given this linked list: `1->2->3->4->5`

For k = 2, you should return: `2->1->4->3->5`

For k = 3, you should return: `3->2->1->4->5`

Note:
- 只允许常数的额外内存
- 您不能更改列表节点中的值，只能更改节点本身

# 方法
这题关键要对指针所指的区域有深的理解。直接拿代码来说
```c++
ListNode *reverseKGroup(ListNode *head, int k) {
    //第一步判断head的长度是否小于2，小于2则返回head
    if (! head || ! head->next) return head;
    //第二步初始化链表的长度为0，后面会把链表的真实长度赋值到这里
    int num = 0;
    //新建一个res，用来存储结果
    ListNode* res = new ListNode(0);
    //将head赋给res的下一个指针
    res->next = head;
    //建立pre，cur，nex指针，pre和cur默认指向res
    //注意，res,pre,cur指向同一块内存
    ListNode *pre = res, *cur = res, *nex;
    //对链表的长度进行计算
    while(cur = cur->next) num += 1;
    //循环对链表进行反转，判断条件是剩余长度大于反转长度
    while(num >= k){
        // 以下两行构建，pre在最前面，cur是pre下一个指针，nex是cur下一个指针
        cur = pre->next;
        nex = cur->next;
        //循环至一个k反转完成
        for (int i = 1; i < k; ++i){
            //将nex的下一个指针赋给cur的下一个指针
            //这一步很重要，这一步不仅改变了cur的链表
            //还改变了pre的链表，它们两个是同一个内存空间
            cur->next = nex->next;
            //这一步就将一次反转结果存储在了nex中了
            nex->next = pre->next;
            //再将结果存储到pre中
            pre->next = nex;
            //对nex进行还原
            nex = cur->next;
        }
        //k反转结束，对pre恢复位置，与初始位置一样。
        pre = cur;
        //得到未反转的链表的长度
        num -= k;
    }
    //返回结果
    return res->next;
}
```