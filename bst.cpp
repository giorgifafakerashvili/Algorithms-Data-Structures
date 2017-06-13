#include "bst.h"

template<typename Dtype>
BST<Dtype>::BST() {
  //
}

/**
 * Insert an element into bst
 * It's not guaranteed to be
 * balanced BST
 */
template<typename Dtype>
void BST<Dtype>::insert(const Dtype& data) {
  if(root_ == nullptr) {
    root_ = std::make_shared<Node>(data);
  } else {
    root_ = insert(root_, data);
  }
}


/**
 * Returns true if finds and element
 */
template<typename Dtype>
bool BST<Dtype>::contains(const Dtype& data) {
  return find(root_, data) != nullptr;
}




/***********************************
 ***********************************
 * Implementaion of private helper functions
 ****************************************
 */
template<typename Dtype>
typename BST<Dtype>::NodePointer BST<Dtype>::insert(BST<Dtype>::NodePointer root, const Dtype& data) {
  if(root == nullptr) {
    return std::make_shared<Node>(data);
  }

  if(data < root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }

  return root;
}


template<typename Dtype>
typename BST<Dtype>::NodePointer BST<Dtype>::find(const BST<Dtype>::NodePointer root, const Dtype& data) {
  if(root == nullptr) return nullptr;

  if(root->data == data) return root;

  if(data < root->data) return find(root->left, data);
  return find(root->right, data);
}
