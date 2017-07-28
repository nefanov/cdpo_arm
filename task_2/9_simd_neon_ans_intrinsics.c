#include <arm_neon.c>
/* try to rewrite the algo in attempt to use SIMD */

void fir(const int16_t *x, const int16_t *c, int 32_t *y, 
	const uint32_t n_samples)
{
	uint32_t i, j;
	int16x4_t xld, cld;
	int32_t res = 0;

	for (i = 0; i < n_samples; i++) {
		res = 0;

		for (j = 0; j < 64; j++) {
			xld = vld1_s16(s+i+j);
			cld = vld1_s16(c+j);
			res = vmlal_s16(res, xld, cld);
		}
		y[i] = vgetq_lane_s32(res,0) + vgetq_lane_s32(res,1) +
		vgetq_lane_s32(res,2) + vgetq_lane_s32(res,3);
	}
	return;
}