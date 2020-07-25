//
// Created by Roie Malykin
//
#include "solver.hpp"
#include <iostream>
#include <complex>

namespace solver
{
    RealVariable operator == (RealVariable X, RealVariable Y)
    {
        RealVariable ans = X - Y;
        return ans;
    }
    /**
     * This method made me cry in my pillow, was semi-smootly solved by Nati
     * @param X
     * @param Y
     * @return
     */
    RealVariable operator ^  (RealVariable X, RealVariable Y)
    {
        if(Y.c != 2)
        {
            throw std::invalid_argument("Power must be 2"); //
        }
        RealVariable temp;
        temp.a = 1;
        temp.b = 0;
        temp.c = 0;
        return temp;
    }
    RealVariable operator *  (RealVariable X, RealVariable Y)
    {
        RealVariable temp;
        temp.c = X.c * Y.c;
        temp.b = X.b * Y.c + X.c * Y.b;
        temp.a = X.a * Y.c + Y.a * X.c + X.b *Y.b;
        return temp;
    }
    RealVariable operator / (RealVariable X, RealVariable Y)
    {
        RealVariable temp;
        temp.c = X.c / Y.c;
        temp.b = X.b / Y.c;
        temp.a = X.a / Y.c;
        return temp;
    }

    RealVariable operator + (RealVariable X, RealVariable Y)
    {
        RealVariable temp;
        temp.c = X.c + Y.c;
        temp.b = X.b + Y.b;
        temp.a = X.a + Y.a;
        return temp;
    }
    RealVariable operator - (RealVariable X, RealVariable Y)
    {
        RealVariable temp;
        temp.c = X.c - Y.c;
        temp.b = X.b - Y.b;
        temp.a = X.a - Y.a;
        return temp;
    }

    double solve(RealVariable X)
    {
        double a = X.getA();
        double b = X.getB();
        double c = X.getC();
        double ans;


        if(a == 0.0 && b == 0.0)
            throw std::runtime_error("No solution within the real numbers");
        else if(a == 0.0)
            ans = -c/b;
        else{
            double d = b*b - 4.0*a*c;
            if(d >= 0)
                ans = (- b + std::sqrt(d)) / (2.0*a);
            else
                throw std::runtime_error("No solution within the real numbers");
        }
        return ans;
    }

    ComplexVariable operator == (ComplexVariable X, ComplexVariable Y)
    {
        ComplexVariable temp = X - Y;
        return temp;
    }
    ComplexVariable operator ^ (ComplexVariable X, ComplexVariable Y)
    {
        if(Y.c.real() != 2){
            throw std::invalid_argument("Power must be 2");
        }
        ComplexVariable temp;
        temp.c = 0;
        temp.b = 0;
        temp.a = 1.0;
        return temp;
    }
    ComplexVariable operator * (ComplexVariable X, ComplexVariable Y)
    {
        ComplexVariable temp;
        temp.c = X.c * Y.c;
        temp.b = X.b * Y.c + X.c * Y.b;
        temp.a = X.a * Y.c + Y.a * X.c + X.b * Y.b;
        return temp;
    }
    ComplexVariable operator / (ComplexVariable X, ComplexVariable Y)
    {
        ComplexVariable temp;
        temp.c = X.c / Y.c;
        temp.b = X.b / Y.c;
        temp.a = X.a / Y.c;
        return temp;
    }
    ComplexVariable operator + (ComplexVariable X, ComplexVariable Y)
    {
        ComplexVariable temp;
        temp.c = X.c + Y.c;
        temp.b = X.b + Y.b;
        temp.a = X.a + Y.a;
        return temp;
    }
    ComplexVariable operator - (ComplexVariable X, ComplexVariable Y)
    {
        ComplexVariable temp;
        temp.c = X.c - Y.c;
        temp.b = X.b - Y.b;
        temp.a = X.a - Y.a;
        return temp;
    }

    std::complex<double> solve(ComplexVariable Y)
    {
        std::complex<double> a = Y.getA();
        std::complex<double> b = Y.getB();
        std::complex<double> c = Y.getC();
        std::complex<double> ans;

        if(a.real() == 0.0 && b.real() == 0.0 && a.imag() == 0.0 && b.imag() == 0.0)
            throw std::runtime_error("No solution to the real numbers");
        else if(a.real() == 0.0 && a.imag() == 0.0)
            ans = -c/b;
        else
            {
            std::complex<double> d = std::sqrt(b*b - 4.0*a*c);
            ans = (- b + d) / (2.0*a);
        }
        return ans;
    }


}
