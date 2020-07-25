#pragma once
#include <complex>
#include <iostream>

using namespace std;

namespace solver
{

    //define real variable class
    class RealVariable
    {
    private:

        //define varibales we may need
        double a = 0.0; //as we did in opp
        double b = 1.0; //as we did in opp
        double c = 0.0; //as we did in opp




    public:


        //constructor
        RealVariable() {}
        RealVariable(double Cans): a(0) , b(0) , c(Cans) {}


        //RealVariable *add=NULL;
      //  bool isnanl=true;


        //define geters
        double getA(){return a;};//return A
        double getB(){return b;};//return B
        double getC(){return c;};//return C

        //define geters
        void setA(int a);//return A
        void setB(double b);//return B
        void setC(double c);//return C




        // OLD VER

        //define varibles for now use
        /*
        // ==
        friend RealVariable& operator==(RealVariable& y, int x);//define: x=int
        friend RealVariable& operator==(RealVariable& y, const double x);//define: x=double
        friend RealVariable& operator==(int x, RealVariable& y);//define: int=x
        friend RealVariable& operator==(const double x, RealVariable& y);//define: double=x
        friend RealVariable& operator==(RealVariable& x, RealVariable& y);//define: x1=x2

        //+
        friend RealVariable& operator+(int x, RealVariable& y);//define: int+x
        friend RealVariable& operator+( double x, RealVariable& y);//define: double+x
        friend RealVariable& operator+(RealVariable& x, RealVariable& y);//define: x1+x2
        friend RealVariable& operator+(RealVariable& y, const double x);//define: x+double
        friend RealVariable& operator+(RealVariable& y, int x);//define: x+int

        //-
        friend RealVariable& operator-(RealVariable& y, int x);//define: x-int
        friend RealVariable& operator-(RealVariable& y, const double x);//define: x-double
        friend RealVariable& operator-(RealVariable& x, RealVariable& y);//define: x1-x2
        friend RealVariable& operator-(RealVariable& y);//define: x
        friend RealVariable& operator-(int x,RealVariable& y);//define: int-x
        friend RealVariable& operator-(const double x,RealVariable& y);//define: double-x



        friend RealVariable& operator*(int x, RealVariable& y); //define: int*x
        friend RealVariable& operator*(const double x, RealVariable& y);//define: dobule*x
        friend RealVariable& operator*(RealVariable& y, int x);//define: x*int
        friend RealVariable& operator*(RealVariable& y, const double x);//define: x*double

        //^
        friend RealVariable& operator^(RealVariable& y, int x);//define: x^int

        // /
        friend RealVariable& operator/(RealVariable& y, const double x);////define: x/double
                *///////
        // NEW VER3
        friend RealVariable operator == (RealVariable X, RealVariable Y);
        friend RealVariable operator ^  (RealVariable X, RealVariable Y);
        friend RealVariable operator *  (RealVariable X, RealVariable Y);
        friend RealVariable operator /  (RealVariable X, RealVariable Y);
        friend RealVariable operator +  (RealVariable X, RealVariable Y);
        friend RealVariable operator -  (RealVariable X, RealVariable Y);

    };


    //define complex variable class
    class ComplexVariable
    {
    private:
        complex <double> a = 0.0; //as we did in opp
        complex <double> b = 1.0; //as we did in opp
        complex <double> c = 0.0; //as we did in opp

    public:
        ComplexVariable(){}
        ComplexVariable(std::complex<double> c) : a(0) , b(0) , c(c){}
        ComplexVariable(double c) : a(0), b(0), c(c) {} // apperanly needed

        ///Getters
        complex <double> getA()
        {
            return a;
        }
        complex <double> getB()
        {
            return b;
        }
        complex <double> getC()
        {
            return c;
        }

        friend ComplexVariable  operator == (ComplexVariable  X, ComplexVariable  Y);
        friend ComplexVariable  operator ^  (ComplexVariable  X, ComplexVariable  Y);
        friend ComplexVariable  operator *  (ComplexVariable  X, ComplexVariable  Y);
        friend ComplexVariable  operator /  (ComplexVariable  X, ComplexVariable  Y);
        friend ComplexVariable  operator +  (ComplexVariable  X, ComplexVariable  Y);
        friend ComplexVariable  operator -  (ComplexVariable  X, ComplexVariable  Y);

    };
// solvemethods in namespace
    double solve(RealVariable);
    std::complex<double> solve(ComplexVariable);

        /** OLDVER
        //constructor
        //ComplexVariable();

        //real and imagine constructor
        //ComplexVariable(double realnumber,double imagenumber);



        //define find values

        //define varibles for now use
        complex<double> comp = 0. + 0i;
        ComplexVariable() : Ca(0,0),Cb(1,0),Cc(0,0) {}
        ComplexVariable(std::complex<double> a,std::complex<double> b , std::complex<double> c) : Ca(a), Cb(b) , Cc(c) {}

        //==
        // friend ComplexVariable& operator==(ComplexVariable& y, int x);//define: x=int
        friend ComplexVariable& operator==(ComplexVariable& y, const double x);//define: x=double
        friend ComplexVariable& operator==(ComplexVariable& x, ComplexVariable& y);//define: x1=x2
        // friend ComplexVariable& operator==(int x, ComplexVariable& y);//define: int=x
        friend ComplexVariable& operator==(const double x, ComplexVariable& y);//define: double=x
        friend ComplexVariable& operator==(const complex<double> x , ComplexVariable& y);//define: double=x
        friend ComplexVariable& operator==(ComplexVariable& y, const complex<double>);//define: double=x


        //+
        // friend ComplexVariable& operator+(int x, ComplexVariable& y);//define: int+x
        friend ComplexVariable& operator+(const double x, ComplexVariable& y);//define: double+x
        friend ComplexVariable& operator+(ComplexVariable& x, ComplexVariable& y);//define: x1+x2
        friend ComplexVariable& operator+(ComplexVariable& y, const double x);//define: x+double
        //friend ComplexVariable& operator+(ComplexVariable& y, int x);//define: x+int
        friend ComplexVariable& operator+(ComplexVariable& y, complex<double> x);//define: x+x(double)
        friend ComplexVariable& operator+(complex<double> x,ComplexVariable& y);//define: x+x(double)

        //-
        // friend ComplexVariable& operator-(ComplexVariable& y, int x);//define: x-int
        // friend ComplexVariable& operator-(int x, ComplexVariable& y);//define: int-x
        friend ComplexVariable& operator-(const double x, ComplexVariable& y);//define: double-x
        friend ComplexVariable& operator-(ComplexVariable& y, const double x);//define: x-double
        friend ComplexVariable& operator-(ComplexVariable& x, ComplexVariable& y);//define: x1-x2
        friend ComplexVariable& operator-(ComplexVariable& y);//define: x
        friend ComplexVariable& operator-(complex<double> x, ComplexVariable &y);//define: x(double)-x
        friend ComplexVariable& operator-(ComplexVariable &y , complex<double> x);//define: x(double)-x


        //*
        // friend ComplexVariable& operator*(int x ,ComplexVariable& y);//define: int*x
        // friend ComplexVariable& operator*(ComplexVariable& y, int x);//define: x*double
        friend ComplexVariable& operator*(complex<double> x, ComplexVariable &y);//define: x(double)*x
        friend ComplexVariable& operator*(ComplexVariable &y , complex<double> x);//define: x(double)*x
        friend ComplexVariable& operator*(double x, ComplexVariable &y);//define: x(double)*x
        friend ComplexVariable& operator*(ComplexVariable &y , double x );//define: x(double)*x
        //   friend ComplexVariable& operator*(ComplexVariable &x, ComplexVariable &y);




        // /
        friend ComplexVariable& operator/(ComplexVariable& y, const double x);
        //^
        friend ComplexVariable& operator^(ComplexVariable& y, const double x);//define: x^int



    };

    //solve func
    double solve(RealVariable &x); //get real variable and return answer in double.

    complex<double> solve(ComplexVariable &x); //get complex variable and return answer in complex double.
**/

}
