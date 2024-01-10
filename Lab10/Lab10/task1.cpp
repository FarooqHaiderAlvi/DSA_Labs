//#include <iostream>
//using namespace std;
//#include <cmath>
//#include <stack>
//#include <queue>
//
//template<class T>
//class BinaryTree {
//private:
//	int size;
//	T* data;
//	bool* status;
//public:
//	BinaryTree(int h) {
//		size = pow(2, h)-1;
//		data = new int[size];
//		status = new bool[size];
//
//		for (int i = 0; i < size; i++) {
//			data[i] = i+1;
//			if (i == 12)
//				status[i] = false;
//			else 
//				status[i] = true;
//		}
//	}
//	void setRoot(T val) {
//		if (!status[0]) {
//			data[0] = val;
//			status[0] = false;
//		}
//			
//	}
//	void setLeftChild(T parent, T val) {
//
//		int child = parent * 2 + 1;
//		if (status[parent] && child<size) {
//			data[child] = val;
//			status[child] = false;
//		}
//		else {
//			cout << "index goes out of bound or parent not found::" << endl;
//		}
//	}
//	void setRightChild(T parent, T val) {
//
//		int child = parent * 2 + 2;
//		if (status[parent] && child<size) {
//			data[child] = val;
//			status[child] = false;
//		}
//		else {
//			cout << "index goes out of bound or parent not found::" << endl;
//		}
//	}
//
//	int getParent(int node) {
//
//		int parent = 0;
//		if (node % 2 == 0)
//			parent = (node - 2) / 2;
//		else
//			parent = (node - 1) / 2;
//
//		if (status[node] && parent > -1)
//			return parent;
//		else return -1;
//
//	}
//
//	int getRightChild(int par) {
//
//		if (par < 0)
//			return -1;
//
//		int child = par * 2 + 2;
//		if (status[par] && child < size) {
//			return child;
//		}
//		else return -1;
//	}
//
//	int getLeftChild(int par) {
//
//		if(par<0)
//			return -1;
//
//		int child = par * 2 + 1;
//		if (status[par] && child < size) {
//			return child;
//		}
//		else return -1;
//	}
//
//
//	void removeDesc(int node) {
//		stack<int> stak;
//
//		stak.push(node);
//
//		while (!stak.empty()) {
//			int desc = stak.top();
//			stak.pop();
//			int left = desc * 2 + 1;
//			int right = desc * 2 + 2;
//			status[desc] = false;
//
//			if (right < size && data[right])
//				stak.push(right);
//
//				if (left < size && data[left])
//					stak.push(left);
//								
//		}
//
//
//	}
//
//	void printAnces(int index) {
//
//		while (index >= 0) {
//			if (status[index]) {
//				cout << data[index] << endl;
//			}
//
//			if (index % 2 == 0)
//				index = (index - 2) / 2;
//			else
//				index = (index - 1) / 2;
//		}
//
//	}
//
//
//	bool isPerfect(int index) {
//		int left = index * 2 + 1;
//		int right = index * 2 + 2;
//		int leftLeft = left * 2 + 1;
//		int rightLeft = right * 2 + 1;
//
//		if (left < size && right < size) {
//			if ((status[left] == false ) != (status[right] == false))
//				return false;
//
//			if (status[left] == false )
//				return true;
//		}
//		if (leftLeft < size && rightLeft < size) {
//		
//			if (( status[leftLeft] == false ) != (  status[rightLeft] == false ))
//				return false;
//		}
//
//		
//		if (left < size && right < size) {
//			if (!isPerfect(left) || !isPerfect(right))
//				return false;
//	   }
//
//		
//
//		return true;
//	}
//
//	bool isComplete(int index) {
//		queue<int> q;
//
//		q.push(index);
//		bool flag = false;
//		while (!q.empty()) {
//
//			int temp = q.front();
//			q.pop();
//			int left = getLeftChild(temp);
//			int right = getRightChild(temp);
//			if (temp < 0)
//				return false;
//
//			if (status[temp] == false) {
//				flag = true;
//			}
//
//			else {
//				if (flag == true)
//					return false;
//
//				q.push(left > 0 ? left : -1);
//				q.push(right > 0? right : -1);
//			}
//
//
//				
//
//		}
//			return true;
//	}
//
//	/*int height(Node* root) {
//		if (root == nullptr) return 0;
//		return max(height(root->left), height(root->right)) + 1;
//	}*/
//};
//int main() {
//	BinaryTree<int> tree(4);
////	tree.removeDesc(1);
//	//tree.printAnces(6);
//
//	if (tree.isComplete(0))
//		cout << "yes";
//	else cout << "No";
//}
//
//
//
//
//
//
