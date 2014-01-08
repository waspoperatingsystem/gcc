/* { dg-do compile } */
/* { dg-options "-mavx512f -O2" } */
/* { dg-final { scan-assembler-times "vprorvq\[ \\t\]+\[^\n\]*%zmm\[0-9\]\[^\{\]" 3 } } */
/* { dg-final { scan-assembler-times "vprorvq\[ \\t\]+\[^\n\]*%zmm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vprorvq\[ \\t\]+\[^\n\]*%zmm\[0-9\]\{%k\[1-7\]\}\{z\}" 1 } } */

#include <immintrin.h>

volatile __m512i x;
volatile __mmask8 m;

void extern
avx512f_test (void)
{
  x = _mm512_rorv_epi64 (x, x);
  x = _mm512_mask_rorv_epi64 (x, m, x, x);
  x = _mm512_maskz_rorv_epi64 (m, x, x);
}
