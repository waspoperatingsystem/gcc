/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sve_acle.h"

/*
** hadd_u64_m_tied1:
**	uhadd	z0\.d, p0/m, z0\.d, z1\.d
**	ret
*/
TEST_UNIFORM_Z (hadd_u64_m_tied1, svuint64_t,
		z0 = svhadd_u64_m (p0, z0, z1),
		z0 = svhadd_m (p0, z0, z1))

/*
** hadd_u64_m_tied2:
**	mov	(z[0-9]+\.d), z0\.d
**	movprfx	z0, z1
**	uhadd	z0\.d, p0/m, z0\.d, \1
**	ret
*/
TEST_UNIFORM_Z (hadd_u64_m_tied2, svuint64_t,
		z0 = svhadd_u64_m (p0, z1, z0),
		z0 = svhadd_m (p0, z1, z0))

/*
** hadd_u64_m_untied:
**	movprfx	z0, z1
**	uhadd	z0\.d, p0/m, z0\.d, z2\.d
**	ret
*/
TEST_UNIFORM_Z (hadd_u64_m_untied, svuint64_t,
		z0 = svhadd_u64_m (p0, z1, z2),
		z0 = svhadd_m (p0, z1, z2))

/*
** hadd_x0_u64_m_tied1:
**	mov	(z[0-9]+\.d), x0
**	uhadd	z0\.d, p0/m, z0\.d, \1
**	ret
*/
TEST_UNIFORM_ZX (hadd_x0_u64_m_tied1, svuint64_t, uint64_t,
		 z0 = svhadd_n_u64_m (p0, z0, x0),
		 z0 = svhadd_m (p0, z0, x0))

/*
** hadd_x0_u64_m_untied:
**	mov	(z[0-9]+\.d), x0
**	movprfx	z0, z1
**	uhadd	z0\.d, p0/m, z0\.d, \1
**	ret
*/
TEST_UNIFORM_ZX (hadd_x0_u64_m_untied, svuint64_t, uint64_t,
		 z0 = svhadd_n_u64_m (p0, z1, x0),
		 z0 = svhadd_m (p0, z1, x0))

/*
** hadd_11_u64_m_tied1:
**	mov	(z[0-9]+\.d), #11
**	uhadd	z0\.d, p0/m, z0\.d, \1
**	ret
*/
TEST_UNIFORM_Z (hadd_11_u64_m_tied1, svuint64_t,
		z0 = svhadd_n_u64_m (p0, z0, 11),
		z0 = svhadd_m (p0, z0, 11))

/*
** hadd_11_u64_m_untied:: { xfail *-*-*}
**	mov	(z[0-9]+\.d), #11
**	movprfx	z0, z1
**	uhadd	z0\.d, p0/m, z0\.d, \1
**	ret
*/
TEST_UNIFORM_Z (hadd_11_u64_m_untied, svuint64_t,
		z0 = svhadd_n_u64_m (p0, z1, 11),
		z0 = svhadd_m (p0, z1, 11))

/*
** hadd_u64_z_tied1:
**	movprfx	z0\.d, p0/z, z0\.d
**	uhadd	z0\.d, p0/m, z0\.d, z1\.d
**	ret
*/
TEST_UNIFORM_Z (hadd_u64_z_tied1, svuint64_t,
		z0 = svhadd_u64_z (p0, z0, z1),
		z0 = svhadd_z (p0, z0, z1))

/*
** hadd_u64_z_tied2:
**	movprfx	z0\.d, p0/z, z0\.d
**	uhadd	z0\.d, p0/m, z0\.d, z1\.d
**	ret
*/
TEST_UNIFORM_Z (hadd_u64_z_tied2, svuint64_t,
		z0 = svhadd_u64_z (p0, z1, z0),
		z0 = svhadd_z (p0, z1, z0))

/*
** hadd_u64_z_untied:
** (
**	movprfx	z0\.d, p0/z, z1\.d
**	uhadd	z0\.d, p0/m, z0\.d, z2\.d
** |
**	movprfx	z0\.d, p0/z, z2\.d
**	uhadd	z0\.d, p0/m, z0\.d, z1\.d
** )
**	ret
*/
TEST_UNIFORM_Z (hadd_u64_z_untied, svuint64_t,
		z0 = svhadd_u64_z (p0, z1, z2),
		z0 = svhadd_z (p0, z1, z2))

/*
** hadd_x0_u64_z_tied1:
**	mov	(z[0-9]+\.d), x0
**	movprfx	z0\.d, p0/z, z0\.d
**	uhadd	z0\.d, p0/m, z0\.d, \1
**	ret
*/
TEST_UNIFORM_ZX (hadd_x0_u64_z_tied1, svuint64_t, uint64_t,
		 z0 = svhadd_n_u64_z (p0, z0, x0),
		 z0 = svhadd_z (p0, z0, x0))

/*
** hadd_x0_u64_z_untied:
**	mov	(z[0-9]+\.d), x0
** (
**	movprfx	z0\.d, p0/z, z1\.d
**	uhadd	z0\.d, p0/m, z0\.d, \1
** |
**	movprfx	z0\.d, p0/z, \1
**	uhadd	z0\.d, p0/m, z0\.d, z1\.d
** )
**	ret
*/
TEST_UNIFORM_ZX (hadd_x0_u64_z_untied, svuint64_t, uint64_t,
		 z0 = svhadd_n_u64_z (p0, z1, x0),
		 z0 = svhadd_z (p0, z1, x0))

/*
** hadd_11_u64_z_tied1:
**	mov	(z[0-9]+\.d), #11
**	movprfx	z0\.d, p0/z, z0\.d
**	uhadd	z0\.d, p0/m, z0\.d, \1
**	ret
*/
TEST_UNIFORM_Z (hadd_11_u64_z_tied1, svuint64_t,
		z0 = svhadd_n_u64_z (p0, z0, 11),
		z0 = svhadd_z (p0, z0, 11))

/*
** hadd_11_u64_z_untied:
**	mov	(z[0-9]+\.d), #11
** (
**	movprfx	z0\.d, p0/z, z1\.d
**	uhadd	z0\.d, p0/m, z0\.d, \1
** |
**	movprfx	z0\.d, p0/z, \1
**	uhadd	z0\.d, p0/m, z0\.d, z1\.d
** )
**	ret
*/
TEST_UNIFORM_Z (hadd_11_u64_z_untied, svuint64_t,
		z0 = svhadd_n_u64_z (p0, z1, 11),
		z0 = svhadd_z (p0, z1, 11))

/*
** hadd_u64_x_tied1:
**	uhadd	z0\.d, p0/m, z0\.d, z1\.d
**	ret
*/
TEST_UNIFORM_Z (hadd_u64_x_tied1, svuint64_t,
		z0 = svhadd_u64_x (p0, z0, z1),
		z0 = svhadd_x (p0, z0, z1))

/*
** hadd_u64_x_tied2:
**	uhadd	z0\.d, p0/m, z0\.d, z1\.d
**	ret
*/
TEST_UNIFORM_Z (hadd_u64_x_tied2, svuint64_t,
		z0 = svhadd_u64_x (p0, z1, z0),
		z0 = svhadd_x (p0, z1, z0))

/*
** hadd_u64_x_untied:
** (
**	movprfx	z0, z1
**	uhadd	z0\.d, p0/m, z0\.d, z2\.d
** |
**	movprfx	z0, z2
**	uhadd	z0\.d, p0/m, z0\.d, z1\.d
** )
**	ret
*/
TEST_UNIFORM_Z (hadd_u64_x_untied, svuint64_t,
		z0 = svhadd_u64_x (p0, z1, z2),
		z0 = svhadd_x (p0, z1, z2))

/*
** hadd_x0_u64_x_tied1:
**	mov	(z[0-9]+\.d), x0
**	uhadd	z0\.d, p0/m, z0\.d, \1
**	ret
*/
TEST_UNIFORM_ZX (hadd_x0_u64_x_tied1, svuint64_t, uint64_t,
		 z0 = svhadd_n_u64_x (p0, z0, x0),
		 z0 = svhadd_x (p0, z0, x0))

/*
** hadd_x0_u64_x_untied:
**	mov	z0\.d, x0
**	uhadd	z0\.d, p0/m, z0\.d, z1\.d
**	ret
*/
TEST_UNIFORM_ZX (hadd_x0_u64_x_untied, svuint64_t, uint64_t,
		 z0 = svhadd_n_u64_x (p0, z1, x0),
		 z0 = svhadd_x (p0, z1, x0))

/*
** hadd_11_u64_x_tied1:
**	mov	(z[0-9]+\.d), #11
**	uhadd	z0\.d, p0/m, z0\.d, \1
**	ret
*/
TEST_UNIFORM_Z (hadd_11_u64_x_tied1, svuint64_t,
		z0 = svhadd_n_u64_x (p0, z0, 11),
		z0 = svhadd_x (p0, z0, 11))

/*
** hadd_11_u64_x_untied:
**	mov	z0\.d, #11
**	uhadd	z0\.d, p0/m, z0\.d, z1\.d
**	ret
*/
TEST_UNIFORM_Z (hadd_11_u64_x_untied, svuint64_t,
		z0 = svhadd_n_u64_x (p0, z1, 11),
		z0 = svhadd_x (p0, z1, 11))
