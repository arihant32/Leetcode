/*

You are given a pointer to the root of a binary tree. Print the top view of the binary tree.
Top view means when you look the tree from the top the nodes, what you will see will be called the top view of the tree. See the example below.
You only have to complete the function.
For example :

   1
    \
     2
      \
       5
      /  \
     3    6
      \
       4
Top View : 1 -> 2 -> 5 -> 6

Input Format

You are given a function,

void topView(node * root) {

}
Constraints

1 Nodes in the tree  500

Output Format

Print the values on a single line separated by space.

Sample Input

   1
    \
     2
      \
       5
      /  \
     3    6
      \
       4
Sample Output

1 2 5 6

Explanation

   1
    \
     2
      \
       5
      /  \
     3    6
      \
       4
From the top only nodes 1,2,5,6 will be visible.

*/


// Solution : Used level order traversal to solved it


#/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    // it will use for horizontal distance
    struct Hnode {
        Node *ptr;
        int hd;
    };

    void topView(Node * root) {

        map<int,int> mp;
        queue<Hnode*> q;
        Hnode *tmp = new Hnode();
        tmp->hd = 0;
        tmp->ptr = root;
        q.push(tmp);
        while(!q.empty()) {
            Hnode *t = q.front();
            q.pop();
            if(mp.find(t->hd) == mp.end()){
                 mp[t->hd] = t->ptr->data;
            }
            if(t->ptr->left) {
                Hnode *temp = new Hnode();
                temp->hd = t->hd -1;
                temp->ptr = t->ptr->left;
                q.push(temp);
            }
            if(t->ptr->right) {
                Hnode *temp = new Hnode();
                temp->hd = t->hd + 1;
                temp->ptr = t->ptr->right;
                q.push(temp);
            }
        }
            
        for(auto ptr= mp.begin(); ptr!=mp.end(); ptr++)
            cout<<ptr->second<<" ";

    }

}; //End of Solution




// 2nd solution

    void fillMap(Node* root,int hd,int l,map<int,pair<int,int>> &m) { 
        if(root==NULL) return; 
  
        if(m.find(hd)==m.end()) 
            m[hd] = {root->data,l};
        else if(m[hd].second>l)
            m[hd] = {root->data,l};
  
        fillMap(root->left,hd-1,l+1,m); 
        fillMap(root->right,hd+1,l+1,m); 
    } 
  
    void topView(Node * root) {
        map<int,pair<int,int>> m; 
        //fillmap(root,vectical_distance_from_root,level_of_node,map) 
        fillMap(root,0,0,m); 
        for(auto it=m.begin();it!=m.end();it++){ 
            cout << it->second.first << " "; 
         } 
    }

    
    }

}; //End of Solution
