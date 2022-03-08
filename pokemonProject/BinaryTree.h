/**********************************************************************
	Title:        BinaryTree.h
	Author:       Victor Hugo Battonyai De Oliveira
	Date Created: 4/05/2021
	Purpose:      BinaryTree Header
***********************************************************************/
#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <iostream>

using namespace std;

template <typename T>
class BinaryTree {
    private:
        struct TreeNode {
            T val;
            TreeNode * left; 
            TreeNode * right;
        };

        TreeNode * root;
        
        /* INSERT - recursive func inserting node into binary search tree */
        void insert(TreeNode *&node, TreeNode *&nextNode) {
            if (node == nullptr) {//insert into first node 
                node = nextNode;
            }              
            else if (nextNode->val < node->val) {//insert into left node tree
                insert(node->left, nextNode);  
            }  
            else {//insert into right node tree
                insert(node->right, nextNode);
            }
        }

        /* DESTROY - recursive func delete all nodes in search tree */
        void destroySubTree(TreeNode *newNode) {
            if (newNode) {
                if (newNode->left) { //delete left node tree
                    destroySubTree(newNode->left);
                }
                if (newNode->right) { //delete right node tree

                    destroySubTree(newNode->right);
                }

                delete newNode; //delete node
            }
        }

        /* DISPLAY - recursive func print nodes in order */
        void displayInOrder(TreeNode *nodePointer) const {
            if (nodePointer) {
                displayInOrder(nodePointer->left);
                cout << nodePointer->val << endl;
                displayInOrder(nodePointer->right);
            }
        }
    
    public:
        /* constructor */
        BinaryTree() {
            root = NULL;
        }

        /* destructor */
        ~BinaryTree() {
            destroySubTree(root);
        }

        /* put template val into node then call insert func */
        void insertNode(T member) {
            TreeNode * node = new TreeNode;

            node->val = member;
            node->left = nullptr;
            node->right = nullptr;
            
            insert(root, node);
        }

        /* display */
        void displayInOrder() const {
            displayInOrder(root);
        }

        /* bool func to find given node, return true if found, false if not */
        bool searchNode(T member) {
            TreeNode *node = root;
            while (node) {
                if (node->val == member) {
                    return true;
                }
                else if (member < node->val) {
                    node = node->left;
                }
                else {
                    node = node->right;
                }
            }
            
            return false;
        }
};

#endif