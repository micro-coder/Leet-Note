// BSTree.cpp : 定义控制台应用程序的入口点。
#include <iostream>
#include "BSTree.h"
using namespace std;
int main()
{
    BSTree<int> btree;
    int temp;
    cout<<"请输入二叉树结点以构造二叉查找树："<<endl;
    while(cin>>temp )
        btree.insert(temp);
    cin.clear();

    //cout<<"前序遍历二叉查找树:"<<endl;
    //s.postOrder();
    //cout<<endl;


    //cout<<"中序遍历二叉查找树:"<<endl;
    //s.inOrder();
    //cout<<endl;


    //cout<<"后序遍历二叉查找树:"<<endl;
    //s.postOrder();
    //cout<<endl;


    cout<<"打印二叉查找树"<<endl;
    btree.print();

	cout<<"验证二叉查找树"<<endl;
	bool flag=btree.checkBST();
	if(flag) cout<<"是二叉查找树"<<endl;
	else cout<<"不是二叉查找树"<<endl;

    cout<<"请输入要查找的数："<<endl;
    while(cin>>temp)
    {
        BSTNode<int>* findnode = btree.search(temp);
        if(!findnode)
        {
            cout<<"查找失败"<<endl;
            btree.insert(temp);
            cout<<"已经将"<<temp<<"插入二叉查找树,现在二叉查找树中序遍历为："<<endl;
            btree.inOrder();
            cout<<endl;
        }
        else
        {
            cout<<findnode->_key<<"查找成功"<<endl;
        }
    }
    cin.clear();

    //cout<<"请输入结点以查找其前驱节点"<<endl;
    //BSTNode<int>* findPreNode= new BSTNode<int>(1,NULL,NULL,NULL);
    //while(cin>>findPreNode->_key)
    //{
    //    BSTNode<int>* preNode ;
    //    if((preNode= s.predecessor(findPreNode))!=NULL)
    //    {
    //        cout<<"其前驱结点为：";
    //        cout<<preNode->_key<<endl;
    //    }
    //    else 
    //        cout<<"没有前驱结点"<<endl;

    //    if((preNode= s.sucessor(findPreNode))!=NULL)
    //    {
    //        cout<<"其后继结点为：";
    //        cout<<preNode->_key<<endl;
    //    }
    //    else 
    //        cout<<"没有后继结点"<<endl;
    //}

    //cin.clear();
    cout<<"请输入要删除的结点："<<endl;
    while(cin >>temp)
    {

        btree.remove(temp);
        cout<<"删除后的二叉排序树："<<endl;
        btree.inOrder();
		btree.print();
    }
	cin.clear();

    //BSTNode<int>* maxNode =  s.minimumNode();
    //if(!maxNode)
    //    cout<<"最小的节点为："<<maxNode->_key<<endl;

    //BSTNode<int>* minNode = s.maximumNode();
    //if(!minNode)
    //    cout<<"最大的节点为："<<minNode->_key<<endl;

    //cout<<"销毁二叉树"<<endl;
    //s.destory();
    //s.inOrder();

    return 0;
}