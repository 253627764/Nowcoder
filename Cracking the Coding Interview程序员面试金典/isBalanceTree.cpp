//��Ŀ����
//
//ʵ��һ�����������������Ƿ�ƽ�⣬ƽ��Ķ������£��������е�����һ����㣬�����������ĸ߶Ȳ����1��
//����ָ����������ָ��TreeNode* root���뷵��һ��bool������������Ƿ�ƽ�⡣

//��Ŀ������
//<����1>��
//ƽ���������ͨ�����������ĸ߶����ж��Ƿ�Ϊƽ��������ģ��������������뵽���������һ�����ĸ߶ȣ���һ�����ĸ߶Ⱥܼ򵥣��ݹ���⣬ÿ������������������߶��ټ�1���Ǹ��ڵ�ĸ߶ȣ������ݹ���ȥ�����������κ�һ�����ĸ߶ȡ�
//��Ȼ��������κ�һ���ڵ�ĸ߶ȣ���ôͨ���ٴα������������ж��κ�һ���ڵ�����������߶�����Ƿ�����ƽ����������ʵ��ƽ����������жϡ�
//��һ��ƽ�����߶ȵ�ʱ�临�Ӷ�ΪO(logN)����ô�ڵڶ��α�����ʱ����Ҫ��ÿ���ڵ�ĸ߶�ʱ�临�Ӷ�ΪO(NlogN)����ʵ������̴󲿷ֶ����ظ��жϵģ�����ķ����Ǹ÷�����Ũ����
//<����2>��
//��һ�α����Ĺ����У�����һ���ڵ�ĸ߶ȣ�ͬʱ�ýڵ��Ƿ�����ƽ���������ݹ麯����һ�����ò��������ӽڵ�ĸ߶ȣ�Ȼ�󸸽ڵ�ĸ߶ȱ����ͨ�������ӽڵ�ĸ߶�������������ж������ӽڵ�ĸ߶��Ƿ�����ƽ���������������ֱ�ӷ��أ����������£������ǰ�ڵ�ĸ߶ȣ��������ϵݹ顣
//�÷�����ʱ�临�Ӷ�ֻ��O(logN)

struct TreeNode
{
	int val;
	struct TreeNode *right;
	struct TreeNode *left;
    TreeNode(int x):val(x), right(nullptr), left(nullptr){}

};

//����һ��
class Balance
{
public:
	int treeDeep(TreeNode *root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		//int deep = 0;
		int left = treeDeep(root->left);
		int right = treeDeep(root->right);
		return left > right ? (left + 1) : (right + 1);
	}
	bool isBalance(TreeNode *root)
	{
		if (root==nullptr)
		{
			return true;
		}
	/*	if (root->left!=nullptr)
		{

		}*/
		int left = treeDeep(root->left);
		int right = treeDeep(root->right);
		if (left-right>1||left-right<-1)
		{
			return false;
		}
		return isBalance(root->left) && isBalance(root->right);
	}

};

//������
class Balance {
public:
	bool isBalance(TreeNode* root) {
		// write code here
		int high = 0;
		return isBalance1(root, high);
	}
	bool isBalance1(TreeNode* root, int &high)
	{
		if (root == nullptr)
		{
			high = 0;
			return true;
		}
		int lhigh, rhigh;
		if (!isBalance1(root->left, lhigh) || !isBalance1(root->right, rhigh))
			return false;
		if (lhigh - rhigh>1 || lhigh - rhigh<-1)
			return false;
		high = (lhigh >= rhigh ? lhigh : rhigh) + 1;
		return true;
	}
};