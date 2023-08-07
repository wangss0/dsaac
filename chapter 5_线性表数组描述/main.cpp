


#include "arrayList.h"


int main()
{
    try
    {
        arrayList<int> a11(10);
    }
    catch (const illegalParameter& e)
    {
        cerr << "Caught exception: " << e.what() << endl;
    }
    
    arrayList<int> al;
    
    for (int i = 0; i < 15; i++)
    {
        al.insert(0, i);
        cout << "al.size() = " << al.size() << endl;
        cout << "al = " << al << endl;
    }
    arrayList<int> al2 = al;
    arrayList<int> al3(al);
    try 
    {
        cout << al.get(17) << endl;
       
    } catch (const illegalIndex& e) 
    {
        cerr << "Caught exception: " << e.what() << endl;
        // 处理异常的其他逻辑
    }

    al.earse(5);

    cout << "al = " << al << endl;

    cout << "al.indexOf() = " << al.indexOf(9) << endl;
    cout << "al.size() = " << al.size() << endl;
    cout << "al.empty() = " << al.empty() << endl;

    cout << "al.size() = " << al.size() << endl;
    return 0;
}