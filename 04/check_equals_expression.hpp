#pragma once

struct Expression;

bool check_equals(Expression const *left, Expression const *right)
{
    // put your code here
    return *(long long*)((char*)left) == *(long long*)((char*)right);
}
