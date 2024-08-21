#include <iostream>
using namespace std;

struct node {
	int parent;
	int left=0;
	int right=0;
};
node* arr[1000001];
int head;
void lastOrder(int idx) {
	if (idx == 0)return;
	lastOrder(arr[idx]->left);
	lastOrder(arr[idx]->right);
	cout << idx << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int tmp; cin >> tmp;
	arr[tmp] = new node();
	head = tmp;
	int cnt = 9;
	while (true) {
		cin >> tmp;
		if (cin.eof() == 1) break;
		int idx = head;
		while (true) {
			if (tmp < idx) {
				if (arr[idx]->left == 0) {
					node* tmp2 = new node();
					tmp2->parent = idx;
					arr[idx]->left = tmp;
					arr[tmp] = tmp2;
					break;
				}
				else {
					idx = arr[idx]->left;
				}
			}
			else {
				if (arr[idx]->right == 0) {
					node* tmp2 = new node();
					tmp2->parent = idx;
					arr[idx]->right = tmp;
					arr[tmp] = tmp2;
					break;
				}
				else {
					idx = arr[idx]->right;
				}
			}
		}
	}
	lastOrder(head);
}