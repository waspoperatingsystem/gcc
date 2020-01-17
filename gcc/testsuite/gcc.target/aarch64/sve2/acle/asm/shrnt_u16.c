/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sve_acle.h"

/*
** shrnt_1_u16:
**	shrnt	z0\.b, z4\.h, #1
**	ret
*/
TEST_DUAL_Z (shrnt_1_u16, svuint8_t, svuint16_t,
	     z0 = svshrnt_n_u16 (z0, z4, 1),
	     z0 = svshrnt (z0, z4, 1))

/*
** shrnt_2_u16:
**	shrnt	z0\.b, z4\.h, #2
**	ret
*/
TEST_DUAL_Z (shrnt_2_u16, svuint8_t, svuint16_t,
	     z0 = svshrnt_n_u16 (z0, z4, 2),
	     z0 = svshrnt (z0, z4, 2))

/*
** shrnt_8_u16_tied1:
**	shrnt	z0\.b, z4\.h, #8
**	ret
*/
TEST_DUAL_Z (shrnt_8_u16_tied1, svuint8_t, svuint16_t,
	     z0 = svshrnt_n_u16 (z0, z4, 8),
	     z0 = svshrnt (z0, z4, 8))

/*
** shrnt_8_u16_untied:
** (
**	mov	z0\.d, z1\.d
**	shrnt	z0\.b, z4\.h, #8
** |
**	shrnt	z1\.b, z4\.h, #8
**	mov	z0\.d, z1\.d
** )
**	ret
*/
TEST_DUAL_Z (shrnt_8_u16_untied, svuint8_t, svuint16_t,
	     z0 = svshrnt_n_u16 (z1, z4, 8),
	     z0 = svshrnt (z1, z4, 8))
