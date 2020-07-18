=begin

Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Constraints:

Both of the given trees will have between 1 and 200 nodes.
Both of the given trees will have values between 0 and 200

=end


# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val = 0, left = nil, right = nil)
#         @val = val
#         @left = left
#         @right = right
#     end
# end
# @param {TreeNode} root1
# @param {TreeNode} root2
# @return {Boolean}


def get_leafs(root, arr)
    return if root.nil?
    arr.push(root.val) if root.left.nil? &&  root.right.nil?
    get_leafs(root.left, arr)
    get_leafs(root.right, arr)
end

def leaf_similar(root1, root2)
    leafs_tree_1 = []
    leafs_tree_2 = []
    get_leafs(root1, leafs_tree_1)
    get_leafs(root2, leafs_tree_2)
    return leafs_tree_1.eql?(leafs_tree_2)
end
