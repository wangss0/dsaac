


#ifndef __LINEAR_LIST__H__
#define __LINEAR_LIST__H__
#include <iostream>
using namespace std;

template<class T>
class linearList
{
public:
	virtual ~linearList() {};

	// ���� true, ��ǰ�ҵ����Ա�Ϊ��
	virtual bool empty() const = 0;
	// �������Ա��Ԫ�ظ���
	virtual int size() const = 0;
	// ��������Ϊ theIndex ��Ԫ��
	virtual T& get(int theIndex) const = 0;
	// ����Ԫ�� theElment ��һ�γ��ֵ�����
	virtual int indexOf(const T& theElement) const = 0;
	// ɾ��Ԫ��Ϊ theIndex ��Ԫ��
	virtual void earse(int theIndex) = 0;
	// �� theElement �������Ա�����Ϊ theIndex ��λ��
	virtual void insert(int theIndex, const T& theElement) = 0;
};



// ע�� : 
// virtual �ؼ������������麯�����麯������������д����ĺ���������ͨ�������ָ������õ���ʱ���Զ�̬�󶨵���ȷ�ĺ�����

// = 0 ���ʾ���麯�������麯�����ڻ�����������û���ṩ����ʵ�ֵ��麯����
// �������麯�����౻��Ϊ�����࣬��ֻ�ܱ�����������Ļ��࣬����ֱ��ʵ���������������ʵ�ֳ������еĴ��麯�����ܳ�Ϊ�����ࡣ




#endif // !__ARRAY_LIST__H__
