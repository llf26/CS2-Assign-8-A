/*
   COPYRIGHT (C) 2017 Student Name (UANET ID ) All rights reserved.
   CS assignment
   Author.  Student Name
            zippy@zips.uakron.edu
   Version. 1.01 09.09.2017
   Purpose: This program ...
*/
#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <algorithm>
#include "treenode.hpp"

// Tree class-template definition
template<typename NODETYPE> class Tree {
public:
   // insert node in Tree
   void insertNode(const NODETYPE& value) {
      insertNodeHelper(&rootPtr, value);
   }

   // begin preorder traversal of Tree
   void preOrderTraversal() const {
      preOrderHelper(rootPtr);
   }

   // begin inorder traversal of Tree
   void inOrderTraversal() const {
      inOrderHelper(rootPtr);
   }

   // begin postorder traversal of Tree
   void postOrderTraversal() const {
      postOrderHelper(rootPtr);
   }

   // get the depth of the tree
   int getDepth() const {
      int totalDepth{0};
      int currentDepth{0};

      determineDepth(rootPtr, &totalDepth, &currentDepth);
      return totalDepth;
   }

   // begin binary search
   TreeNode<NODETYPE>* binaryTreeSearch(int val) const {
      return binarySearchHelper(rootPtr, val);
   }

private:
   TreeNode<NODETYPE>* rootPtr{nullptr};

   // utility function called by insertNode; receives a pointer
   // to a pointer so that the function can modify pointer's value
   void insertNodeHelper(
      TreeNode<NODETYPE>** ptr, const NODETYPE& value) {
      // subtree is empty; create new TreeNode containing value
      if (*ptr == nullptr) {
         *ptr = new TreeNode<NODETYPE>(value);
      }
      else { // subtree is not empty
             // data to insert is less than data in current node
         if (value <= (*ptr)->data) {
            insertNodeHelper(&((*ptr)->leftPtr), value);
         }
         else {
            insertNodeHelper(&((*ptr)->rightPtr), value);
         }
      }
   }

   // utility function to perform preorder traversal of Tree
   void preOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         std::cout << ptr->data << ' '; // process node
         preOrderHelper(ptr->leftPtr); // traverse left subtree
         preOrderHelper(ptr->rightPtr); // traverse right subtree
      }
   }

   // utility function to perform inorder traversal of Tree
   void inOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         inOrderHelper(ptr->leftPtr); // traverse left subtree
         std::cout << ptr->data << ' '; // process node
         inOrderHelper(ptr->rightPtr); // traverse right subtree
      }
   }

   // utility function to perform postorder traversal of Tree
   void postOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         postOrderHelper(ptr->leftPtr); // traverse left subtree
         postOrderHelper(ptr->rightPtr); // traverse right subtree
         std::cout << ptr->data << ' '; // process node
      }
   }

   // calculate the depth of the tree
   void determineDepth(TreeNode<NODETYPE>* leaf) {
    //If there are no nodes, return 0. Find max depth of right and left sub trees.
    //Return 1 + depth of tree because the lst and rst are one deeper than the root
    if(leaf){ return 1 + max( maxDepth(leaf->left), maxDepth(leaf->right)); }
    return 0;




      }


   // do a binary search on the Tree
   TreeNode<NODETYPE>* binarySearchHelper(TreeNode<NODETYPE>* leaf, NODETYPE value) const{
   //If the tree is not empty
   if(leaf != NULL)
   {
       //If value is already equal to the leaf node
       if(value == leaf->data)
        {
        std::cout << "Comparing " << value << " to " << leaf->data << ": search complete" << std::endl;
        return leaf;
        }

       //If value is less than leaf node
       if(value < leaf->data)
       {
          //Go left and compare again
           std::cout << "Comparing " << value << " to " << leaf->data << ": smaller, walk left" << std::endl;
           TreeNode<NODETYPE>* tmplft = leaf->getLeftPtr();
           return binarySearchHelper(tmplft, value);
       }
       //If value is greater than leaf node
       else
       {
           //Go right and compare again
           std::cout << "Comparing " << value << " to " << leaf->data << ": larger, walk right" << std::endl;
           TreeNode<NODETYPE>* tmpright = leaf->getRightPtr();
           return binarySearchHelper(tmpright, value);
       }



   }
   else return NULL;





   }

};

#endif // TREE_HPP

