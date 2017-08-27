#ifndef __BINNARY_TREE_H__
#define __BIN24NARY_TREE_H__

#include "LinkQueue.h"				// 链队列
#include "BinTreeNode.h"	// 三叉树结点类
#include "SeqStack.h"
#include "LinkStack.h"

// 三叉树类
template <class ElemType>
class TriaryTree
{
protected:
//  三叉树的数据成员:
	TriTreeNode<ElemType> *root;

//	辅助函数:
	TriTreeNode<ElemType> *CopyTree(TriTreeNode<ElemType> *t);
// 复制三叉树
	void Destroy(TriTreeNode<ElemType> * &r);	// 删除以r为根三叉树
	void PreOrder(TriTreeNode<ElemType>*r,void(*Visit)(const ElemType&)) const;
		// 先序遍历以r为根的三叉树
	void InOrder(TriTreeNode<ElemType>*r,void (*Visit)(const ElemType &)) const;
		// 中序遍历以r为根的三叉树
	void PostOrder(TriTreeNode<ElemType>*r,
    void (*Visit)(const ElemType &)) const;	// 后序遍历以r为根的三叉树
    int Height(const TriTreeNode<ElemType> *r) const;
// 求以r为根的三叉树的高
	int NodeCount(const TriTreeNode<ElemType> *r) const;
// 求以r为根的三叉树的结点个数
	TriTreeNode<ElemType> *Parent(TriTreeNode<ElemType> *r,
		const TriTreeNode<ElemType>*p) const;//在以r为根的三叉树中求p的双亲

public:
//  三叉树方法声明及重载编译系统默认方法声明:
	TriaryTree();						// 无参数的构造函数
	TriaryTree(const ElemType &e);		// 构造以e为根的三叉树
	virtual ~TriaryTree();				// 析构函数
	TriTreeNode<ElemType> *GetRoot() const;	// 返回三叉树的根
	bool IsEmpty() const;				// 判断三叉树是否为空
	Status GetElem(TriTreeNode<ElemType> *p, ElemType &e) const;
		// 用e返回结点p元素值
	Status SetElem(TriTreeNode<ElemType> *p, const ElemType &e);
		// 将结点p的值置为e
	void InOrder(void (*Visit)(const ElemType &)) const;// 三叉树的中序遍历
	void PreOrder(void (*Visit)(const ElemType &)) const;// 三叉树的先序遍历
	void PostOrder(void (*Visit)(const ElemType &)) const;// 三叉树的后序遍历
	void LevelOrder(void (*Visit)(const ElemType &)) const;	// 三叉树的层次遍历
	int NodeCount() const;				// 求三叉树的结点个数
	TriTreeNode<ElemType> *LeftChild(const TriTreeNode<ElemType> *p) const;
		//  求结点p的左孩子
	TriTreeNode<ElemType> *RightChild(const TriTreeNode<ElemType> *p) const;
		// 求结点p的右孩子
	TriTreeNode<ElemType> *MidChild(const TriTreeNode<ElemType> *p) const;
		// 求结点p的中孩子
	TriTreeNode<ElemType> *Parent(const TriTreeNode<ElemType> *p) const;
		// 求结点p的双亲
	void InsertLeftChild(TriTreeNode<ElemType> *p, const ElemType &e);
        // 插入一个结点e作为p的左孩子
	void InsertRightChild(TriTreeNode<ElemType> *p, const ElemType &e);
        // 插入一个结点e作为p的右孩子
	void InsertMidChild(TriTreeNode<ElemType> *p, const ElemType &e);
        // 插入一个结点e作为p的中孩子
	void DeleteLeftChild(TriTreeNode<ElemType> *p);	// 删除p的左子树
	void DeleteRightChild(TriTreeNode<ElemType> *p);// 删除p的右子树
	void DeleteMidChild(TriTreeNode<ElemType> *p);// 删除p的中子树
	int	Height() const;							    // 求三叉树的高
	TriaryTree(const TriaryTree<ElemType> &t);	// 复制构造函数
	TriaryTree(TriTreeNode<ElemType> *r);			// 建立以r为根的三叉树
	TriaryTree<ElemType> &operator=(const TriaryTree<ElemType>& t);
		// 赋值运算符重载
	TriaryTree<ElemType> &operator!=(const TriaryTree<ElemType>& t);
		// 赋值运算符重载
};



template <class ElemType>
void DisplayBTWithTreeShape(TriTreeNode<ElemType> *r, int level);
	//	按树状形式显示以r为根的三叉树，level为层次数，可设根结点的层次数为1
template <class ElemType>
void DisplayBTWithTreeShape(TriaryTree<ElemType> &bt);
	//	树状形式显示三叉树
template <class ElemType>
void CreateTriaryTree(TriTreeNode<ElemType> *&r, ElemType pre[], ElemType in[],
	int preLeft, int preRight, int inLeft, int inRight);
	// 已知三叉树的先序序列pre[preLeft..preRight]和中序序列in[inLeft..inRight]构造以r为根的
	// 三叉树
template <class ElemType>
TriaryTree<ElemType> &CreateTriaryTree(ElemType pre[], ElemType in[], int n);
	// 已知先序和中序序列构造三叉树
template <class ElemType>
void DisplayBTWithTreeonShape(TriTreeNode<ElemType> *r, int level);
	//	------迷宫构成树的展示
template <class ElemType>
void DisplayBTWithTreeonShape(TriaryTree<ElemType> &bt);
	//	-------迷宫构成树的展示
template <class ElemType>
void CreateTriaryleftTreeon(TriTreeNode<ElemType> *&r,ElemType on[10][10],int i,int j);
	//-------------迷宫三叉树构造-----------左
template <class ElemType>
void CreateTriaryrightTreeon(TriTreeNode<ElemType> *&r,ElemType on[10][10],int i,int j);
	//-------------迷宫三叉树构造----------右
template <class ElemType>
void CreateTriarymidTreeon(TriTreeNode<ElemType> *&r,ElemType on[10][10],int i,int j);
	//-------------迷宫三叉树构造-----------中
template <class ElemType>
void CreateTriaryTreeon(TriTreeNode<ElemType> *&r,ElemType on[10][10],int i,int j);
	//-------------迷宫三叉树构造
template <class ElemType>
TriaryTree<ElemType> &CreateTriaryTreeon(ElemType on[10][10],int i,int j);
	// -------------迷宫三叉树构造
template <class ElemType>
void DisplayBTWithTreeonnShape(TriaryTree<ElemType> &bt,TriTreeNode<ElemType> *r);
	//	------迷宫构成树的展示--------历遍结点
template <class ElemType>
void DisplayBTWithTreeonnShapestack(TriaryTree<ElemType> &bt,TriTreeNode<ElemType> *r);
template <class ElemType>
	//------迷宫构成树的展示-------利用栈展示路径
void DisplayBTWithTreeonnShape(TriaryTree<ElemType> &bt);
	//	-------迷宫构成树的展示



// 三叉树类的实现部分
template <class ElemType>
TriaryTree<ElemType>::TriaryTree()
// 操作结果：构造一个空三叉树
{
	root = NULL;
}

template <class ElemType>
TriaryTree<ElemType>::~TriaryTree()
// 操作结果：删除三叉树--析造函数
{
	Destroy(root);
}

template <class ElemType>
TriTreeNode<ElemType> *TriaryTree<ElemType>::GetRoot() const
// 操作结果：返回三叉树的根
{
	return root;
}

template <class ElemType>
bool TriaryTree<ElemType>::IsEmpty() const
// 操作结果：判断三叉树是否为空
{
	return root == NULL;
}

template <class ElemType>
Status TriaryTree<ElemType>::GetElem(TriTreeNode<ElemType> *p, ElemType &e) const
// 操作结果：用e返回结点p元素值,如果不存在结点p,函数返回NOT_PRESENT,否则返回ENTRY_FOUND
{
	if (p == NULL)		// 不存在结点p
		return NOT_PRESENT;			// 返回NOT_PRESENT
	else	{	// 存在结点p
		e = p->data;				// 用e返回元素值
		return ENTRY_FOUND;			// 返回ENTRY_FOUND
	}
}

template <class ElemType>
Status TriaryTree<ElemType>::SetElem(TriTreeNode<ElemType> *p, const ElemType &e)
// 操作结果：如果不存在结点p,则返回FAIL,否则返回SUCCESS,并将结点p的值设置为e
{
	if (p == NULL)		// 不存在结点p
		return FAIL;				// 返回FAIL
	else	{	// 存在结点p
		p->data = e;				// 将结点p的值设置为e
		return SUCCESS;				// 返回SUCCESS
	}
}

template <class ElemType>
void TriaryTree<ElemType>::PreOrder(TriTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// 操作结果：先序遍历以r为根的三叉树
{
	if (r != NULL)	{
		(*Visit)(r->data);				// 首先访问根结点r
		PreOrder(r->leftChild, Visit);	// 再遍历r的左子树
		PreOrder(r->midChild, Visit);	// 再遍历r的中子树
		PreOrder(r->rightChild, Visit);	// 最后遍历r的右子树
	}
}

template <class ElemType>
void TriaryTree<ElemType>::PreOrder(void (*Visit)(const ElemType &)) const
// 操作结果：先序遍历三叉树
{
	PreOrder(root, Visit);
}

template <class ElemType>
void TriaryTree<ElemType>::InOrder(TriTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// 操作结果：中序遍历以r为根的三叉树
{
	if (r != NULL) 	{
		InOrder(r->leftChild, Visit);	// 首先遍历r的左子树
		PreOrder(r->midChild, Visit);	// 再遍历r的中子树
		(*Visit)(r->data);				// 再访问根结点r
		InOrder(r->rightChild, Visit);	// 最后遍历r的右子树
	}
}

template <class ElemType>
void TriaryTree<ElemType>::InOrder(void (*Visit)(const ElemType &)) const
// 操作结果：中序遍历三叉树
{
	InOrder(root, Visit);
}

template <class ElemType>
void TriaryTree<ElemType>::PostOrder(TriTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// 操作结果：后序遍历以r为根的三叉树
{
	if (r != NULL) 	{
		PostOrder(r->leftChild, Visit);	// 首先遍历r的左子树
		PreOrder(r->midChild, Visit);	// 再遍历r的中子树
		PostOrder(r->rightChild, Visit);// 再遍历r的右子树
		(*Visit)(r->data);				// 最后访问根结点r
	}
}

template <class ElemType>
void TriaryTree<ElemType>::PostOrder(void (*Visit)(const ElemType &)) const
// 操作结果：后序遍历三叉树
{
	PostOrder(root, Visit);
}

template <class ElemType>
void TriaryTree<ElemType>::LevelOrder(void (*Visit)(const ElemType &)) const
// 操作结果：层次遍历三叉树
{
	LinkQueue<TriTreeNode<ElemType> *> q;	// 定义队列q
	TriTreeNode<ElemType> *p;

	if (root != NULL) q.EnQueue(root);		// 如果根非空,则入队
	while (!q.IsEmpty())	{	            // q非空,说明还有结点未访问
		q.DelQueue(p);                      // 队头元素出队，并访问之
		(*Visit)(p->data);
		if (p->leftChild != NULL)			// 队头元素左孩子非空
			q.EnQueue(p->leftChild);		// 左孩子入队
		if (p->midChild != NULL)			// 队头元素右孩子非空
			q.EnQueue(p->midChild);		// 右孩子入队
		if (p->rightChild != NULL)			// 队头元素右孩子非空
			q.EnQueue(p->rightChild);		// 右孩子入队
            // 右孩子入队
	}
}

template <class ElemType>
int TriaryTree<ElemType>::Height(const TriTreeNode<ElemType> *r) const
// 操作结果：返回以r为根的三叉树的高
{
	if(r == NULL)	// 空三叉树高为0
		return 0;
	else	{	// 非空三叉树高为左右子树的高的最大值再加1
		int lHeight, rHeight;
		lHeight = Height(r->leftChild);		// 左子树的高
		rHeight = Height(r->rightChild);	// 右子树的高
		mHeight = Height(r->midChild);	// 右子树的高
		return ((lHeight > rHeight ? lHeight : rHeight)>mHeight?(lHeight > rHeight ? lHeight : rHeight):mHeight) + 1;
			// 非空三叉树高为左右子树的高的最大值再加1
	}
}

template <class ElemType>
int TriaryTree<ElemType>::Height() const
// 操作结果：返回三叉树的高
{
	return Height(root);
}

template <class ElemType>
TriaryTree<ElemType>::TriaryTree(const ElemType &e)
// 操作结果：建立以e为根的三叉树
{
	root = new TriTreeNode<ElemType>(e);
}

template <class ElemType>
int TriaryTree<ElemType>::NodeCount(const TriTreeNode<ElemType> *r) const
// 操作结果：返回以r为根的三叉树的结点个数
{
	if (r ==NULL)
       return 0;			// 空三叉树结点个数为0
	else
       return NodeCount(r->leftChild) + NodeCount(r->rightChild) +NodeCount(r->midChild)+ 1;
		// 非空三叉树结点个为左中右子树的结点个数之和再加1
}

template <class ElemType>
int TriaryTree<ElemType>::NodeCount() const
// 操作结果：返回三叉树的结点个数
{
	return NodeCount(root);
}

template <class ElemType>
TriTreeNode<ElemType> *TriaryTree<ElemType>::LeftChild(const TriTreeNode<ElemType> *p) const
// 操作结果：返回三叉树结点p的左孩子
{
	return p->leftChild;
}

template <class ElemType>
TriTreeNode<ElemType> *TriaryTree<ElemType>::RightChild(const TriTreeNode<ElemType> *p) const
// 操作结果：返回三叉树结点p的右孩子
{
	return p->rightChild;
}
template <class ElemType>
TriTreeNode<ElemType> *TriaryTree<ElemType>::MidChild(const TriTreeNode<ElemType> *p) const
// 操作结果：返回三叉树结点p的右孩子
{
	return p->midChild;
}


template <class ElemType>
TriTreeNode<ElemType> * TriaryTree<ElemType>::Parent(TriTreeNode<ElemType> *r, const TriTreeNode<ElemType> *p) const
// 操作结果：返回以r为根的三叉树, 结点p的双亲
{
	if (r == NULL)
       return NULL;		// 空三叉树
	else if (r->leftChild == p || r->rightChild == p||r->midChild==p)
       return r; // r为p的双亲
	else	{	// 在子树上求双亲
		TriTreeNode<ElemType> *tmp;
		tmp = Parent(r->leftChild, p);	// 在左子树上求p的双亲
		if (tmp != NULL)
           return tmp;			        // 双亲在左子树上

		tmp = Parent(r->rightChild, p);	// 在右子树上求p的双亲
		if (tmp != NULL)
           return tmp;			        // 双亲在右子树上
		tmp = Parent(r->midChild, p);	// 在中子树上求p的双亲
		if (tmp != NULL)
           return tmp;	
		else
           return NULL;				    // 表示p无双亲
	}
}
template <class ElemType>
TriTreeNode<ElemType> *TriaryTree<ElemType>::Parent(const TriTreeNode<ElemType> *p) const
// 操作结果：返回三叉树结点p的双亲
{
	return Parent(root, p);
}

template <class ElemType>
void TriaryTree<ElemType>::InsertLeftChild(TriTreeNode<ElemType> *p, const ElemType &e)
// 初始条件：p非空，
// 操作结果：插入元素值为e的结点为p的左孩子，如果p的左孩子非空，则p原有左子树成为e的左子树
{
	if (p == NULL)	// p空，返回
		return;
	else 	{	// 插入左孩子
		TriTreeNode<ElemType> *child =  new TriTreeNode<ElemType>(e);// 元素值为e结点
		if (p->leftChild != NULL)	// p的左孩子非空
			child->leftChild = p->leftChild;	// p原有左子树成为e的左子树
		p->leftChild = child;					// e成为p的左孩子
		return;
	}
}

template <class ElemType>
void TriaryTree<ElemType>::InsertRightChild(TriTreeNode<ElemType> *p, const ElemType &e)
// 初始条件：p非空
// 操作结果：插入元素值为e的结点为p的右孩子，如果p的右孩子非空，则p原有右子树成为e的右子树
{
	if (p == NULL)	// p为空，返回
		return;
	else	{	// 插入右孩子
		TriTreeNode<ElemType> *child =  new TriTreeNode<ElemType>(e);// 元素值为e结点
		if (p->rightChild != NULL)	// p的右孩子非空
			child->rightChild = p->rightChild;	// p原有右子树成为e的右子树
		p->rightChild = child;					// e成为p的右孩子
		return;
	}
}
template <class ElemType>
void TriaryTree<ElemType>::InsertMidChild(TriTreeNode<ElemType> *p, const ElemType &e)
// 初始条件：p非空，
// 操作结果：插入元素值为e的结点为p的左孩子，如果p的左孩子非空，则p原有左子树成为e的左子树
{
	if (p == NULL)	// p空，返回
		return;
	else 	{	// 插入左孩子
		TriTreeNode<ElemType> *child =  new TriTreeNode<ElemType>(e);// 元素值为e结点
		if (p->midChild != NULL)	// p的左孩子非空
			child->midChild = p->midChild;	// p原有左子树成为e的左子树
		p->midChild = child;					// e成为p的左孩子
		return;
	}
}
template <class ElemType>
void TriaryTree<ElemType>::DeleteLeftChild(TriTreeNode<ElemType> *p)
// 初始条件：p非空
// 操作结果：删除p左子树
{
	if (p == NULL)	// p为空
		return;
	else	// p非空
		Destroy(p->leftChild);	// 删除p左子树
}

template <class ElemType>
void TriaryTree<ElemType>::DeleteRightChild(TriTreeNode<ElemType> *p)
// 初始条件：p非空
// 操作结果：删除p右子树
{
	if (p == NULL)	// p为空
		return;
	else	// p非空
		Destroy(p->rightChild);	// 删除p右子树
}
template <class ElemType>
void TriaryTree<ElemType>::DeleteMidChild(TriTreeNode<ElemType> *p)
// 初始条件：p非空
// 操作结果：删除p中子树
{
	if (p == NULL)	// p为空
		return;
	else	// p非空
		Destroy(p->midChild);	// 删除p中子树
}

template <class ElemType>
void TriaryTree<ElemType>::Destroy(TriTreeNode<ElemType> *&r)
// 操作结果：删除以r的三叉树
{
	if(r != NULL)	{	// r非空,实施删除
		Destroy(r->leftChild);		// 删除左子树
		Destroy(r->rightChild);		// 删除右子树
		Destroy(r->midChild);		// 删除右子树
		delete r;					// 删除根结点
		r = NULL;
	}
}

template <class ElemType>
TriTreeNode<ElemType> *TriaryTree<ElemType>::CopyTree(TriTreeNode<ElemType> *t)
// 操作结果：将以t为根的三叉树复制成新的三叉树,返回新三叉树的根
{
	if (t == NULL)	// 复制空三叉树
		return NULL;					// 空三叉树根为空
	else	{	// 复制非空三叉树
		TriTreeNode<ElemType> *lChild = CopyTree(t->leftChild);	// 复制左子树
		TriTreeNode<ElemType> *rChild = CopyTree(t->rightChild);	// 复制右子树
		TriTreeNode<ElemType> *mChild = CopyTree(t->midChild);	// 复制右子树
		TriTreeNode<ElemType> *r = new TriTreeNode<ElemType>(t->data, lChild, rChild,mChild);
			// 复制根结点
		return r;
	}
}


template <class ElemType>
TriaryTree<ElemType>::TriaryTree(const TriaryTree<ElemType> &t)
// 操作结果：由已知三叉树构造新三叉树——复制构造函数
{
	root = CopyTree(t.root);	// 复制三叉树
}

template <class ElemType>
TriaryTree<ElemType>::TriaryTree(TriTreeNode<ElemType> *r)
// 操作结果：建立以r为根的三叉树
{
	root = r;	// 复制三叉树
}

template <class ElemType>
TriaryTree<ElemType> &TriaryTree<ElemType>::operator=(const TriaryTree<ElemType> &t)
// 操作结果：由已知三叉树t复制到当前三叉树--赋值运算符重载
{
	if (&t != this)	{
		Destroy(root);				// 释放原三叉树所占用空间
		root = CopyTree(t.root);	// 复制三叉树
	}
	return *this;
}

template <class ElemType>
void DisplayBTWithTreeShape(TriTreeNode<ElemType> *r, int level)
// 操作结果：按树状形式显示以r为根的三叉树，level为层次数，可设根结点的层次数为1
{
	if(r != NULL)	{	// 空树不显式，只显式非空树
		DisplayBTWithTreeShape<ElemType>(r->rightChild, level + 1);//显示右子树
		cout << endl;					//显示新行
		for(int i = 0; i < level - 1; i++)
			cout << "  ";				//确保在第level列显示结点
		cout << r->data;				//显示结点
		DisplayBTWithTreeShape<ElemType>(r->leftChild, level + 1);//显示左子树
	}
}

template <class ElemType>
void DisplayBTWithTreeShape(TriaryTree<ElemType> &bt)
// 操作结果：树状形式显示三叉树
{
	DisplayBTWithTreeShape<ElemType>(bt.GetRoot(), 1);
		// 树状显示以bt.GetRoot()为根的三叉树
	cout << endl;
}

template <class ElemType>
void CreateTriaryTree(TriTreeNode<ElemType> *&r, ElemType pre[], ElemType in[],
							int preLeft, int preRight, int inLeft, int inRight)
// 操作结果：已知三叉树的先序序列pre[preLeft..preRight]和中序序列in[inLeft..inRight]构造
//	以r为根的三叉树
{
	if (inLeft > inRight)	// 三叉树无结点,空三叉树
		r = NULL;			// 空三叉树根为空
	else	{	// 三叉树有结点,非空三叉树
		r = new TriTreeNode<ElemType>(pre[preLeft]);// 生成根结点
		int mid = inLeft;
		while (in[mid] != pre[preLeft]) 	// 查找pre[preLeft]在in[]中的位置,也就是中序序列中根的位置
			mid++;
		CreateTriaryTree(r->leftChild, pre, in, preLeft+1, preLeft + mid - inLeft, inLeft, mid - 1);
			// 生成左子树
		CreateTriaryTree(r->rightChild, pre, in, preLeft + mid - inLeft + 1, preRight, mid + 1,
			inRight);								// 生成右子树
	}
}

template <class ElemType>
TriaryTree<ElemType> &CreateTriaryTree(ElemType pre[], ElemType in[], int n)
// 操作结果：已知先序和中序序列构造三叉树
{
	TriTreeNode<ElemType> *r;						// 三叉树的根
	CreateTriaryTree<ElemType>(r, pre, in, 0, n - 1, 0, n - 1);
		// 由先序和中序序列构造以r为根的三叉树
	TriaryTree<ElemType> *bt = new TriaryTree<ElemType>(r);	// 生成三叉树
	return *bt;
}
template <class ElemType>
void CreateTriaryleftTreeon(TriTreeNode<ElemType> *&r,ElemType on[12][12],int i,int j)
//以数组a[10][10]构造三叉树-----------------------------------左
{
	 
	if (on[i][j].a==1)	// 三叉树无结点,空三叉树
		r = NULL;			// 空三叉树根为空
	else	{	// 三叉树有结点,非空三叉树
		r = new TriTreeNode<ElemType>(on[i][j]);// 生成根结点
		j=j-1;
       if(on[i][j].a==0&&i<11&&j<11&&i>0&&j>0)
		  {
			  CreateTriaryleftTreeon(r->leftChild,on,i,j);// 生成左子树
	   }
	   i=i+1;
	   j=j+1;
	   if(on[i][j].a==0&&i<11&&j<11&&i>0&&j>0)
	     {
			 CreateTriarymidTreeon(r->midChild,on,i,j);			 // 生成中子树
	   }
	}
}
template <class ElemType>
void CreateTriaryrightTreeon(TriTreeNode<ElemType> *&r,ElemType on[12][12],int i,int j)
//以数组a[10][10]构造三叉树----------------------------右
{
	 
	if (on[i][j].a==1)	// 三叉树无结点,空三叉树
		r = NULL;			// 空三叉树根为空
	else	{	// 三叉树有结点,非空三叉树
		r = new TriTreeNode<ElemType>(on[i][j]);// 生成根结点
	   j=j+1;
	   if(on[i][j].a==0&&i<11&&j<11&&i>0&&j>0)
	     {
			 CreateTriaryrightTreeon(r->rightChild,on,i,j);			 // 生成右子树
	   }
	   i=i+1;
	   j=j-1;
	   if(on[i][j].a==0&&i<11&&j<11&&i>0&&j>0)
	     {
			 CreateTriarymidTreeon(r->midChild,on,i,j);			 // 生成中子树
	   }
	}
}

template <class ElemType>
void CreateTriarymidTreeon(TriTreeNode<ElemType> *&r,ElemType on[12][12],int i,int j)
//以数组a[10][10]构造三叉树----------------------------中
{
	 
	if (on[i][j].a==1)	// 三叉树无结点,空三叉树
		r = NULL;			// 空三叉树根为空
	else	{	// 三叉树有结点,非空三叉树
		r = new TriTreeNode<ElemType>(on[i][j]);// 生成根结点
	   j=j+1;
	   if(on[i][j].a==0&&i<11&&j<11&&i>0&&j>0)
	     {
			 CreateTriaryrightTreeon(r->rightChild,on,i,j);			 // 生成右子树
	   }
	   i=i+1;
	   j=j-1;
	   if(on[i][j].a==0&&i<11&&j<11&&i>0&&j>0)
	     {
			 CreateTriarymidTreeon(r->midChild,on,i,j);			 // 生成中子树
	   }
	   j=j-1;
	   i=i-1;
	   if(on[i][j].a==0&&i<11&&j<11&&i>0&&j>0)
	     {
			 CreateTriaryleftTreeon(r->leftChild,on,i,j);			 // 生成左子树
	   }
	}
}	 

template <class ElemType>
TriaryTree<ElemType> &CreateTriaryTreeon(ElemType on[12][12],int i,int j)
// 操作结果：由数组a[10][10]构造三叉树
{
	TriTreeNode<ElemType> *r;						// 三叉树的根
	CreateTriarymidTreeon<ElemType>(r,on,i,j);
	TriaryTree<ElemType> *bt = new TriaryTree<ElemType>(r);	// 生成三叉树
	return *bt;
}
template <class ElemType>
void DisplayBTWithTreeonShape(TriTreeNode<ElemType> *r, int level)
// 操作结果：以树行结构显示迷宫
{
	if(r != NULL)
	{
		DisplayBTWithTreeonShape<ElemType>(r->leftChild, level + 1);//显示左子树
		cout << endl;					//显示新行
		for(int i = 0; i < level - 1; i++)
			cout << " *";				//确保在第level列显示结点
		cout <<"["<<r->data.b<<","<<r->data.c<<"]";				//显示结点
		DisplayBTWithTreeonShape<ElemType>(r->midChild, level + 1);//显视中子树
		DisplayBTWithTreeonShape<ElemType>(r->rightChild, level + 1);//显示右子树
	}
}

template <class ElemType>
void DisplayBTWithTreeonShape(TriaryTree<ElemType> &bt)
// 操作结果：树状形式显示迷宫
{
	DisplayBTWithTreeonShape<ElemType>(bt.GetRoot(), 1);
		// 树状显示以bt.GetRoot()为根的三叉树
	cout << endl;
}
int n=0;
template <class ElemType>
void DisplayBTWithTreeonnShapestack(TriaryTree<ElemType> &bt,TriTreeNode<ElemType> *r)
// 操作结果：以树行结构显示迷宫的所有路径
{
	
	if(r != NULL)
	{	n++;
		cout<<"输出迷宫的第"<<n<<"条路径是："<<endl;
		LinkStack <TriTreeNode<ElemType> *> q;
		TriTreeNode<ElemType> *p;
	
		while(r!=bt.GetRoot())
		{
			q.Push(r);
			//q.Push();
			r=bt.Parent(r);
		}
		q.Push(bt.GetRoot());
		while (!q.IsEmpty())
		{
			q.Pop(p);
			cout<<"["<<p->data.b<<","<<p->data.c<<"]----->";
		}
		cout<<"到达终点";
		cout<<endl;
	}
}
template <class ElemType>
void DisplayBTWithTreeonnShape(TriaryTree<ElemType> &bt,TriTreeNode<ElemType> *r)
// 操作结果：以树行结构显示迷宫的所有路径
{
	
	if(r != NULL)
	{
		//int n=0;
		if(r->data.b==10&&r->data.c==10)
		{
			DisplayBTWithTreeonnShapestack(bt,r);
		}
		DisplayBTWithTreeonnShape<ElemType>(bt,r->leftChild);//显示左子树
		DisplayBTWithTreeonnShape<ElemType>(bt,r->rightChild);//显示右子树
		DisplayBTWithTreeonnShape<ElemType>(bt,r->midChild);//显示中子树
	
	}
}
template <class ElemType>
void DisplayBTWithTreeonnShape(TriaryTree<ElemType> &bt)
// 操作结果：树状形式显示迷宫
{
	DisplayBTWithTreeonnShape<ElemType>(bt,bt.GetRoot());
		// 树状显示以bt.GetRoot()为根的三叉树迷宫的所有路径
	cout << endl;
}
#endif
