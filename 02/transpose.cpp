int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    if (rows && cols && m)
    {
        const unsigned &new_rows = cols;
        const unsigned &new_cols = rows;
        int **ret_val = new int*[new_rows];
        ret_val[0] = new int[new_rows*new_cols];
        for (unsigned i = 1; i != new_rows; ++i)
            ret_val[i] = ret_val[i-1] + new_cols;
        for (unsigned y = 0; y != rows; ++y)
            for (unsigned x = 0; x != cols; ++x)
                ret_val[x][y] = m[y][x];
        return ret_val;
    }
    
    return 0;
}
