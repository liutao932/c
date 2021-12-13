#include"List.h"

static LN* NodeBuy(ListNodeDataType x)//申请节点
{
	LN* newnode = (LN*)malloc(sizeof(LN));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
static void NodePushBack(LN** head, ListNodeDataType x)//尾插
{
	assert(head);
	LN* newnode = NodeBuy(x);
	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		LN* tail = *head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
		tail = newnode;
	}
}
static void NodePushFront(LN** head, ListNodeDataType x)//头插
{
	assert(head);
	LN* newnode = NodeBuy(x);
	newnode->next = *head;
	*head = newnode;
}
static void NodePopBack(LN** head)//尾删
{
	assert(head);
	assert(*head);
	if ((*head)->next == NULL)
	{
		*head = NULL;
	}
	else
	{
		LN* prev = NULL;
		LN* tail = *head;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
	}
}
static void NodePopFront(LN** head)//头删
{
	assert(head);
	assert(*head);
	if ((*head)->next == NULL)
	{
		*head = NULL;
	}
	else
	{
		LN* next = (*head)->next;
		free(*head);
		*head = next;
	}
}
static LN* NodeFind(LN* head, ListNodeDataType x)//查找节点
{
	assert(head);
	LN* cur = head;
	while (cur)
	{
		if (cur->data == x)
		{
			break;
		}
		cur = cur->next;
	}
	return cur;
}
static void NodeInsert(LN* head,LN* Node, ListNodeDataType x)//在Node 节点之前插入
{
	assert(head);
	LN* newnode = NodeBuy(x);
	LN* prev = NULL;
	LN* cur = head;
	while (cur)
	{
		if (cur == Node)
		{
			break;
		}
		prev = cur;
		cur = cur->next;
	}
	newnode->next = Node;
	prev->next = newnode;
}
static void NodeDestroy(LN** head)//销毁
{
	assert(head);
	LN* cur = *head;
	while (cur)
	{
		LN* next = cur->next;
		free(cur);
		cur = next;
	}
}
static void NodePrintf(LN* head)//打印
{
	LN* cur = head;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
static void NodeReverse(LN** head) //逆置
{
	assert(head);
	LN* n1 = NULL;
	LN* n2 = *head;
	while (n2)
	{
		LN* n3 = n2->next;
		n2->next = n1;
		n1 = n2;
		n2 = n3;
	}
	*head = n1;
}
static void NodeClassified(LN** head) //分类小于5在左边等于5的在中间大于5在右边，相对顺序不变
{
	assert(head);
	assert(*head);
	LN* Shead, * Stail;   //小于的头尾
	Shead = Stail = (LN*)malloc(sizeof(LN));
	assert(Shead && Stail);
	Shead->next = Stail->next = NULL;

	LN* Ehead, * Etail;   //等于的头尾
	Ehead = Etail = (LN*)malloc(sizeof(LN));
	assert(Ehead && Etail);
	Ehead->next = Etail->next = NULL;


	LN* Ghead, * Gtail;    //大于的头尾
	Ghead = Gtail = (LN*)malloc(sizeof(LN));
	assert(Ghead && Gtail);
	Ghead->next = Gtail->next = NULL;
	//处理
	LN* cur = *head;
	while (cur)
	{
		if (cur->data < 5)
		{
			Stail->next = cur;
			Stail = cur;
		}
		else if (cur->data == 5)
		{
			Etail->next = cur;
			Etail = cur;
		}
		else
		{
			Gtail->next = cur;
			Gtail = cur;
		}
		cur = cur->next;
	}
	/*各种极端情况的处理*/
	//if (Stail->next != NULL && Etail->next != NULL && Gtail != NULL) //都不为空
	//{
		Stail->next = Ehead->next;
		Etail->next = Ghead->next;
		Gtail->next = NULL;
		*head = Shead->next;
	//}
	//else if (Stail->next == NULL && Etail->next != NULL && Gtail != NULL) //小于5的为空
	//{
	//	Etail->next = Ghead->next;
	//	Gtail->next = NULL;
	//	*head = Ehead->next;
	//}
	//else if (Stail->next != NULL && Etail->next == NULL && Gtail != NULL) //等于5的为空
	//{
	//	Stail->next = Ghead->next;
	//	Gtail->next = NULL;
	//	*head = Shead->next;
	//}
	//else if (Stail->next != NULL && Etail->next != NULL && Gtail == NULL) //大于5的为空
	//{
	//	Stail->next = Ehead->next;
	//	Etail->next = NULL;
	//	*head = Shead->next;
	//}
	//else if (Stail->next == NULL && Etail->next == NULL && Gtail != NULL) //大于5的不为空
	//{
	//	*head = Ghead->next;
	//}
	//else if (Stail->next == NULL && Etail->next != NULL && Gtail == NULL) //等于5的不为空
	//{
	//	*head = Ehead->next;
	//}
	//else if (Stail->next == NULL && Etail->next != NULL && Gtail == NULL)  //小于5的不为空
	//{
	//	*head = Etail->next;
	//}
}
static LN* NodeMid(LN* head) //中间节点
{
	assert(head);
	LN* slow = head;
	LN* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
static bool NodePalindrome(LN* head) //判断是否回文
{
	assert(head);
	if (head == NULL && head->next == NULL)
		return false;
	LN* solw = head;
	LN* fast = head;
	while (fast->next && fast->next->next) //找到中间节点
	{
		solw = solw->next;
		fast = fast->next->next;
	}
	LN* next = solw->next;
	solw->next = NULL; //断开连接
	NodeReverse(&next);
	while (head && next)
	{
		if (head->data != next->data)
			return false;

		head = head->next;
		next = next->next;
	}
	return true;
}
static LN* NodeTwoAdd(LN* l1, LN* l2)//两个链表相加
{
	assert(l1 && l2);
	NodeReverse(&l1);  //先逆置
	NodeReverse(&l2);  //先逆置
	LN* cur1 = l1;
	LN* cur2 = l2;
	LN* newhead = NULL;
	int count = 0; //进位标志
	while (cur1 && cur2)
	{
		int sum = cur1->data + cur2->data + count;
		int tmp = sum % 10;
		NodePushBack(&newhead, tmp);
		count = sum / 10;
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	while (cur1)
	{
		int sum = cur1->data + count;
		int tmp = sum % 10;
		NodePushBack(&newhead, tmp);
		count = sum / 10;
		cur1 = cur1->next;
	}
	while (cur2)
	{
		int sum = cur2->data + count;
		int tmp = sum % 10;
		NodePushBack(&newhead, tmp);
		count = sum / 10;
		cur2 = cur2->next;
	}
	if (count == 1)
	{
		NodePushBack(&newhead, 1);
	}
	NodeReverse(&newhead);
	return newhead;
}
LN* NodeTwoCross(LN* l1, LN* l2)//求相交节点
{
	assert(l1 && l2);
	int len1 = 0, len2 = 0;
	LN* cur1 = l1, *cur2 = l2;
	while (cur1)
	{
		len1++;
		cur1 = cur1->next;
	}
	while (cur2)
	{
		len2++;
		cur2 = cur2->next;
	}
    LN* longlist  =  len1 > len2 ? l1 : l2;
	LN* shortlist =  len1 < len2 ? l1 : l2;
	/*LN* shortlist = l1;
	LN* longlist = l2;
	if (len1 > len2)
	{
		shortlist = cur2;
		longlist = cur1;
	}*/
	int k = abs(len1 - len2);
	while (k--)
	{
		longlist = longlist->next;
	}
	while (longlist)
	{
		if (longlist == shortlist)
			return longlist;
		longlist  = longlist->next;
		shortlist = shortlist->next;
	}
	return NULL;
}
static bool NodeCir(LN* head) //是否有环
{
	assert(head);
	LN* slow = head;
	LN* fast = head;
	while (fast)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return true;
		}
	}
	return false;
}
static LN* NodeCirFirst(LN* head)//环的入口节点
{
	assert(head);
	LN* slow = head;
	LN* fast = head;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			break;
		}
	}
	if (fast->next==NULL || fast->next->next == NULL)
		return NULL;
	LN* meet = slow;
	while (meet != head)
	{
		meet = meet->next;
		head = head->next;
	}
	return meet;
}
static LN* NodeTwoSort(LN* l1, LN* l2) //两个有序链表的排序
{
	if (l1 == NULL && l2 == NULL)
		return NULL;
	if (!l1)
		return l2;
	if (!l2)
		return l1;
	LN* newhead, * newtail;
	newhead = newtail = (LN*)malloc(sizeof(LN));
	assert(newhead && newtail);
	newhead->next = newtail->next = NULL;
	LN* cur1 = l1, * cur2 = l2;
	while (cur1 && cur2)
	{
		if (cur1->data < cur2->data)
		{
			newtail->next = cur1;
			newtail = cur1;
			cur1 = cur1->next;
		}
		else
		{
			newtail->next = cur2;
			newtail = cur2;
			cur2 = cur2->next;
		}
	}
	while (cur1)
	{
		newtail->next = cur1;
		newtail = cur1;
		cur1 = cur1->next;
	}
	while (cur2)
	{
		newtail->next = cur2;
		newtail = cur2;
		cur2 = cur2->next;
	}
	LN* list = newhead->next;
	free(newhead);
	return list;
}
/*如1->2->3->4->5->6,left = 2,rigth =4
* 定义leftprev ,leftnode,rigthnode,rigthnext
* 在截断，在连接
*/
static void  Reverse(LN* head)
{
	assert(head);
	LN* n1 = NULL;
	LN* n2 = head;
	while (n2)
	{
		LN* n3 = n2->next;
		n2->next = n1;
		n1 = n2;
		n2 = n3;
	}
}
static LN* NodeTwoReverse(LN* head, int left, int rigth) //逆置左节点和右节点区间
{
	assert(head);
	LN* leftprev = NULL;
	LN* cur = head;
	left--;
	while (left--)
	{
		leftprev = cur;
		cur = cur->next;
	}
	LN * leftnode = cur;
	rigth--;
	cur = head;
	while (rigth--)
	{
		cur = cur->next;
	}
	LN* rigthnode = cur;
	LN* rigthnext = rigthnode->next;
	//截断
	leftprev->next = NULL;
	rigthnode->next = NULL;
	//逆置
	Reverse(leftnode);
	//连接
	leftprev->next = rigthnode;
	leftnode->next = rigthnext;
	return head;
}
static LN* NodeInsertSort(LN* head)//对链表进行插入排序
{
	assert(head);
	LN* sorthead = head;
	LN* cur = head->next;
	sorthead->next = NULL;
	while (cur)
	{
		LN* next = cur->next;
		//头插
		if (cur->data <= sorthead->data)
		{
			cur->next = sorthead;
			sorthead = cur;
		}
		else
		{
			LN* prev = sorthead;
			LN* sortcur = sorthead->next;
			while (sortcur)
			{
				if (sortcur->data > cur->data)   //中间插
				{
					cur->next = sortcur;
					prev->next = cur;
					break;
				}
				else
				{
					prev = sortcur;
					sortcur = sortcur->next;
				}
			}
			if (!sortcur)   //尾插
			{
				prev->next = cur;
				cur->next = NULL;
			}
		}
		cur = next;
	}
	return sorthead;
}
void ListNode()//总接口
{
	//LN* root = NULL;
	//while (1)
	//{
	//	int x;
	//	printf("Please input number\n");
	//	scanf("%d", &x);
	//	if (x == -1)
	//	{
	//		break;
	//	}
	//	//NodePushBack(&root, x);
	//	NodePushBack(&root, x);
	//}
	/*printf("the behind of reverse\n");
	NodePrintf(root);
	NodeReverse(&root);
	printf("the end of reverse\n");
	NodePrintf(root);*/
	/*NodeClassified(&root);
	NodePrintf(root);*/
	/*
	* 验证函数的功能
	*  NodePopBack(&root) 尾删
	*  NodePopFront(&root) 头删
	*  NodeFind(root, 5)  查找
	*/
	//NodePopBack(&root);
	//NodePopFront(&root);
	//NodePrintf(root);
	//LN * ret = NodeFind(root, 5);
	/*if (ret)
	{
		printf("the node is %d\n", ret->data);	
	}
	else
	{
		printf("no find the node\n");
	}*/
	//NodeInsert(root, ret, 4);
	/*LN *ret = NodeMid(root);
	NodePrintf(ret);*/
	//printf("%d\n", NodePalindrome(root));
	//LN* root1 = NULL;
	//while (1)
	//{
	//	int x;
	//	printf("Please input number\n");
	//	scanf("%d", &x);
	//	if (x == -1)
	//	{
	//		break;
	//	}
	//	//NodePushBack(&root, x);
	//	NodePushBack(&root1, x);
	//}
	//NodePrintf(root1);
	//LN* root2 = NULL;
	//while (1)
	//{
	//	int x;
	//	printf("Please input number\n");
	//	scanf("%d", &x);
	//	if (x == -1)
	//	{
	//		break;
	//	}
	//	//NodePushBack(&root, x);
	//	NodePushBack(&root2, x);
	//}
	//NodePrintf(root2);
	//LN * ret = NodeTwoAdd(root1, root2);
	//NodePrintf(ret);
	//LN* root1 = NULL;
	//while (1)
	//{
	//	int x;
	//	printf("Please input number\n");
	//	scanf("%d", &x);
	//	if (x == -1)
	//	{
	//		break;
	//	}
	//	//NodePushBack(&root, x);
	//	NodePushBack(&root1, x);
	//}
	//NodePrintf(root1);
	//LN* root2 = NULL;
	//while (1)
	//{
	//	int x;
	//	printf("Please input number\n");
	//	scanf("%d", &x);
	//	if (x == -1)
	//	{
	//		break;
	//	}
	//	//NodePushBack(&root, x);
	//	NodePushBack(&root2, x);
	//}
	//NodePrintf(root2);
	//LN* cur2 = root2;
	//while (cur2->next != NULL)
	//{
	//	cur2 = cur2->next;
	//}
	//cur2->next = root1->next;
	//LN* ret = NodeTwoCross(root1, root2);
	//NodePrintf(root1);
	//NodePrintf(root2);
	//NodePrintf(ret);
 //   LN* root1 = NULL;
	//while (1)
	//{
	//	int x;
	//	printf("Please input number\n");
	//	scanf("%d", &x);
	//	if (x == -1)
	//	{
	//		break;
	//	}
	//	//NodePushBack(&root, x);
	//	NodePushBack(&root1, x);
	//}
	//NodePrintf(root1);
	//LN* tail = root1;
	//while (tail->next != NULL)
	//{
	//	tail = tail->next;
	//}
	//tail->next = root1->next->next->next;
	////printf("%d\n", NodeCir(root1));
	//LN* ret = NodeCirFirst(root1);
	//printf("%d", ret->data);

	//LN* root1 = NULL;
	//while (1)
	//{
	//	int x;
	//	printf("Please input number\n");
	//	scanf("%d", &x);
	//	if (x == -1)
	//	{
	//		break;
	//	}
	//	//NodePushBack(&root, x);
	//	NodePushBack(&root1, x);
	//}
	//NodePrintf(root1);
	//LN * ret = NodeTwoReverse(root1, 2, 4);
	//NodePrintf(ret);
	//LN* root2 = NULL;
	//while (1)
	//{
	//	int x;
	//	printf("Please input number\n");
	//	scanf("%d", &x);
	//	if (x == -1)
	//	{
	//		break;
	//	}
	//	//NodePushBack(&root, x);
	//	NodePushBack(&root2, x);
	//}
	//NodePrintf(root2);
	//LN * ret = NodeTwoSort(root1, root2);
	//NodePrintf(ret);



	LN* root1 = NULL;
	while (1)
	{
		int x;
		printf("Please input number\n");
		scanf("%d", &x);
		if (x == -1)
		{
			break;
		}
		//NodePushBack(&root, x);
		NodePushBack(&root1, x);
	}
	NodePrintf(root1);
	LN * ret = NodeInsertSort(root1);
	NodePrintf(ret);
}