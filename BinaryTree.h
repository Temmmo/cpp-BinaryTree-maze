#ifndef __BINNARY_TREE_H__
#define __BIN24NARY_TREE_H__

#include "LinkQueue.h"				// ������
#include "BinTreeNode.h"	// �����������
#include "SeqStack.h"
#include "LinkStack.h"

// ��������
template <class ElemType>
class TriaryTree
{
protected:
//  �����������ݳ�Ա:
	TriTreeNode<ElemType> *root;

//	��������:
	TriTreeNode<ElemType> *CopyTree(TriTreeNode<ElemType> *t);
// ����������
	void Destroy(TriTreeNode<ElemType> * &r);	// ɾ����rΪ��������
	void PreOrder(TriTreeNode<ElemType>*r,void(*Visit)(const ElemType&)) const;
		// ���������rΪ����������
	void InOrder(TriTreeNode<ElemType>*r,void (*Visit)(const ElemType &)) const;
		// ���������rΪ����������
	void PostOrder(TriTreeNode<ElemType>*r,
    void (*Visit)(const ElemType &)) const;	// ���������rΪ����������
    int Height(const TriTreeNode<ElemType> *r) const;
// ����rΪ�����������ĸ�
	int NodeCount(const TriTreeNode<ElemType> *r) const;
// ����rΪ�����������Ľ�����
	TriTreeNode<ElemType> *Parent(TriTreeNode<ElemType> *r,
		const TriTreeNode<ElemType>*p) const;//����rΪ��������������p��˫��

public:
//  �������������������ر���ϵͳĬ�Ϸ�������:
	TriaryTree();						// �޲����Ĺ��캯��
	TriaryTree(const ElemType &e);		// ������eΪ����������
	virtual ~TriaryTree();				// ��������
	TriTreeNode<ElemType> *GetRoot() const;	// �����������ĸ�
	bool IsEmpty() const;				// �ж��������Ƿ�Ϊ��
	Status GetElem(TriTreeNode<ElemType> *p, ElemType &e) const;
		// ��e���ؽ��pԪ��ֵ
	Status SetElem(TriTreeNode<ElemType> *p, const ElemType &e);
		// �����p��ֵ��Ϊe
	void InOrder(void (*Visit)(const ElemType &)) const;// ���������������
	void PreOrder(void (*Visit)(const ElemType &)) const;// ���������������
	void PostOrder(void (*Visit)(const ElemType &)) const;// �������ĺ������
	void LevelOrder(void (*Visit)(const ElemType &)) const;	// �������Ĳ�α���
	int NodeCount() const;				// ���������Ľ�����
	TriTreeNode<ElemType> *LeftChild(const TriTreeNode<ElemType> *p) const;
		//  ����p������
	TriTreeNode<ElemType> *RightChild(const TriTreeNode<ElemType> *p) const;
		// ����p���Һ���
	TriTreeNode<ElemType> *MidChild(const TriTreeNode<ElemType> *p) const;
		// ����p���к���
	TriTreeNode<ElemType> *Parent(const TriTreeNode<ElemType> *p) const;
		// ����p��˫��
	void InsertLeftChild(TriTreeNode<ElemType> *p, const ElemType &e);
        // ����һ�����e��Ϊp������
	void InsertRightChild(TriTreeNode<ElemType> *p, const ElemType &e);
        // ����һ�����e��Ϊp���Һ���
	void InsertMidChild(TriTreeNode<ElemType> *p, const ElemType &e);
        // ����һ�����e��Ϊp���к���
	void DeleteLeftChild(TriTreeNode<ElemType> *p);	// ɾ��p��������
	void DeleteRightChild(TriTreeNode<ElemType> *p);// ɾ��p��������
	void DeleteMidChild(TriTreeNode<ElemType> *p);// ɾ��p��������
	int	Height() const;							    // ���������ĸ�
	TriaryTree(const TriaryTree<ElemType> &t);	// ���ƹ��캯��
	TriaryTree(TriTreeNode<ElemType> *r);			// ������rΪ����������
	TriaryTree<ElemType> &operator=(const TriaryTree<ElemType>& t);
		// ��ֵ���������
	TriaryTree<ElemType> &operator!=(const TriaryTree<ElemType>& t);
		// ��ֵ���������
};



template <class ElemType>
void DisplayBTWithTreeShape(TriTreeNode<ElemType> *r, int level);
	//	����״��ʽ��ʾ��rΪ������������levelΪ���������������Ĳ����Ϊ1
template <class ElemType>
void DisplayBTWithTreeShape(TriaryTree<ElemType> &bt);
	//	��״��ʽ��ʾ������
template <class ElemType>
void CreateTriaryTree(TriTreeNode<ElemType> *&r, ElemType pre[], ElemType in[],
	int preLeft, int preRight, int inLeft, int inRight);
	// ��֪����������������pre[preLeft..preRight]����������in[inLeft..inRight]������rΪ����
	// ������
template <class ElemType>
TriaryTree<ElemType> &CreateTriaryTree(ElemType pre[], ElemType in[], int n);
	// ��֪������������й���������
template <class ElemType>
void DisplayBTWithTreeonShape(TriTreeNode<ElemType> *r, int level);
	//	------�Թ���������չʾ
template <class ElemType>
void DisplayBTWithTreeonShape(TriaryTree<ElemType> &bt);
	//	-------�Թ���������չʾ
template <class ElemType>
void CreateTriaryleftTreeon(TriTreeNode<ElemType> *&r,ElemType on[10][10],int i,int j);
	//-------------�Թ�����������-----------��
template <class ElemType>
void CreateTriaryrightTreeon(TriTreeNode<ElemType> *&r,ElemType on[10][10],int i,int j);
	//-------------�Թ�����������----------��
template <class ElemType>
void CreateTriarymidTreeon(TriTreeNode<ElemType> *&r,ElemType on[10][10],int i,int j);
	//-------------�Թ�����������-----------��
template <class ElemType>
void CreateTriaryTreeon(TriTreeNode<ElemType> *&r,ElemType on[10][10],int i,int j);
	//-------------�Թ�����������
template <class ElemType>
TriaryTree<ElemType> &CreateTriaryTreeon(ElemType on[10][10],int i,int j);
	// -------------�Թ�����������
template <class ElemType>
void DisplayBTWithTreeonnShape(TriaryTree<ElemType> &bt,TriTreeNode<ElemType> *r);
	//	------�Թ���������չʾ--------������
template <class ElemType>
void DisplayBTWithTreeonnShapestack(TriaryTree<ElemType> &bt,TriTreeNode<ElemType> *r);
template <class ElemType>
	//------�Թ���������չʾ-------����ջչʾ·��
void DisplayBTWithTreeonnShape(TriaryTree<ElemType> &bt);
	//	-------�Թ���������չʾ



// ���������ʵ�ֲ���
template <class ElemType>
TriaryTree<ElemType>::TriaryTree()
// �������������һ����������
{
	root = NULL;
}

template <class ElemType>
TriaryTree<ElemType>::~TriaryTree()
// ���������ɾ��������--���캯��
{
	Destroy(root);
}

template <class ElemType>
TriTreeNode<ElemType> *TriaryTree<ElemType>::GetRoot() const
// ��������������������ĸ�
{
	return root;
}

template <class ElemType>
bool TriaryTree<ElemType>::IsEmpty() const
// ����������ж��������Ƿ�Ϊ��
{
	return root == NULL;
}

template <class ElemType>
Status TriaryTree<ElemType>::GetElem(TriTreeNode<ElemType> *p, ElemType &e) const
// �����������e���ؽ��pԪ��ֵ,��������ڽ��p,��������NOT_PRESENT,���򷵻�ENTRY_FOUND
{
	if (p == NULL)		// �����ڽ��p
		return NOT_PRESENT;			// ����NOT_PRESENT
	else	{	// ���ڽ��p
		e = p->data;				// ��e����Ԫ��ֵ
		return ENTRY_FOUND;			// ����ENTRY_FOUND
	}
}

template <class ElemType>
Status TriaryTree<ElemType>::SetElem(TriTreeNode<ElemType> *p, const ElemType &e)
// �����������������ڽ��p,�򷵻�FAIL,���򷵻�SUCCESS,�������p��ֵ����Ϊe
{
	if (p == NULL)		// �����ڽ��p
		return FAIL;				// ����FAIL
	else	{	// ���ڽ��p
		p->data = e;				// �����p��ֵ����Ϊe
		return SUCCESS;				// ����SUCCESS
	}
}

template <class ElemType>
void TriaryTree<ElemType>::PreOrder(TriTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// ������������������rΪ����������
{
	if (r != NULL)	{
		(*Visit)(r->data);				// ���ȷ��ʸ����r
		PreOrder(r->leftChild, Visit);	// �ٱ���r��������
		PreOrder(r->midChild, Visit);	// �ٱ���r��������
		PreOrder(r->rightChild, Visit);	// ������r��������
	}
}

template <class ElemType>
void TriaryTree<ElemType>::PreOrder(void (*Visit)(const ElemType &)) const
// ����������������������
{
	PreOrder(root, Visit);
}

template <class ElemType>
void TriaryTree<ElemType>::InOrder(TriTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// ������������������rΪ����������
{
	if (r != NULL) 	{
		InOrder(r->leftChild, Visit);	// ���ȱ���r��������
		PreOrder(r->midChild, Visit);	// �ٱ���r��������
		(*Visit)(r->data);				// �ٷ��ʸ����r
		InOrder(r->rightChild, Visit);	// ������r��������
	}
}

template <class ElemType>
void TriaryTree<ElemType>::InOrder(void (*Visit)(const ElemType &)) const
// ����������������������
{
	InOrder(root, Visit);
}

template <class ElemType>
void TriaryTree<ElemType>::PostOrder(TriTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
// ������������������rΪ����������
{
	if (r != NULL) 	{
		PostOrder(r->leftChild, Visit);	// ���ȱ���r��������
		PreOrder(r->midChild, Visit);	// �ٱ���r��������
		PostOrder(r->rightChild, Visit);// �ٱ���r��������
		(*Visit)(r->data);				// �����ʸ����r
	}
}

template <class ElemType>
void TriaryTree<ElemType>::PostOrder(void (*Visit)(const ElemType &)) const
// ����������������������
{
	PostOrder(root, Visit);
}

template <class ElemType>
void TriaryTree<ElemType>::LevelOrder(void (*Visit)(const ElemType &)) const
// �����������α���������
{
	LinkQueue<TriTreeNode<ElemType> *> q;	// �������q
	TriTreeNode<ElemType> *p;

	if (root != NULL) q.EnQueue(root);		// ������ǿ�,�����
	while (!q.IsEmpty())	{	            // q�ǿ�,˵�����н��δ����
		q.DelQueue(p);                      // ��ͷԪ�س��ӣ�������֮
		(*Visit)(p->data);
		if (p->leftChild != NULL)			// ��ͷԪ�����ӷǿ�
			q.EnQueue(p->leftChild);		// �������
		if (p->midChild != NULL)			// ��ͷԪ���Һ��ӷǿ�
			q.EnQueue(p->midChild);		// �Һ������
		if (p->rightChild != NULL)			// ��ͷԪ���Һ��ӷǿ�
			q.EnQueue(p->rightChild);		// �Һ������
            // �Һ������
	}
}

template <class ElemType>
int TriaryTree<ElemType>::Height(const TriTreeNode<ElemType> *r) const
// ���������������rΪ�����������ĸ�
{
	if(r == NULL)	// ����������Ϊ0
		return 0;
	else	{	// �ǿ���������Ϊ���������ĸߵ����ֵ�ټ�1
		int lHeight, rHeight;
		lHeight = Height(r->leftChild);		// �������ĸ�
		rHeight = Height(r->rightChild);	// �������ĸ�
		mHeight = Height(r->midChild);	// �������ĸ�
		return ((lHeight > rHeight ? lHeight : rHeight)>mHeight?(lHeight > rHeight ? lHeight : rHeight):mHeight) + 1;
			// �ǿ���������Ϊ���������ĸߵ����ֵ�ټ�1
	}
}

template <class ElemType>
int TriaryTree<ElemType>::Height() const
// ��������������������ĸ�
{
	return Height(root);
}

template <class ElemType>
TriaryTree<ElemType>::TriaryTree(const ElemType &e)
// ���������������eΪ����������
{
	root = new TriTreeNode<ElemType>(e);
}

template <class ElemType>
int TriaryTree<ElemType>::NodeCount(const TriTreeNode<ElemType> *r) const
// ���������������rΪ�����������Ľ�����
{
	if (r ==NULL)
       return 0;			// ��������������Ϊ0
	else
       return NodeCount(r->leftChild) + NodeCount(r->rightChild) +NodeCount(r->midChild)+ 1;
		// �ǿ�����������Ϊ�����������Ľ�����֮���ټ�1
}

template <class ElemType>
int TriaryTree<ElemType>::NodeCount() const
// ��������������������Ľ�����
{
	return NodeCount(root);
}

template <class ElemType>
TriTreeNode<ElemType> *TriaryTree<ElemType>::LeftChild(const TriTreeNode<ElemType> *p) const
// ����������������������p������
{
	return p->leftChild;
}

template <class ElemType>
TriTreeNode<ElemType> *TriaryTree<ElemType>::RightChild(const TriTreeNode<ElemType> *p) const
// ����������������������p���Һ���
{
	return p->rightChild;
}
template <class ElemType>
TriTreeNode<ElemType> *TriaryTree<ElemType>::MidChild(const TriTreeNode<ElemType> *p) const
// ����������������������p���Һ���
{
	return p->midChild;
}


template <class ElemType>
TriTreeNode<ElemType> * TriaryTree<ElemType>::Parent(TriTreeNode<ElemType> *r, const TriTreeNode<ElemType> *p) const
// ���������������rΪ����������, ���p��˫��
{
	if (r == NULL)
       return NULL;		// ��������
	else if (r->leftChild == p || r->rightChild == p||r->midChild==p)
       return r; // rΪp��˫��
	else	{	// ����������˫��
		TriTreeNode<ElemType> *tmp;
		tmp = Parent(r->leftChild, p);	// ������������p��˫��
		if (tmp != NULL)
           return tmp;			        // ˫������������

		tmp = Parent(r->rightChild, p);	// ������������p��˫��
		if (tmp != NULL)
           return tmp;			        // ˫������������
		tmp = Parent(r->midChild, p);	// ������������p��˫��
		if (tmp != NULL)
           return tmp;	
		else
           return NULL;				    // ��ʾp��˫��
	}
}
template <class ElemType>
TriTreeNode<ElemType> *TriaryTree<ElemType>::Parent(const TriTreeNode<ElemType> *p) const
// ����������������������p��˫��
{
	return Parent(root, p);
}

template <class ElemType>
void TriaryTree<ElemType>::InsertLeftChild(TriTreeNode<ElemType> *p, const ElemType &e)
// ��ʼ������p�ǿգ�
// �������������Ԫ��ֵΪe�Ľ��Ϊp�����ӣ����p�����ӷǿգ���pԭ����������Ϊe��������
{
	if (p == NULL)	// p�գ�����
		return;
	else 	{	// ��������
		TriTreeNode<ElemType> *child =  new TriTreeNode<ElemType>(e);// Ԫ��ֵΪe���
		if (p->leftChild != NULL)	// p�����ӷǿ�
			child->leftChild = p->leftChild;	// pԭ����������Ϊe��������
		p->leftChild = child;					// e��Ϊp������
		return;
	}
}

template <class ElemType>
void TriaryTree<ElemType>::InsertRightChild(TriTreeNode<ElemType> *p, const ElemType &e)
// ��ʼ������p�ǿ�
// �������������Ԫ��ֵΪe�Ľ��Ϊp���Һ��ӣ����p���Һ��ӷǿգ���pԭ����������Ϊe��������
{
	if (p == NULL)	// pΪ�գ�����
		return;
	else	{	// �����Һ���
		TriTreeNode<ElemType> *child =  new TriTreeNode<ElemType>(e);// Ԫ��ֵΪe���
		if (p->rightChild != NULL)	// p���Һ��ӷǿ�
			child->rightChild = p->rightChild;	// pԭ����������Ϊe��������
		p->rightChild = child;					// e��Ϊp���Һ���
		return;
	}
}
template <class ElemType>
void TriaryTree<ElemType>::InsertMidChild(TriTreeNode<ElemType> *p, const ElemType &e)
// ��ʼ������p�ǿգ�
// �������������Ԫ��ֵΪe�Ľ��Ϊp�����ӣ����p�����ӷǿգ���pԭ����������Ϊe��������
{
	if (p == NULL)	// p�գ�����
		return;
	else 	{	// ��������
		TriTreeNode<ElemType> *child =  new TriTreeNode<ElemType>(e);// Ԫ��ֵΪe���
		if (p->midChild != NULL)	// p�����ӷǿ�
			child->midChild = p->midChild;	// pԭ����������Ϊe��������
		p->midChild = child;					// e��Ϊp������
		return;
	}
}
template <class ElemType>
void TriaryTree<ElemType>::DeleteLeftChild(TriTreeNode<ElemType> *p)
// ��ʼ������p�ǿ�
// ���������ɾ��p������
{
	if (p == NULL)	// pΪ��
		return;
	else	// p�ǿ�
		Destroy(p->leftChild);	// ɾ��p������
}

template <class ElemType>
void TriaryTree<ElemType>::DeleteRightChild(TriTreeNode<ElemType> *p)
// ��ʼ������p�ǿ�
// ���������ɾ��p������
{
	if (p == NULL)	// pΪ��
		return;
	else	// p�ǿ�
		Destroy(p->rightChild);	// ɾ��p������
}
template <class ElemType>
void TriaryTree<ElemType>::DeleteMidChild(TriTreeNode<ElemType> *p)
// ��ʼ������p�ǿ�
// ���������ɾ��p������
{
	if (p == NULL)	// pΪ��
		return;
	else	// p�ǿ�
		Destroy(p->midChild);	// ɾ��p������
}

template <class ElemType>
void TriaryTree<ElemType>::Destroy(TriTreeNode<ElemType> *&r)
// ���������ɾ����r��������
{
	if(r != NULL)	{	// r�ǿ�,ʵʩɾ��
		Destroy(r->leftChild);		// ɾ��������
		Destroy(r->rightChild);		// ɾ��������
		Destroy(r->midChild);		// ɾ��������
		delete r;					// ɾ�������
		r = NULL;
	}
}

template <class ElemType>
TriTreeNode<ElemType> *TriaryTree<ElemType>::CopyTree(TriTreeNode<ElemType> *t)
// �������������tΪ�������������Ƴ��µ�������,�������������ĸ�
{
	if (t == NULL)	// ���ƿ�������
		return NULL;					// ����������Ϊ��
	else	{	// ���Ʒǿ�������
		TriTreeNode<ElemType> *lChild = CopyTree(t->leftChild);	// ����������
		TriTreeNode<ElemType> *rChild = CopyTree(t->rightChild);	// ����������
		TriTreeNode<ElemType> *mChild = CopyTree(t->midChild);	// ����������
		TriTreeNode<ElemType> *r = new TriTreeNode<ElemType>(t->data, lChild, rChild,mChild);
			// ���Ƹ����
		return r;
	}
}


template <class ElemType>
TriaryTree<ElemType>::TriaryTree(const TriaryTree<ElemType> &t)
// �������������֪�������������������������ƹ��캯��
{
	root = CopyTree(t.root);	// ����������
}

template <class ElemType>
TriaryTree<ElemType>::TriaryTree(TriTreeNode<ElemType> *r)
// ���������������rΪ����������
{
	root = r;	// ����������
}

template <class ElemType>
TriaryTree<ElemType> &TriaryTree<ElemType>::operator=(const TriaryTree<ElemType> &t)
// �������������֪������t���Ƶ���ǰ������--��ֵ���������
{
	if (&t != this)	{
		Destroy(root);				// �ͷ�ԭ��������ռ�ÿռ�
		root = CopyTree(t.root);	// ����������
	}
	return *this;
}

template <class ElemType>
void DisplayBTWithTreeShape(TriTreeNode<ElemType> *r, int level)
// �������������״��ʽ��ʾ��rΪ������������levelΪ���������������Ĳ����Ϊ1
{
	if(r != NULL)	{	// ��������ʽ��ֻ��ʽ�ǿ���
		DisplayBTWithTreeShape<ElemType>(r->rightChild, level + 1);//��ʾ������
		cout << endl;					//��ʾ����
		for(int i = 0; i < level - 1; i++)
			cout << "  ";				//ȷ���ڵ�level����ʾ���
		cout << r->data;				//��ʾ���
		DisplayBTWithTreeShape<ElemType>(r->leftChild, level + 1);//��ʾ������
	}
}

template <class ElemType>
void DisplayBTWithTreeShape(TriaryTree<ElemType> &bt)
// �����������״��ʽ��ʾ������
{
	DisplayBTWithTreeShape<ElemType>(bt.GetRoot(), 1);
		// ��״��ʾ��bt.GetRoot()Ϊ����������
	cout << endl;
}

template <class ElemType>
void CreateTriaryTree(TriTreeNode<ElemType> *&r, ElemType pre[], ElemType in[],
							int preLeft, int preRight, int inLeft, int inRight)
// �����������֪����������������pre[preLeft..preRight]����������in[inLeft..inRight]����
//	��rΪ����������
{
	if (inLeft > inRight)	// �������޽��,��������
		r = NULL;			// ����������Ϊ��
	else	{	// �������н��,�ǿ�������
		r = new TriTreeNode<ElemType>(pre[preLeft]);// ���ɸ����
		int mid = inLeft;
		while (in[mid] != pre[preLeft]) 	// ����pre[preLeft]��in[]�е�λ��,Ҳ�������������и���λ��
			mid++;
		CreateTriaryTree(r->leftChild, pre, in, preLeft+1, preLeft + mid - inLeft, inLeft, mid - 1);
			// ����������
		CreateTriaryTree(r->rightChild, pre, in, preLeft + mid - inLeft + 1, preRight, mid + 1,
			inRight);								// ����������
	}
}

template <class ElemType>
TriaryTree<ElemType> &CreateTriaryTree(ElemType pre[], ElemType in[], int n)
// �����������֪������������й���������
{
	TriTreeNode<ElemType> *r;						// �������ĸ�
	CreateTriaryTree<ElemType>(r, pre, in, 0, n - 1, 0, n - 1);
		// ��������������й�����rΪ����������
	TriaryTree<ElemType> *bt = new TriaryTree<ElemType>(r);	// ����������
	return *bt;
}
template <class ElemType>
void CreateTriaryleftTreeon(TriTreeNode<ElemType> *&r,ElemType on[12][12],int i,int j)
//������a[10][10]����������-----------------------------------��
{
	 
	if (on[i][j].a==1)	// �������޽��,��������
		r = NULL;			// ����������Ϊ��
	else	{	// �������н��,�ǿ�������
		r = new TriTreeNode<ElemType>(on[i][j]);// ���ɸ����
		j=j-1;
       if(on[i][j].a==0&&i<11&&j<11&&i>0&&j>0)
		  {
			  CreateTriaryleftTreeon(r->leftChild,on,i,j);// ����������
	   }
	   i=i+1;
	   j=j+1;
	   if(on[i][j].a==0&&i<11&&j<11&&i>0&&j>0)
	     {
			 CreateTriarymidTreeon(r->midChild,on,i,j);			 // ����������
	   }
	}
}
template <class ElemType>
void CreateTriaryrightTreeon(TriTreeNode<ElemType> *&r,ElemType on[12][12],int i,int j)
//������a[10][10]����������----------------------------��
{
	 
	if (on[i][j].a==1)	// �������޽��,��������
		r = NULL;			// ����������Ϊ��
	else	{	// �������н��,�ǿ�������
		r = new TriTreeNode<ElemType>(on[i][j]);// ���ɸ����
	   j=j+1;
	   if(on[i][j].a==0&&i<11&&j<11&&i>0&&j>0)
	     {
			 CreateTriaryrightTreeon(r->rightChild,on,i,j);			 // ����������
	   }
	   i=i+1;
	   j=j-1;
	   if(on[i][j].a==0&&i<11&&j<11&&i>0&&j>0)
	     {
			 CreateTriarymidTreeon(r->midChild,on,i,j);			 // ����������
	   }
	}
}

template <class ElemType>
void CreateTriarymidTreeon(TriTreeNode<ElemType> *&r,ElemType on[12][12],int i,int j)
//������a[10][10]����������----------------------------��
{
	 
	if (on[i][j].a==1)	// �������޽��,��������
		r = NULL;			// ����������Ϊ��
	else	{	// �������н��,�ǿ�������
		r = new TriTreeNode<ElemType>(on[i][j]);// ���ɸ����
	   j=j+1;
	   if(on[i][j].a==0&&i<11&&j<11&&i>0&&j>0)
	     {
			 CreateTriaryrightTreeon(r->rightChild,on,i,j);			 // ����������
	   }
	   i=i+1;
	   j=j-1;
	   if(on[i][j].a==0&&i<11&&j<11&&i>0&&j>0)
	     {
			 CreateTriarymidTreeon(r->midChild,on,i,j);			 // ����������
	   }
	   j=j-1;
	   i=i-1;
	   if(on[i][j].a==0&&i<11&&j<11&&i>0&&j>0)
	     {
			 CreateTriaryleftTreeon(r->leftChild,on,i,j);			 // ����������
	   }
	}
}	 

template <class ElemType>
TriaryTree<ElemType> &CreateTriaryTreeon(ElemType on[12][12],int i,int j)
// ���������������a[10][10]����������
{
	TriTreeNode<ElemType> *r;						// �������ĸ�
	CreateTriarymidTreeon<ElemType>(r,on,i,j);
	TriaryTree<ElemType> *bt = new TriaryTree<ElemType>(r);	// ����������
	return *bt;
}
template <class ElemType>
void DisplayBTWithTreeonShape(TriTreeNode<ElemType> *r, int level)
// ��������������нṹ��ʾ�Թ�
{
	if(r != NULL)
	{
		DisplayBTWithTreeonShape<ElemType>(r->leftChild, level + 1);//��ʾ������
		cout << endl;					//��ʾ����
		for(int i = 0; i < level - 1; i++)
			cout << " *";				//ȷ���ڵ�level����ʾ���
		cout <<"["<<r->data.b<<","<<r->data.c<<"]";				//��ʾ���
		DisplayBTWithTreeonShape<ElemType>(r->midChild, level + 1);//����������
		DisplayBTWithTreeonShape<ElemType>(r->rightChild, level + 1);//��ʾ������
	}
}

template <class ElemType>
void DisplayBTWithTreeonShape(TriaryTree<ElemType> &bt)
// �����������״��ʽ��ʾ�Թ�
{
	DisplayBTWithTreeonShape<ElemType>(bt.GetRoot(), 1);
		// ��״��ʾ��bt.GetRoot()Ϊ����������
	cout << endl;
}
int n=0;
template <class ElemType>
void DisplayBTWithTreeonnShapestack(TriaryTree<ElemType> &bt,TriTreeNode<ElemType> *r)
// ��������������нṹ��ʾ�Թ�������·��
{
	
	if(r != NULL)
	{	n++;
		cout<<"����Թ��ĵ�"<<n<<"��·���ǣ�"<<endl;
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
		cout<<"�����յ�";
		cout<<endl;
	}
}
template <class ElemType>
void DisplayBTWithTreeonnShape(TriaryTree<ElemType> &bt,TriTreeNode<ElemType> *r)
// ��������������нṹ��ʾ�Թ�������·��
{
	
	if(r != NULL)
	{
		//int n=0;
		if(r->data.b==10&&r->data.c==10)
		{
			DisplayBTWithTreeonnShapestack(bt,r);
		}
		DisplayBTWithTreeonnShape<ElemType>(bt,r->leftChild);//��ʾ������
		DisplayBTWithTreeonnShape<ElemType>(bt,r->rightChild);//��ʾ������
		DisplayBTWithTreeonnShape<ElemType>(bt,r->midChild);//��ʾ������
	
	}
}
template <class ElemType>
void DisplayBTWithTreeonnShape(TriaryTree<ElemType> &bt)
// �����������״��ʽ��ʾ�Թ�
{
	DisplayBTWithTreeonnShape<ElemType>(bt,bt.GetRoot());
		// ��״��ʾ��bt.GetRoot()Ϊ�����������Թ�������·��
	cout << endl;
}
#endif
