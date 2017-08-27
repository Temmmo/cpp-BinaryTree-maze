#ifndef __BIN_TREE_NODE_H__
#define __BIN_TREE_NODE_H__

// 三叉链表结点类
template <class ElemType>
struct TriTreeNode
{
// 数据成员:
	ElemType data;		// 数据域
	TriTreeNode<ElemType>  *leftChild;	// 左孩子指针域
	TriTreeNode<ElemType>  *midChild;	// 中孩子指针域
	TriTreeNode<ElemType>  *rightChild;	// 右孩子指针域

//	构造函数:
	TriTreeNode();		// 无参数的构造函数 
	TriTreeNode(const ElemType &d,// 已知数据元素值,指向左右孩子的指针构造一个结点
		TriTreeNode<ElemType> *lChild = NULL, TriTreeNode<ElemType> *mChild = NULL, 
		TriTreeNode<ElemType> *rChild = NULL);
};

// 三叉树结点类的实现部分
template <class ElemType>
TriTreeNode<ElemType>::TriTreeNode()
// 操作结果：构造一个叶结点
{
	leftChild = rightChild = midChild = NULL;	// 叶结点左中右孩子为空
}

template <class ElemType>
TriTreeNode<ElemType>::TriTreeNode(const ElemType &d, 
	TriTreeNode<ElemType> *lChild, TriTreeNode<ElemType> *mChild,TriTreeNode<ElemType> *rChild)
// 操作结果：构造一个数据域为d,左孩子为lChild,中孩子为cChild;右孩子为rChild的结点
{	
	data = d;		// 数据元素值
	leftChild = lChild;			// 左孩子
	midChild = mChild;	        //中孩子
	rightChild = rChild;		// 右孩子
}

#endif

