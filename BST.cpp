#include <iostream>
using namespace std;

struct TreeNode{
    int value;
    TreeNode* root;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){
         value = 0;
         root = NULL;
         left = NULL;
         right = NULL;
         }
    TreeNode(int v){
              value = v;
          }
};
    
 
  	TreeNode* insertRecursive(TreeNode *r, TreeNode *new_node)
	{
		if(r==NULL)
		{
			r=new_node;
			cout <<"Insertion successful"<<endl;
			return r;
		}
	
		if(new_node->value < r->value)
		{
			r->left = insertRecursive(r->left,new_node);
		}
		else if (new_node->value > r->value)  
		{
			r->right = insertRecursive(r->right,new_node);
		}
	   else
	   {
	     	cout << "No duplicate values allowed!" << endl;
	     	return r; 
		}
		return r;
	}
TreeNode * iterativeSearch(TreeNode * root,int v) {
    if (root == NULL) {
      return root;
    } else {
      TreeNode * temp = root;
      while (temp != NULL) {
        if (v == temp -> value) {
          return temp;
        } else if (v < temp -> value) {
          temp = temp -> left;
        } else {
          temp = temp -> right;
        }
      }
      return NULL;
    }
  }
TreeNode * minValueNode(TreeNode * node) {
    TreeNode * current = node;
    /* loop down to find the leftmost leaf */
    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
  }
  TreeNode * recursiveSearch(TreeNode * root, int v) {
    if (root == NULL || root -> value == v)
      return root;

    else if (v < root -> value)
      return recursiveSearch(root -> left, v);

    else
      return recursiveSearch(root -> right, v);
  }
  TreeNode * deleteNode(TreeNode * root, int v) {
    // base case 
    if (root == NULL) {
      return NULL;
    }
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    else if (v < root -> value) {
      root -> left = deleteNode(root -> left, v);
    }
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (v > root -> value) {
      root -> right = deleteNode(root -> right, v);
    }
    // if key is same as root's key, then This is the node to be deleted 
    else {
      // node with only one child or no child 
      if (root -> left == NULL) {
        TreeNode * temp = root -> right;
        delete root;
        return temp;
      } else if (root -> right == NULL) {
        TreeNode * temp = root -> left;
        delete root;
        return temp;
      } else {
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        TreeNode * temp = minValueNode(root -> right);
        // Copy the inorder successor's content to this node 
        root -> value = temp -> value;
        // Delete the inorder successor 
        root -> right = deleteNode(root -> right, temp -> value);
        //deleteNode(r->right, temp->value); 
      }
    }
    return root;
  }
  void printInorder(TreeNode * root) //  (Left, current node, Right)
  {
    if (root == NULL)
      return;
    /* first recur on left child */
    printInorder(root -> left);
    /* then print the data of node */
    cout << root -> value << " ";
    /* now recur on right child */
    printInorder(root -> right);
  }

int main() {
  TreeNode* root = NULL;
  int option, val;

  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Display tree" << endl;
    cout << "0. Exit Program" << endl;
    cin >> option;
    
TreeNode * new_node = new TreeNode();

    switch (option) {
    case 0:
      break;
      case 1:
      	cout <<"INSERT"<<endl;
	      cout <<"Enter VALUE of TREE NODE to INSERT in BST: ";
	      cin >> val;
	      new_node->value = val;
	      root= insertRecursive(root,new_node);
	      //obj.insertNode(new_node);
	      cout<<endl;
    		break;
      
    case 2:
      cout << "SEARCH" << endl;
      cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
      cin >> val;
      //new_node = obj.iterativeSearch(val);
      new_node = recursiveSearch(root, val);
      if (new_node != NULL) {
        cout << "Value found" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
    case 3:
      cout << "DELETE" << endl;
      cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
      cin >> val;
      new_node = iterativeSearch(root,val);
      if (new_node != NULL) {
        deleteNode(root, val);
        cout << "Value Deleted" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
      case 4:
      cout << "printing tree" << endl;
      printInorder(root);
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}