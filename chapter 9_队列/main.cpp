




#include "arrayQueue.h"
#include "linkedQueue.h"
#include "queue.h"

using std::string;
using std::cout;
using std::endl;

class person
{
public:
	person() : age(0), name("") {}
	person(unsigned int theAge, string theName) : age(theAge), name(theName) {}
	void personPrint()
	{
		cout << "age = " << age << ", name = " << name << endl;
	}
private:
	unsigned int age;
	string name;
};

void testQueue(queue<person>& q)
{
	try
	{
		q.front();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception occurred: " << e.what() << std::endl;
	}
	person p1(11, "p1");
	person p2(22, "p2");
	person p3(33, "p3");
	person p4(44, "p4");
	person p5(55, "p5");
	person p6(66, "p6");
	person p7(77, "p7");

	// 入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	q.push(p5);
	q.push(p6);
	q.push(p7);


	
	q.front().personPrint();
	// 弹栈并输出
	while (!q.empty())
	{
		person frontPerson = q.front();
		frontPerson.personPrint();
		q.pop();
	}
}
int main()
{
	cout << "arrayQueue test" << endl;
	arrayQueue<person> ap;
	testQueue(ap);

	cout << "linkedQueue test" << endl;
	linkedQueue<person> lp;
	testQueue(lp);
	system("pause");
	return 0;
}