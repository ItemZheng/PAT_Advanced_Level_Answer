#include <iostream>

using namespace std;

// 无坑，注意需要long的范围。可以直接把所有的int 改成 long 

long gcd(long m, long n){
    if(m % n == 0){
        return n;
    }
    return gcd(n, m % n);
}

long getFactor(long m, long n){
    if(m > n){
        return gcd(m, n);
    }
    return gcd(n, m);
}


class Rational{
public:
    long numerator, denominator;
public:
    Rational(){
        numerator = 0;
        denominator = 1;
    }

    void simplify(){
        if(numerator == 0){
            denominator = 1;
            return;
        }
        if(denominator == 0){
            return;
        }

        if(denominator < 0){
            denominator = -denominator;
            numerator = -numerator;
        }

        long factor = getFactor(abs(numerator), denominator);
        numerator /= factor;
        denominator /= factor;
    }

    void output(){
        long d = denominator, n = numerator;
        if(denominator == 0){
            cout << "Inf";
            return;
        }
        if(numerator == 0){
            cout << "0";
            return;
        }
        bool neg = numerator < 0;
        if(neg){
            cout << "(-";
            numerator = - numerator;
        }
        if(numerator / denominator != 0){
            cout << numerator / denominator;
            numerator = numerator % denominator;
            if(numerator > 0){
                cout << " ";
            }
        }
        if(numerator > 0){
            cout << numerator << "/" << denominator;
        }
        if(neg){
            cout << ")";
        }
        denominator = d;
        numerator = n;
    }

    void add(Rational r){
        Rational res;
        res.denominator = r.denominator * denominator;
        res.numerator = r.numerator * denominator + r.denominator * numerator;
        res.simplify();

        output();
        cout << " + ";
        r.output();
        cout << " = ";
        res.output();
        cout << endl;
    }

    void sub(Rational r){
        Rational res;
        res.denominator = r.denominator * denominator;
        res.numerator = r.denominator * numerator - r.numerator * denominator;
        res.simplify();

        output();
        cout << " - ";
        r.output();
        cout << " = ";
        res.output();
        cout << endl;
    }

    void mul(Rational r){
        Rational res;
        res.denominator = r.denominator * denominator;
        res.numerator = numerator * r.numerator;
        res.simplify();

        output();
        cout << " * ";
        r.output();
        cout << " = ";
        res.output();
        cout << endl;
    }

    void div(Rational r){
        Rational res;
        res.denominator = r.numerator * denominator;
        res.numerator = numerator * r.denominator;
        res.simplify();

        output();
        cout << " / ";
        r.output();
        cout << " = ";
        res.output();
        cout << endl;
    }

};

int main(){
    Rational r1, r2;
    for(long i = 0; i < 2; i++){
        string r_str;
        cin >> r_str;
        long idx = r_str.find('/');
        long n = stoi(r_str.substr(0, idx)), d = stoi(r_str.substr(idx + 1));
        if(i == 0){
            r1.denominator = d;
            r1.numerator = n;
        } else {
            r2.denominator = d;
            r2.numerator = n;
        }
    }

    r1.simplify();
    r2.simplify();
    r1.add(r2);
    r1.sub(r2);
    r1.mul(r2);
    r1.div(r2);
}