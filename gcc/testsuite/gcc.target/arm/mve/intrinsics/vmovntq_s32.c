/* { dg-do compile  } */
/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */

#include "arm_mve.h"

int16x8_t
foo (int16x8_t a, int32x4_t b)
{
  return vmovntq_s32 (a, b);
}

/* { dg-final { scan-assembler "vmovnt.i32"  }  } */

int16x8_t
foo1 (int16x8_t a, int32x4_t b)
{
  return vmovntq (a, b);
}

/* { dg-final { scan-assembler "vmovnt.i32"  }  } */
