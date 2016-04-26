
//��Ŀ����
//
//�������������ʾ��������ÿ��������һ����λ����Щ��λ�Ƿ����ŵģ�Ҳ���Ǹ�λ����������ײ�����д������������������ͣ�����������ʽ���ؽ����
//������������ListNode* A��ListNode* B���뷵��A + B�Ľ��(ListNode*)��



struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class Plus {
public:
	ListNode* plusAB(ListNode* a, ListNode* b) {
		// write code here
		if (a==nullptr&&b!=nullptr)
		{
			return b;
		}
		else if (a!=nullptr&&b==nullptr)
		{
			return a;
		}
		else if (a==nullptr&&b==nullptr)
		{
			return nullptr;
		}
		else
		{
			ListNode *cHead = new ListNode(-1);
			ListNode *c = cHead;
			while (a!=nullptr&&b!=nullptr)
			{
				int temp = 0,carry = 0;
				if (a->val+b->val<10)
				{
					temp = a->val + b->val+carry;
				}
				else
				{
					int temp = (carry+a->val + b->val) % 10;
					carry = (carry + a->val + b->val) / 10;
				}
				ListNode *tmp = new ListNode(temp);
				c->next = tmp;
				c = c->next;
				a = a->next;
				b = b->next;
			}
			if (a||b)
			{
				c->next = a;
				c->next = b;
			}
			c->next = nullptr;

			return cHead->next;
			delete cHead;
		}		
	}
};

//�����˼·�ܼ򵥣�����Сѧ��ѧ��ѧϰ�ļӷ�ԭ���ĩβ����λ����ÿһλ������Ӽ��ɡ�����������δ���ͬ���ȵ����֣�
//�Լ���λ�����λ���жϡ�������ڲ�ͬ���ȵ����֣�����ͨ�����϶̵����ֲ�0����֤ÿһλ������ӡ�

ListNode* plusAB(ListNode* a, ListNode* b) {
	int carry = 0;
	ListNode *retHead = new ListNode(0);
	ListNode *p = retHead;
	while (a || b || carry) {
		int vala = a ? a->val : 0;
		int valb = b ? b->val : 0;
		int val = (vala + valb + carry) % 10;
		carry = (vala + valb + carry) / 10;  //��λ
		ListNode *tmp = new ListNode(val);
		p->next = tmp;
		p = p->next;
		a = a ? a->next : nullptr;
		b = b ? b->next : nullptr;
	}
	p->next = nullptr;
	return retHead->next;
}