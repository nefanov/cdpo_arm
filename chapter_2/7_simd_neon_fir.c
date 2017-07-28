/* try to rewrite the algo in attempt to use SIMD */

void fir(const int16_t *x, const int16_t *c, int 32_t *y, 
	const uint32_t num_samples)
{
	uint32_t i, j;
	int32_t res = 0;

	for (i = 0; i < num_samples; i++) {
		res = 0;

		for (j = 0; j < 64; j++) {
			res += c[j] * x[i+j];
		}
		y[i] = res;
	}
	return;
}
