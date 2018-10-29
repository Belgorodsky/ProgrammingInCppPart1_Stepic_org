struct Rational
{
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    Rational& operator+=(Rational rational);
    Rational& operator-=(Rational rational);
    Rational& operator*=(Rational rational);
    Rational& operator/=(Rational rational);

    Rational operator-() const;
    Rational operator+() const;

    int numerator() const;
    int denominator() const;

    private:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational lhs, Rational rhs);
Rational operator-(Rational lhs, Rational rhs);
Rational operator*(Rational lhs, Rational rhs);
Rational operator/(Rational lhs, Rational rhs);

int Rational::numerator() const
{
    return numerator_;
}

int Rational::denominator() const
{
    return denominator_;
}

bool operator==(Rational const& lhs, Rational const& rhs)
{
    Rational a = lhs - rhs;
    return a.numerator() == 0; 
}

bool operator!=(const Rational &lhs, const Rational &rhs)
{
    return !(lhs == rhs);
}

bool operator<(Rational const& lhs, Rational const& rhs)
{
    Rational a = rhs - lhs;
    return a.numerator() > 0;
}

bool operator>(const Rational &lhs, const Rational &rhs)
{
    return rhs < lhs;
}

bool operator<=(const Rational &lhs, const Rational &rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const Rational &lhs, const Rational &rhs)
{
    return !(lhs < rhs);
}
