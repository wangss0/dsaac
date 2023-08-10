


#include "arrayStack.h"

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

void testArrayStack()
{
	arrayStack<person> as;
	person p1(12, "wang");
	person p2(13, "li");
	person p3(77, "zhang");

	// Ñ¹Õ»
	as.push(p1);
	as.push(p2);
	as.push(p3);

	as.top().personPrint();
	// µ¯Õ»²¢Êä³ö
	while (!as.empty())
	{
		person topPerson = as.top();
		topPerson.personPrint();
		as.pop();
	}
}

int main()
{
	testArrayStack();
	system("pause");
	return 0;
}