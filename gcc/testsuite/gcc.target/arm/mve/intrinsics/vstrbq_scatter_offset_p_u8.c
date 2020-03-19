/* { dg-do compile  } */
/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */

#include "arm_mve.h"

void
foo (uint8_t * base, uint8x16_t offset, uint8x16_t value, mve_pred16_t p)
{
  vstrbq_scatter_offset_p_u8 (base, offset, value, p);
}

/* { dg-final { scan-assembler "vstrbt.8"  }  } */

void
foo1 (uint8_t * base, uint8x16_t offset, uint8x16_t value, mve_pred16_t p)
{
  vstrbq_scatter_offset_p (base, offset, value, p);
}

/* { dg-final { scan-assembler "vstrbt.8"  }  } */
