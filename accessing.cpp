#include<iostream>

using namespace std;

class A
{
    public:
        A(){
            callA = 0;
        }
    private:
        int callA;
        void inc(){
            callA++;
        }

    protected:
        void func(int & a)
        {
            a = a * 2;
            inc();
        }
    public:
        int getA(){
            return callA;
        }
};

class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};

class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};

class D 
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val = 1;
		 }


		 //Implement this function
		  void update_val(int new_val) {
            while (val < new_val) {
                while (new_val % 2 == 0 && val * 2 <= new_val) {
                    A::func(val);
                }
                while (new_val % 3 == 0 && val * 3 <= new_val) {
                    B::func(val);
                }
                while (new_val % 5 == 0 && val * 5 <= new_val) {
                    C::func(val);
                }
            }
        }
        
        void check(int new_val) {
            update_val(new_val);
            cout << "Value = " << val << endl;
            cout << "A's func will be called " << A::getA() << " times" << endl;
            cout << "B's func will be called " << B::getB() << " times" << endl;
            cout << "C's func will be called " << C::getC() << " times" << endl;
        }
};
 


void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);

}
