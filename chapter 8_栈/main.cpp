


#include "arrayStack.h"
#include "linkedStack.h"
#include "stack.h"

using std::string; 
using std::cout;
using std::endl;

class person
{
public:
	person() : age(0), name("") {}
	person(unsigned int theAge,string theName) : age(theAge), name(theName) {}
	void personPrint()
	{
		cout << "age = " << age << ", name = " << name << endl;
	}
private:
	unsigned int age;
	string name;
};

void testStack(stack<person>& s)
{
	person p1(11, "p1");
	person p2(22, "p2");
	person p3(33, "p3");
	person p4(44, "p4");
	person p5(55, "p5");
	person p6(66, "p6");
	person p7(77, "p7");

	// Ñ¹Õ»
	s.push(p1);
	s.push(p2);
	s.push(p3);
	s.push(p4);
	s.push(p5);
	s.push(p6);
	s.push(p7);



	s.top().personPrint();
	// µ¯Õ»²¢Êä³ö
	while (!s.empty())
	{
		person topPerson = s.top();
		topPerson.personPrint();
		s.pop();
	}
}
int main()
{
	arrayStack<person> as;
	testStack(as);

	linkedStack<person> ls;
	testStack(ls);
	system("pause");
	return 0;
}