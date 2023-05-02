#ifndef __JSMATH_H__
#define __JSMATH_H__

#include <stdint.h>
/*
Math functions available in javascript

Math.abs()      Returns the absolute value of x.
Math.acos()     Returns the arccosine of x.
Math.acosh()    Returns the hyperbolic arccosine of x.
Math.asin()     Returns the arcsine of x.
Math.asinh()    Returns the hyperbolic arcsine of a number.
Math.atan()     Returns the arctangent of x.
Math.atanh()    Returns the hyperbolic arctangent of x.
Math.atan2()    Returns the arctangent of the quotient of its arguments.
Math.cbrt()     Returns the cube root of x.
Math.ceil()     Returns the smallest integer greater than or equal to x.
Math.clz32()    Returns the number of leading zero bits of the 32-bit integer x.
Math.cos()      Returns the cosine of x.
Math.cosh()     Returns the hyperbolic cosine of x.
Math.exp()      Returns ex, where x is the argument, and e is Euler's number (2.718…, the base of the natural logarithm).
Math.expm1()    Returns subtracting 1 from exp(x).
Math.floor()    Returns the largest integer less than or equal to x.
Math.fround()   Returns the nearest single precision float representation of x.
Math.hypot()    Returns the square root of the sum of squares of its arguments.
Math.imul()     Returns the result of the 32-bit integer multiplication of x and y.
Math.log()      Returns the natural logarithm (㏒e; also, ㏑) of x.
Math.log1p()    Returns the natural logarithm (㏒e; also ㏑) of 1 + x for the number x.
Math.log10()    Returns the base-10 logarithm of x.
Math.log2()     Returns the base-2 logarithm of x.
Math.max()      Returns the largest of zero or more numbers.
Math.min()      Returns the smallest of zero or more numbers.
Math.pow()      Returns base x to the exponent power y (that is, xy).
Math.random()   Returns a pseudo-random number between 0 and 1.
Math.round()    Returns the value of the number x rounded to the nearest integer.
Math.sign()     Returns the sign of the x, indicating whether x is positive, negative, or zero.
Math.sin()      Returns the sine of x.
Math.sinh()     Returns the hyperbolic sine of x.
Math.sqrt()     Returns the positive square root of x.
Math.tan()      Returns the tangent of x.
Math.tanh()     Returns the hyperbolic tangent of x.
*/

/* Constants definden in the math.h library */
#define M_E		    2.7182818284590452354	/* e */
#define M_LOG2E	    1.4426950408889634074	/* log_2 e */
#define M_LOG10E	0.43429448190325182765	/* log_10 e */
#define M_LN2		0.69314718055994530942	/* log_e 2 */
#define M_LN10		2.30258509299404568402	/* log_e 10 */
#define M_PI		3.14159265358979323846	/* pi */
#define M_PI_2		1.57079632679489661923	/* pi/2 */
#define M_PI_4		0.78539816339744830962	/* pi/4 */
#define M_1_PI		0.31830988618379067154	/* 1/pi */
#define M_2_PI		0.63661977236758134308	/* 2/pi */
#define M_2_SQRTPI	1.12837916709551257390	/* 2/sqrt(pi) */
#define M_SQRT2	    1.41421356237309504880	/* sqrt(2) */
#define M_SQRT1_2	0.70710678118654752440	/* 1/sqrt(2) */

#define M_Ef		2.7182818284590452354f	/* e */
#define M_LOG2Ef	1.4426950408889634074f	/* log_2 e */
#define M_LOG10Ef	0.43429448190325182765f	/* log_10 e */
#define M_LN2f		0.69314718055994530942f	/* log_e 2 */
#define M_LN10f	    2.30258509299404568402f	/* log_e 10 */
#define M_PIf		3.14159265358979323846f	/* pi */
#define M_PI_2f	    1.57079632679489661923f	/* pi/2 */
#define M_PI_4f	    0.78539816339744830962f	/* pi/4 */
#define M_1_PIf	    0.31830988618379067154f	/* 1/pi */
#define M_2_PIf	    0.63661977236758134308f	/* 2/pi */
#define M_2_SQRTPIf	1.12837916709551257390f	/* 2/sqrt(pi) */
#define M_SQRT2f	1.41421356237309504880f	/* sqrt(2) */
#define M_SQRT1_2f	0.70710678118654752440f	/* 1/sqrt(2) */


__attribute__((import_name("js_abs")))
extern double js_abs(double);
__attribute__((import_name("js_acos")))
extern double js_acos(double);
__attribute__((import_name("js_acosh")))
extern double js_acosh(double);
__attribute__((import_name("js_asin")))
extern double js_asin(double);
__attribute__((import_name("js_asinh")))
extern double js_asinh(double);
__attribute__((import_name("js_atan")))
extern double js_atan(double);
__attribute__((import_name("js_atanh")))
extern double js_atanh(double);
__attribute__((import_name("js_atan2")))
extern double js_atan2(double, double);
__attribute__((import_name("js_cbrt")))
extern double js_cbrt(double);
__attribute__((import_name("js_ceil")))
extern double js_ceil(double);
__attribute__((import_name("js_cos")))
extern double js_cos(double);
__attribute__((import_name("js_cosh")))
extern double js_cosh(double);
__attribute__((import_name("js_exp")))
extern double js_exp(double);
__attribute__((import_name("js_expm1")))
extern double js_expm1(double);
__attribute__((import_name("js_floor")))
extern double js_floor(double);
__attribute__((import_name("js_log")))
extern double js_log(double);
__attribute__((import_name("js_log1p")))
extern double js_log1p(double);
__attribute__((import_name("js_log10")))
extern double js_log10(double);
__attribute__((import_name("js_log2")))
extern double js_log2(double);
__attribute__((import_name("js_max")))
extern double js_max(double);
__attribute__((import_name("js_min")))
extern double js_min(double);
__attribute__((import_name("js_pow")))
extern double js_pow(double, double);
__attribute__((import_name("js_random")))
extern double js_random();
__attribute__((import_name("js_round")))
extern double js_round(double);
__attribute__((import_name("js_sign")))
extern double js_sign(double);
__attribute__((import_name("js_sin")))
extern double js_sin(double);
__attribute__((import_name("js_sinh")))
extern double js_sinh(double);
__attribute__((import_name("js_sqrt")))
extern double js_sqrt(double);
__attribute__((import_name("js_tan")))
extern double js_tan(double);
__attribute__((import_name("js_tanh")))
extern double js_tanh(double);

#endif //__JSMATH_H__
