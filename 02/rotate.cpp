void rotate(int a[], unsigned size, int shift)
{
	int b[size];
	for (unsigned i = 0; i < size; ++i)
		b[i] = a[(size + i + shift) % size];
	for (unsigned i = 0; i < size; ++i)
		a[i] = b[i];
}
