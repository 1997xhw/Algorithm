#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
	int val;
    TreeNode *left;
  	TreeNode *right;
   	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Codec {
//public:
//
//    // Encodes a tree to a single string.
//    string serialize(TreeNode* root) {
//        if(root == NULL) {
//            return NULL;
//        }
//        String treeString = "";
//        serialize(root, treeString);
//        return treeString;        
//    }
//
//    void serialize(TreeNode* root, String ts ) {
//        if (root != NULL){
//        ts += root.val;
//        ts += '#';
//        } else {
//            return;
//        }
//        serialize(root.left, ts);
//        serialize(root.right, ts);
//
//
//    }
//
//    // Decodes your encoded data to tree.
//    TreeNode* deserialize(string data) {
//        
//    }
//};

int main() {
	int a = 222;
	string s = to_string(a);
	cout << s;
	return 0;
} 
