//#include <iostream>
//using namespace std;
//
//class SmartPtr {
//	int* ptr; // Actual pointer
//public:
//	// Constructor: Refer https:// www.geeksforgeeks.org/g-fact-93/
//	// for use of explicit keyword
//	explicit SmartPtr(int* p = NULL)
//	{
//		ptr = p;
//	}
//
//	// Destructor
//	~SmartPtr()
//	{
//		delete (ptr);
//	}
//
//	// Overloading dereferencing operator
//	int& operator*() { return *ptr; }
//};
//
//int main()
//{
//	SmartPtr ptr(new int());
//	*ptr = 20;
//	cout << *ptr;
//
//	// We don't need to call delete ptr: when the object
//	// ptr goes out of scope, the destructor for it is automatically
//	// called and destructor does delete ptr.
//
//	return 0;
//}


//This only works for int.So, we’ll have to create Smart Pointer for every object ? No, there’s a solution, Template.In the code below as you can see T can be of any type.Read more about Template here.


//#include <iostream>
//using namespace std;
//
//// A generic smart pointer class
//template <class T>
//class SmartPtr {
//	T* ptr; // Actual pointer
//public:
//	// Constructor
//	explicit SmartPtr(T* p = NULL)
//	{
//		ptr = p;
//	}
//
//	// Destructor
//	~SmartPtr()
//	{
//		delete (ptr);
//	}
//
//	// Overloading dereferencing operator
//	T& operator*()
//	{
//		return *ptr;
//	}
//
//	// Overloading arrow operator so that
//	// members of T can be accessed
//	// like a pointer (useful if T represents
//	// a class or struct or union type)
//	T* operator->()
//	{
//		return ptr;
//	}
//};
//
//int main()
//{
//	SmartPtr<int> ptr(new int());
//	*ptr = 20;
//	cout << *ptr;
//	return 0;
//}

//1. unique_ptr

//unique_ptr stores one pointer only.We can assign a different object by removing the current object from the pointer.Notice the code below.First, the unique_pointer is pointing to P1.But, then we remove P1and assign P2 so the pointer now points to P2.


//#include <iostream>
//using namespace std;
//#include <memory>
//
//class Rectangle
//{
//	int length;
//	int breadth;
//
//public:
//	Rectangle(int l, int b)
//	{
//		length = l;
//		breadth = b;
//	}
//
//	int area()
//	{
//		return length * breadth;
//	}
//};
//
//int main() {
//
//	unique_ptr<Rectangle> P1(new Rectangle(10, 5));
//	cout << P1->area() << endl; // This'll print 50
//
//	// unique_ptr<Rectangle> P2(P1);
//	unique_ptr<Rectangle> P2;
//	P2 = move(P1);
//
//	// This'll print 50
//	cout << P2->area() << endl;
//
//	// cout<<P1->area()<<endl;
//	return 0;
//}



//2. shared_ptr

//By using shared_ptr more than one pointer can point to this one object at a timeand it’ll maintain a Reference Counter using use_count() method.

#include <iostream>
using namespace std;
#include <memory>

class Rectangle {
	int length;
	int breadth;

public:
	Rectangle(int l, int b)
	{
		length = l;
		breadth = b;
	}

	int area()
	{
		return length * breadth;
	}
};

int main()
{

	shared_ptr<Rectangle> P1(new Rectangle(10, 5));
	// This'll print 50
	cout << P1->area() << endl;

	shared_ptr<Rectangle> P2;
	P2 = P1;

	// This'll print 50
	cout << P2->area() << endl;

	// This'll now not give an error,
	cout << P1->area() << endl;

	// This'll also print 50 now
	// This'll print 2 as Reference Counter is 2
	cout << P1.use_count() << endl;
	return 0;
}


//3. weak_ptr 

//It’s much more similar to shared_ptr except it’ll not maintain a Reference Counter.In this case, a pointer will not have a stronghold on the object.The reason is if suppose pointers are holding the objectand requesting for other objects then they may form a Deadlock.

//weak_ptr

//C++ libraries provide implementations of smart pointers in the form of auto_ptr, unique_ptr, shared_ptrand weak_ptr