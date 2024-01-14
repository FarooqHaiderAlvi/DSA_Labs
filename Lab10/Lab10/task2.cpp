//
//#include <iostream>
//using namespace std;
//#include <queue>
//#include <stack>
//
//template<class T>
//class BST;
//
//template<class T>
//class BSTNode
//{
//	friend BST<T>;
//	T data;
//	BSTNode<T>* left;
//	BSTNode<T>* right;
//
//	BSTNode(T val) {
//		data = val;
//		left = nullptr;
//		right = nullptr;
//	}
//	
//};
//template<class T>
//class BST
//{
//	BSTNode<T>* root;
//
//public:
//
//	BST() {
//		root = nullptr;
//	}
//
//	void insertion(T val) {
//		
//		if (!root)
//			root = new BSTNode<T>(val);
//		else {
//			BSTNode<T>* temp = root;
//			BSTNode<T>* prev = nullptr;
//
//			while (temp) {
//				prev = temp;
//				if (temp->data > val)
//					temp = temp->left;
//
//				else temp = temp->right;
//
//			}
//
//			if (prev->data > val){
//			    prev->left = new BSTNode<T>(val);
//			}
//			else{
//			    prev->right = new BSTNode<T>(val);
//			}
//
//		}
//
//	}
//
//	void levelOrderTraversal() {
//
//				queue<BSTNode<T>*> q;
//		
//				BSTNode<T>* temp = root;
//				BSTNode<T>* curr = root;
//		
//				if (curr) {
//					q.push(curr);
//					while (!q.empty()) {
//		
//						temp = q.front();
//		
//						cout << temp->data << " ";
//		
//						if (temp->left)
//							q.push(temp->left);
//						if (temp->right)
//							q.push(temp->right);
//		
//						q.pop();
//		
//		
//					}
//				}
//				
//		
//		
//	}
//
//	BSTNode<T>* returnRoot() 
//	{
//		return root;
//	}
//
//	bool isBST(BSTNode<T>*node) {
//
//		if (!node)
//			return true;
//
//		if (node->left) {
//			if (node->data < node->left->data)
//				return false;
//		}
//		
//		if (node->right) {
//
//			if ( node->data > node->right->data)
//			return false;
//		}
//
//		
//		if (!isBST(node->left) || !isBST(node->right))
//			return false;
//
//
//	}
//
//
//	void dispAnces(int val) {
//		queue<BSTNode<T>*> q;
//
//		BSTNode<T>* temp = root;
//
//		while (temp) {
//			if (temp->data == val)
//				break;
//			else
//				q.push(temp);
//
//
//			if (temp->data > val)
//			{
//				temp = temp->left;
//			}
//			else {
//				temp = temp->right;
//			}
//		}
//
//		if (temp) {
//			while (!q.empty()) {
//				BSTNode<T>* ances = q.front();
//				q.pop();
//				cout << ances->data << endl;
//			}
//		}
//	}
//
//	int getNodeCount(BSTNode<T>* tree) {
//
//		queue<BSTNode<T>*> q;
//		int count = 0;
//
//		if (tree) {
//			q.push(tree);
//			while (!q.empty()) {
//				BSTNode<T>* temp = q.front();
//				q.pop();
//				count++;
//				if (temp->left)
//					q.push(temp->left);
//				if (temp->right)
//					q.push(temp->right);
//
//			}
//		}
//		 return count;
//	}
//
//	int findMax(int a, int b) {
//
//		return (a > b ? a : b);
//	}
//
//	int findHeight(BSTNode<T>* node) {
//		if (!node)
//			return 0;
//		else
//			return 1 + findMax(findHeight(node->left), findHeight(node->right));
//	}
//
//	int getHeight()
//	{
//		int height = findHeight(root);
//		return height;
//	}
//
//	BST<T> getMirror() {
//
//		stack<BSTNode<T>*> st;
//		BSTNode<T>* temp = root;
//				st.push(temp);
//				
//		
//				while (!st.empty()) {
//					temp = st.top();
//					st.pop();
//					BSTNode<T>* hold = temp->left;
//
//					temp->left = temp->right;
//					temp->right = hold;
//
//
//		
//					if (temp->right)
//						st.push(temp->right);
//					if (temp->left)
//						st.push(temp->left);
//				}
//
//				return *this;
//	}
//
//	bool isEqual(BSTNode<T>* r1, BSTNode<T>* r2) {
//
//
//		stack<BSTNode<T>*> st1;
//		stack<BSTNode<T>*> st2;
//		BSTNode<T>* temp1 = r1;
//		BSTNode<T>* temp2 = r2;
//		st1.push(temp1);
//		st2.push(temp2);
//
//
//		while (!st1.empty() && !st2.empty()) {
//			temp1 = st1.top();
//			temp2 = st2.top();
//			st1.pop();
//			st2.pop();
//
//
//			if (temp1->data != temp2->data)
//				return false;
//
//
//			if (temp1->right)
//				st1.push(temp1->right);
//
//			if (temp1->left)
//				st1.push(temp1->left);
//
//			if (temp2->right)
//				st2.push(temp2->right);
//
//			if (temp2->left)
//				st2.push(temp2->left);
//		}
//
//		if (!st1.empty() || !st2.empty())
//			return false;
//
//		return true;
//
//	}
//
//	bool areEqual(BSTNode<T>* root1, BSTNode<T>* root2) {
//		// If both trees are empty, they are equal.
//		if (root1 == nullptr && root2 == nullptr) {
//			return true;
//		}
//
//		// If one of the trees is empty and the other is not, they are not equal.
//		if (root1 == nullptr || root2 == nullptr) {
//			return false;
//		}
//
//		// Check if the values of the current nodes are equal.
//		if (root1->data != root2->data) {
//			return false;
//		}
//
//		// Recursively check the left and right subtrees.
//		return areEqual(root1->left, root2->left) && areEqual(root1->right, root2->right);
//	}
//
//	void countNodesAtEachLevel() {
//
//		queue<BSTNode<T>*> q;
//
//		BSTNode<T>* temp = root;
//		int count = 0;
//
//		if (temp) {
//			q.push(temp);
//			while (!q.empty()) {
//
//				int levelSize = q.size();
//				cout << "nodes count at level " << count << ":: " << levelSize << "; and nodes data  " ;
//				
//				
//				for (int i = 0; i < levelSize; i++) {
//					temp = q.front();
//					q.pop();
//					cout << temp->data << " ";
//					if (temp->left)
//						q.push(temp->left);
//					if (temp->right)
//						q.push(temp->right);
//				}
//
//				
//				cout << endl;
//
//				count++;
//
//
//			}
//		}
//
//	}
//
//};
//
//
//int main() {
//	BST<int> tree;
//	tree.insertion(10);
//	tree.insertion(7);
//	tree.insertion(15);
//	tree.insertion(5);
//	tree.insertion(8);
//	tree.insertion(11);
//	 
////	tree.levelOrderTraversal();
////	tree.dispAnces(16);
//	//cout << tree.getHeight();
////	tree.countNodesAtEachLevel();
//		
//}