#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <memory> // for shared memroy


template<typename Dtype>
class BST {
private:
  struct Node {
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    Dtype data;

    Node() {}
    Node(const Dtype& data)
      : data(data) {}
  };

  // main root element of bst
  std::shared_ptr<Node> root_;


  typedef std::shared_ptr<Node> NodePointer;

public:
  BST();

  // Insert element into bst
  void insert(const Dtype&);

  // check whether bst contains element or not
  bool contains(const Dtype&);

private:
  // Implementaion of helper functions
  std::shared_ptr<Node> insert(std::shared_ptr<Node> root,
                               const Dtype& data);

  // Implemenation of contains
  std::shared_ptr<Node> find(const std::shared_ptr<Node>& root, const Dtype& data); 
};

#endif // _BST_H_
