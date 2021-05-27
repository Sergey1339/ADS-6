// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 public:
  struct Node {
    T value;
    int count;
    Node* left;
    Node* right;
  };

 private:
  Node* root;
  Node* AddNode(Node* root, T value);
  int SearchNode(Node* root, T value);
  int DepthTree(Node* root);

 public:
  BST() :root(nullptr) {}
  ~BST() {}
  void add(T value);
  int search(T value);
  int depth();
};
/*                                                             Реализация privat секции */
typename BST<T>::Node* BST<T>::AddNode(Node* root, T value) {
    if (root == nullptr) {
      root = new Node;
      root->left = nullptr;
      root->right = nullptr;
      root->value = value;
      root->count = 1;
    } else if (root->value > value) {
      root->left = addNode(root->left, value);
    } else if (root->value < value) {
      root->right = addNode(root->right, value);
    } else {
      root->count++;
    }
    return root;
}

int BST<T>::SearchNode(Node* root, T value) {
    if (root == nullptr)
      return 0;
    else if (root->value > value)
      return SearchNode(root->left, value);
    else if (root->value < value)
      return SearchNode(root->right, value);
    else
      return root->count;
}

int BST<T>::DepthTree(Node* root) {
    if ((root == nullptr) || (root->left == nullptr && root->right == nullptr))
      return 0;
    int left_h = DepthTree(root->left), right_h = DepthTree(root->right);
    return (left_h > right_h ? left_h : right_h) + 1;
}
/*                                                             Реализация public секции */
void BST<T>::add(T value) {
    root = AddNode(root, value);
}

int BST<T>::search(T value) {
    return SearchNode(root, value);
}

int BST<T>::depth() {
    return DepthTree(root);
}
#endif  // INCLUDE_BST_H_
