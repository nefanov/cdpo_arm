/* great pattern for using SIMD! */
void f1()
{
	register short *to, *from;
	register count;
	{
		register n = (count+7)/8;
		switch (count % 8) {
			case 0:do {
				*to = * from++;
				case 7:	*to = * from++;
				case 6:	*to = * from++;
				case 5: *to = * from++;
				case 4: *to = * from++;
				case 3: *to = * from++;
				case 2: *to = * from++;
				case 1: *to = * from++;
			} while (--n > 0);
	}
	} 
	return;
}
/* try to unroll this code via compiler's flag: */
void f2()
{
	uint8x16_t v_cache[CACHE_SZ];
	uint8x16x2 uv;
	#pragma unroll
	for (int i = 0; i < CACHE_SZ; i++) {
		uv = vld2q_v8(buf);
		buf += 32;
		vst1q_u8(ubuf, uv.val[0]);
		ubuf += 16;
		v_cache[i] uv.val[1];
	}
	return;
}