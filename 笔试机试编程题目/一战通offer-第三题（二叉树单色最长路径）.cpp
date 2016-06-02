
//����һ���ɺڰ׵���ɵĶ�������������Ҫ�ҵ�������ĵ�ɫ��·�������м�·���Ķ����Ǵ����ϵ�ĳ�㿪ʼ�������߲��ظ��ĵ㵽���ϵ�
//��һ��������γɵ�·������·���ĳ��Ⱦ��Ǿ����ĵ������(���������յ�)��������������˵�ĵ�ɫ·����Ȼ����ֻ����һ����ɫ�ĵ��·����
//����Ҫ�ҵ����������ĵ�ɫ·����
//����һ�ö������ĸ��ڵ�(���ĵ���С�ڵ���300��������O(n)�ĸ��Ӷ�)���뷵�����ɫ·���ĳ��ȡ�
//����Ľڵ���ɫ�ɵ��ϵ�Ȩֵ��ʾ��ȨֵΪ1���Ǻڵ㣬Ϊ0���ǰ׵㡣


//�����ö�̬�滮����⡣��Ҫ�õ�һ�����ô�ֵ(white��black)����¼ÿ���ڵ�����Һ��ӽڵ�ĺڰ�·������ֵ����������
//�磺lhswhite ��lhsblack ��rhswhite��rhsblack�ֱ��ʾ�������ӽڵ�ĺڰ��·������
//�����������
//��1�������ڵ�Ϊ��ʱ����white = 0��black = max(lhsblack + 1, rhsblack + 1)���������ɫ·������Ϊlhsblack + rhsblack + 1��
//��2�������ڵ�Ϊ��ʱ����black = 0��white = max(lhswhite + 1, rhswhite + 1)���������ɫ·������Ϊlhswhite + rhswhite + 1��

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};
//Ҳ��֪��Ϊʲô���ǲ�AC,��������������𣿣�����
class LongestPath {
public:
	int result = 0;
	
	int findPath(TreeNode* root) {
		// write code here
		if (root==nullptr)
		{
			return 0;
		}
		int white = 0, black = 0;
		path(root,white,black);
		return result;
	}
	void path(TreeNode* root, int &white, int &balck)
	{
		if (root->right == nullptr&&root->right == nullptr)
		{
			if (root->val == 1)
			{
				balck = 1; white = 0;
			}
			else
			{
				balck = 0; white = 1;
			}
		}
		else
		{
			int lblack = 0, lwhite = 0;
			int rblack = 0, rwhite = 0;
			if (root->right != nullptr)
			{
				path(root->right, rwhite, rblack);
			}
			if (root->left != nullptr)
			{
				path(root->left, lwhite, lblack);
			}
			if (root->val == 1)
			{
				if (lblack + rblack + 1 > result)
					result = lblack + rblack + 1;
				white = 0;
				balck = (lblack + 1) > (rblack + 1) ? (lblack + 1) : (rblack + 1);
			}
			else
			{
				if (rwhite + lwhite + 1 > result)
					result = rwhite + lwhite + 1;
				balck = 0;
				white = (lwhite + 1) > (rwhite + 1) ? (lwhite + 1) : (rwhite + 1);
			}
		}
	}
};

class LongestPath {
public:
	int ret = 0;
	int findPath(TreeNode* root) {
		// write code here
		int white = 0, black = 0;
		dfsPath(root, white, black);
		return ret;
	}
	void dfsPath(TreeNode* root, int &white, int &black){
		if (root->left == nullptr && root->right == nullptr){
			if (root->val == 1){
				white = 0; black = 1;
			}
			else{
				white = 1; black = 0;
			}
		}
		else{
			int lhswhite = 0, lhsblack = 0;
			int rhswhite = 0, rhsblack = 0;
			if (root->left != nullptr) dfsPath(root->left, lhswhite, lhsblack);
			if (root->right != nullptr) dfsPath(root->right, rhswhite, rhsblack);
			if (root->val == 1){
				if (lhsblack + rhsblack + 1 > ret) ret = lhsblack + rhsblack + 1;
				white = 0;
				black = lhsblack + 1 > rhsblack + 1 ? lhsblack + 1 : rhsblack + 1;
			}
			else{
				if (lhswhite + rhswhite + 1 > ret) ret = lhswhite + rhswhite + 1;
				black = 0;
				white = lhswhite + 1 > rhswhite + 1 ? lhswhite + 1 : rhswhite + 1;
			}
		}
	}
};