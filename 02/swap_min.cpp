#include <algorithm>

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    /* ... */
    int min_val_row = 0;
    int min_val = m[0][0];
    for (unsigned y = 0; y != rows; ++y)
    {
        int local_min = *std::min_element(m[y], m[y] + cols);
        if (local_min < min_val)
        {
            min_val = local_min;
            min_val_row = y;
        }
    }
    std::swap(m[0], m[min_val_row]);
}
