#include <iostream>
#include <cmath>

using namespace std;

class triangle
{	
	float l1, l2, l3;
	public:
	triangle()
	{
		l1 = 0; l2 = 0; l3 = 0;
	}
	triangle(float,float,float);
	void check();
	void print();
	void area(float);
	void area(float,float);
	void area(float,float,float);
	triangle& operator=(triangle);
	bool operator==(triangle);
	~triangle(){};
};

triangle::triangle(float a, float b, float c)
{
	l1 = (a < b && a < c ? a : (b < c ? b : c));//This will be the smallest side always
	
	l3 = (a > b ? (a > c ? a : c) : (b > c ? b : c));//This will be the largest side always
	
	l2 = a + b + c - l1 - l3;//This will be the median side always
}

void triangle::print()
{
cout << "\n\t The parameters of the Triangle :  " << l1 <<"\t" << l2 << "\t" << l3 << endl;
}

void triangle::check()
{	
	if(l3 >= l1 + l2||l2>=l1+l3||l1>=l2+l3)
		cout << "\n\n\t This is wrong parameters for a triangle.\n";
	else if(l1 == l2 && l2 == l3)
		area(l1);
	else if(l3*l3 == (l1*l1 + l2*l2))
		area(l1,l2);
	else
		area(l1, l2, l3);
}

void triangle::area(float a)
{
		float area =sqrt(3)*(a*a);
           area/=4;
	cout << "\n\n\t The area of equilateral triangle  :  " << area << endl;
}

void triangle::area(float a, float b)
{
	float area = 0.5 * a * b;
	cout << "\n\n\t The area of right angle triangle  :  " << area << endl;
}

void triangle::area(float a, float b, float c)
{
	float area, s;
	
	s = (a+b+c) / 2;
	area = sqrt(s * (s - a) * (s - b) * (s - c));		
	cout << "\n\n\t The area of triangle with distinct sides solved with heron formula :  " << area << endl;
}

triangle& triangle::operator=(triangle r)
{
	l1 = r.l1;
	l2 = r.l2;
	l3 = r.l3;
	return (*this);
}

bool triangle::operator==(triangle r)
{
	bool equal;
	equal = (l1 == r.l1 && l2 == r.l2 && l3 == r.l3);
	return equal;
}

void set_(float &a, float &b, float &c)
{
	bool non_valid = false;
	do
	{
		cout << "\n\n Enter the parameters of the triangle.....";
		cout << "\n\n\t\t Side1 length : ";
		cin >> a;
		cout << "\t\t Side2 length : ";
		cin >> b;
		cout << "\t\t Side3 length : ";
		cin >> c;
		
		if(a <= 0 || b <= 0 || c <= 0)
		{
			cout << "\n\n The length of the triangle can't be negative nor 0." << endl;
			non_valid = true;
		}
		else
			non_valid = false;
	}while(non_valid);
}

int main()
{	float s1, s2, s3;
	int op ;
		 cout<<"\n\n\n************************************************\nPROGRAM TO OPERATE ON TRIANGLE\n***************************************************\n\n";
		 cout<<"\n*****Enter sides of triangle 1 for calculating area:*******\n\n";
	set_(s1,s2,s3);
	triangle t1(s1,s2,s3);
	
	cout<<"\n*****Enter sides of triangle 2 for overload assignment and overload equality operator:******\n\n";
	set_(s1,s2,s3);
	triangle t2(s1,s2,s3);
	
	while(op!=4)
	{
		cout << "\n\n Choose :- \n\n\t 1. Calculate Area \n\t 2. Overload assignment operator \n\t 3. Overload equality operator";
		cout << "\n\t 4. Quit \n\n Enter your choice :-  ";
		cin >> op;
		switch(op)
		{
			case 1:
				t1.check();
				break;
				
			case 2:
				cout<<"\nFirst triangle original dimensions\n";
				t1.print();
			cout<<"\nSecond triangle original dimensions\n";
				t2.print();
				t2 = t1;
				cout<<"\n****After operation****\n";
				cout << "\n First Triangle \n";
				t1.print();
				cout << "\n Second Triangle \n";
				t2.print();
				break;
				
			case 3:
				if(t2== t1)
					cout << "\n\n The parameters of two triangles are same.\n";
				else
					cout << "\n\n The parameters of two triangles are not same.\n";	
				break;
				case 4: cout<<"Exiting.....";
				exit(1);
				
			default:
					cout << "\n\n !!Invalid input!!\n";
		}
	}
	return 0;
}
