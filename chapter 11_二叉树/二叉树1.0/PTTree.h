


#ifndef __PTREE__H__
#define __PTREE__H__

template <class T>
struct pTNode
{
	T element;
	int parent;	// ˫��λ����

	pTNode(const T& elem, int p = -1)
		: element(elem), parent(p) {}
};

template <class T>
class pTree
{
private:
	pTNode<T>* nodes;	// �ڵ�����, ��Žڵ�, �����±�
	int rootIndex;		// ���ڵ�λ��
	int size;			// �ڵ����
};

#endif // ! __PTREE__H__
