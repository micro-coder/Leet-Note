#ifndef REDBLACKTREE_RBTREE_H
#define REDBLACKTREE_RBTREE_H

//all keys are int
class Node {
public:
    int key;//关键字
    Node * p;//父结点
    Node * left;//左子结点
    Node * right;//右子结点
    enum c{RED,BLACK};
    c color;
    Node(int k);
};
class RBTree {
private:
    void InsertFixup(Node * n);
    void DeleteFixup(Node * n);
    void LeftRotate(Node * n);
    void RightRotate(Node * n);
    void TransPlant(Node * n1,Node * n2);
public:
    Node * root;
    explicit RBTree(Node * n);
    Node * Search(int k);
    void InorderTreeWalk(Node * n);
    Node * Minimum(Node *n);
    Node * Maximum();
    Node * Predecessor(Node * n);
    Node * Successor(Node * n);
    Node * Insert (int k);
    bool Delete(int k);

};

#endif //REDBLACKTREE_RBTREE_H