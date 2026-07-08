#include <iostream>

using namespace std;


class A
{
	private:
		int a;
	public:
		friend class B;
		A(int a=10)
		{
			this->a=a;
		}
		int getA()
		{
			return a;
		}
		void setA(int a)
		{
			this->a=a;
		}
		void f()
		{
			cout<<"A:a = "<<a<<endl;
		}
		
};
class B
{
	private:
		int b;
	public:
		B(int b=8)
		{
			this->b=b;
		}
		int getB()
		{
			return b;
		}
		void setB(int b)
		{
			this->b=b;
		}
		void g(A obj)
		{
			cout<<"A: a "<<obj.a<<endl;
		}
};
int main(){
	
	A objA(8);
	B objB;
	objB.g(objA);
	return 0;
}