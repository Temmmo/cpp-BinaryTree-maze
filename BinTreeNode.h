#ifndef __BIN_TREE_NODE_H__
#define __BIN_TREE_NODE_H__

// ������������
template <class ElemType>
struct TriTreeNode
{
// ���ݳ�Ա:
	ElemType data;		// ������
	TriTreeNode<ElemType>  *leftChild;	// ����ָ����
	TriTreeNode<ElemType>  *midChild;	// �к���ָ����
	TriTreeNode<ElemType>  *rightChild;	// �Һ���ָ����

//	���캯��:
	TriTreeNode();		// �޲����Ĺ��캯�� 
	TriTreeNode(const ElemType &d,// ��֪����Ԫ��ֵ,ָ�����Һ��ӵ�ָ�빹��һ�����
		TriTreeNode<ElemType> *lChild = NULL, TriTreeNode<ElemType> *mChild = NULL, 
		TriTreeNode<ElemType> *rChild = NULL);
};

// ������������ʵ�ֲ���
template <class ElemType>
TriTreeNode<ElemType>::TriTreeNode()
// �������������һ��Ҷ���
{
	leftChild = rightChild = midChild = NULL;	// Ҷ��������Һ���Ϊ��
}

template <class ElemType>
TriTreeNode<ElemType>::TriTreeNode(const ElemType &d, 
	TriTreeNode<ElemType> *lChild, TriTreeNode<ElemType> *mChild,TriTreeNode<ElemType> *rChild)
// �������������һ��������Ϊd,����ΪlChild,�к���ΪcChild;�Һ���ΪrChild�Ľ��
{	
	data = d;		// ����Ԫ��ֵ
	leftChild = lChild;			// ����
	midChild = mChild;	        //�к���
	rightChild = rChild;		// �Һ���
}

#endif

