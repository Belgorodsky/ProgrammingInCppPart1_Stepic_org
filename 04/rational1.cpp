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
    Rational& operator += (const Rational &A);
    Rational& operator -= (const Rational &A);
    Rational& operator *= (const Rational &A);
    Rational& operator /= (const Rational &A);

    private:
    int numerator_;
    unsigned denominator_;
};

Rational& Rational::operator+=(const Rational &rhs)
{
    this->add(rhs);
    return *this;
}

Rational& Rational::operator-=(const Rational &rhs)
{
    this->sub(rhs);
    return *this;
}

Rational& Rational::operator*=(const Rational &rhs)
{
    this->mul(rhs);
    return *this;
}

Rational& Rational::operator/=(const Rational &rhs)
{
    this->div(rhs);
    return *this;
}

Rational operator-(Rational rhs)
{
    rhs.neg();
    return rhs;
}

Rational operator+(Rational const & rhs)
{
    return rhs;
}
