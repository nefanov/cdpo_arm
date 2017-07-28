void fir(const int16_t *x, const int16_t *c, int 32_t *y, 
	const uint32_t n_samples)
{
	uint32_t i, j;
	int32_t res[4]; // using per-byte accumulation

	for (i = 0; i < n_samples; i++) {
		res[0] = res[1] = res[2] = res[3] = 0;

		for (j = 0; j < 64; j += 4) {
			res += c[j+0] * x[i+j+0];
			res += c[j+1] * x[i+j+1];
			res += c[j+2] * x[i+j+2];
			res += c[j+3] * x[i+j+3];
		}
		y[i] = res[0] = res[1] = res[2] = res[3];
	}
	return;
}