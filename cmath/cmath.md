### source

```
https://cplusplus.com/reference/cmath/
```


### Trigonometric Functions
***
* **`sin(x)`**
    Computes the sine of an angle `x` in radians. It returns a floating-point value between $-1$ and $1$.
* **`cos(x)`**
    Computes the cosine of an angle `x` in radians. It returns a floating-point value between $-1$ and $1$.
* **`tan(x)`**
    Computes the tangent of an angle `x` in radians. The tangent is the ratio of the sine to the cosine of the angle.
* **`asin(x)`**
    Computes the arcsine (inverse sine) of `x`. It returns an angle in radians in the range $[-\pi/2, \pi/2]$.
* **`acos(x)`**
    Computes the arccosine (inverse cosine) of `x`. It returns an angle in radians in the range $[0, \pi]$.
* **`atan(x)`**
    Computes the arctangent (inverse tangent) of `x`. It returns an angle in radians in the range $(-\pi/2, \pi/2)$.
* **`atan2(y, x)`**
    Computes the arctangent of `y/x` using the signs of both arguments to determine the correct quadrant. It returns an angle in radians in the range $[-\pi, \pi]$.

***
### Hyperbolic Functions
***
* **`sinh(x)`**
    Computes the hyperbolic sine of `x`. It's defined as $\frac{e^x - e^{-x}}{2}$.
* **`cosh(x)`**
    Computes the hyperbolic cosine of `x`. It's defined as $\frac{e^x + e^{-x}}{2}$.
* **`tanh(x)`**
    Computes the hyperbolic tangent of `x`. It's defined as $\frac{sinh(x)}{cosh(x)}$.
* **`asinh(x)`**
    Computes the inverse hyperbolic sine of `x`. It returns a floating-point value.
* **`acosh(x)`**
    Computes the inverse hyperbolic cosine of `x`. It returns a floating-point value in the range $[0, \infty)$.
* **`atanh(x)`**
    Computes the inverse hyperbolic tangent of `x`. The input `x` must be in the range $(-1, 1)$.

***
### Exponential and Logarithmic Functions
***
* **`exp(x)`**
    Computes the base-e exponential of `x`, i.e., $e^x$.
* **`exp2(x)`**
    Computes the base-2 exponential of `x`, i.e., $2^x$.
* **`log(x)`**
    Computes the natural (base-e) logarithm of `x`. The input `x` must be greater than zero.
* **`log10(x)`**
    Computes the base-10 logarithm of `x`. The input `x` must be greater than zero.
* **`log2(x)`**
    Computes the base-2 logarithm of `x`. The input `x` must be greater than zero.
* **`log1p(x)`**
    Computes the natural logarithm of $1 + x$. This can be more accurate for small values of $x$.

***
### Power and Absolute Value Functions
***
* **`pow(base, exp)`**
    Computes the value of `base` raised to the power of `exp`, i.e., $base^{exp}$.
* **`sqrt(x)`**
    Computes the square root of `x`. The input `x` must be non-negative.
* **`cbrt(x)`**
    Computes the cubic root of `x`, i.e., $\sqrt[3]{x}$.
* **`hypot(x, y)`**
    Computes the hypotenuse of a right-angled triangle with sides `x` and `y`, i.e., $\sqrt{x^2 + y^2}$.
* **`abs(x)`**
    Returns the absolute value of `x`. Note: a version of `abs` for floating-point types is also in `<cstdlib>`.
* **`fabs(x)`**
    Returns the absolute value of `x` for floating-point types. It is functionally identical to `abs` for these types.

***
### Rounding, Remainder, and Floating-Point Functions
***
* **`ceil(x)`**
    Computes the smallest integer value not less than `x`. It effectively rounds a number up to the nearest integer.
* **`floor(x)`**
    Computes the largest integer value not greater than `x`. It effectively rounds a number down to the nearest integer.
* **`trunc(x)`**
    Computes the integral part of `x` by truncating the fractional part. It rounds towards zero.
* **`round(x)`**
    Computes the nearest integer value to `x`. It rounds half-way cases away from zero.
* **`fmod(x, y)`**
    Computes the floating-point remainder of `x / y`. The result has the same sign as `x`.
* **`remainder(x, y)`**
    Computes the floating-point remainder of `x / y` as defined by the IEEE 754 standard. The result is always between $-y/2$ and $y/2$.
* **`modf(x, iptr)`**
    Breaks a floating-point number into its integral and fractional parts. The fractional part is returned and the integral part is stored in the location pointed to by `iptr`.

***
### Error, Gamma, and Special Functions
***
* **`erf(x)`**
    Computes the error function of `x`. It is used in statistics and probability theory.
* **`erfc(x)`**
    Computes the complementary error function of `x`. It is defined as $1 - erf(x)$ and is more accurate for large `x`.
* **`tgamma(x)`**
    Computes the gamma function of `x`, $\Gamma(x)$. This is an extension of the factorial function to real and complex numbers.
* **`lgamma(x)`**
    Computes the natural logarithm of the absolute value of the gamma function of `x`. It is useful for avoiding overflow with large `x`.

***
### Classification and Comparison Functions
***
* **`isinf(x)`**
    Checks if `x` is an infinite value. It returns `true` if `x` is positive or negative infinity.
* **`isnan(x)`**
    Checks if `x` is "Not a Number" (NaN). It returns `true` if `x` cannot be represented as a valid floating-point number.
* **`isnormal(x)`**
    Checks if `x` is a normal floating-point number. It returns `true` for numbers that are not zero, subnormal, infinite, or NaN.
* **`isfinite(x)`**
    Checks if `x` is a finite value. It returns `true` if `x` is not an infinity or NaN.
* **`signbit(x)`**
    Checks the sign of the floating-point number `x`. It returns `true` if the sign bit of `x` is set.
* **`isgreater(x, y)`**
    Checks if `x > y`. This is a macro that avoids issues with NaN values.
* **`isless(x, y)`**
    Checks if `x < y`. Similar to `isgreater`, it handles NaN values properly.


```

#include <iostream>
#include <cmath>     // Required for all mathematical functions
#include <stdexcept> // For catching exceptions (not strictly necessary for cmath but good practice)

// This program demonstrates the usage of various functions from the <cmath> header.
// All explanations are provided directly within the comments of the code.

int main() {
    // A constant for π (pi)
    const double PI = 3.14159265358979323846;
    double x = 0.5;
    double y = 1.0;

    std::cout << "--- Part 1: Trigonometric Functions ---\n";
    std::cout << "Input angle (in radians): " << PI / 6 << "\n";
    // sin(x) - Computes the sine of an angle in radians.
    std::cout << "sin(PI/6) = " << std::sin(PI / 6) << "\n"; // Should be approximately 0.5
    // cos(x) - Computes the cosine of an angle in radians.
    std::cout << "cos(PI/6) = " << std::cos(PI / 6) << "\n"; // Should be approximately 0.866
    // tan(x) - Computes the tangent of an angle in radians.
    std::cout << "tan(PI/6) = " << std::tan(PI / 6) << "\n"; // Should be approximately 0.577

    std::cout << "Input value (x): " << x << "\n";
    // asin(x) - Computes the arcsine (inverse sine) of x, returning an angle in radians.
    std::cout << "asin(" << x << ") = " << std::asin(x) << " radians\n";
    // acos(x) - Computes the arccosine (inverse cosine) of x, returning an angle in radians.
    std::cout << "acos(" << x << ") = " << std::acos(x) << " radians\n";
    // atan(x) - Computes the arctangent (inverse tangent) of x, returning an angle in radians.
    std::cout << "atan(" << x << ") = " << std::atan(x) << " radians\n";
    // atan2(y, x) - Computes the arctangent of y/x, using both arguments to determine the quadrant.
    std::cout << "atan2(" << y << ", " << x << ") = " << std::atan2(y, x) << " radians\n\n";

    std::cout << "--- Part 2: Hyperbolic Functions ---\n";
    std::cout << "Input value (x): " << x << "\n";
    // sinh(x) - Computes the hyperbolic sine of x.
    std::cout << "sinh(" << x << ") = " << std::sinh(x) << "\n";
    // cosh(x) - Computes the hyperbolic cosine of x.
    std::cout << "cosh(" << x << ") = " << std::cosh(x) << "\n";
    // tanh(x) - Computes the hyperbolic tangent of x.
    std::cout << "tanh(" << x << ") = " << std::tanh(x) << "\n";
    // asinh(x) - Computes the inverse hyperbolic sine of x.
    std::cout << "asinh(" << x << ") = " << std::asinh(x) << "\n\n";

    std::cout << "--- Part 3: Exponential and Logarithmic Functions ---\n";
    std::cout << "Input value (x): " << x << "\n";
    // exp(x) - Computes e raised to the power of x.
    std::cout << "exp(" << x << ") = " << std::exp(x) << "\n";
    // log(x) - Computes the natural (base-e) logarithm of x.
    std::cout << "log(" << x << ") = " << std::log(x) << "\n";
    // log10(x) - Computes the base-10 logarithm of x.
    std::cout << "log10(" << 100 << ") = " << std::log10(100) << "\n";
    // log2(x) - Computes the base-2 logarithm of x.
    std::cout << "log2(" << 8 << ") = " << std::log2(8) << "\n\n";

    std::cout << "--- Part 4: Power and Absolute Value Functions ---\n";
    double base = 2.0;
    double exponent = 3.0;
    // pow(base, exp) - Computes base raised to the power of exp.
    std::cout << "pow(" << base << ", " << exponent << ") = " << std::pow(base, exponent) << "\n";
    double val_sqrt = 9.0;
    // sqrt(x) - Computes the square root of x.
    std::cout << "sqrt(" << val_sqrt << ") = " << std::sqrt(val_sqrt) << "\n";
    double val_cbrt = 27.0;
    // cbrt(x) - Computes the cubic root of x.
    std::cout << "cbrt(" << val_cbrt << ") = " << std::cbrt(val_cbrt) << "\n";
    double side_a = 3.0, side_b = 4.0;
    // hypot(x, y) - Computes the hypotenuse of a right triangle with sides x and y.
    std::cout << "hypot(" << side_a << ", " << side_b << ") = " << std::hypot(side_a, side_b) << "\n";
    double negative_val = -10.5;
    // abs(x) and fabs(x) - Return the absolute value of x.
    std::cout << "abs(" << negative_val << ") = " << std::abs(negative_val) << "\n\n";

    std::cout << "--- Part 5: Rounding, Remainder, and Floating-Point Functions ---\n";
    double rounding_val = 5.7;
    // ceil(x) - Rounds up to the nearest integer.
    std::cout << "ceil(" << rounding_val << ") = " << std::ceil(rounding_val) << "\n";
    // floor(x) - Rounds down to the nearest integer.
    std::cout << "floor(" << rounding_val << ") = " << std::floor(rounding_val) << "\n";
    double rounding_val2 = -5.7;
    // trunc(x) - Truncates the fractional part, rounding towards zero.
    std::cout << "trunc(" << rounding_val2 << ") = " << std::trunc(rounding_val2) << "\n";
    // round(x) - Rounds to the nearest integer, half-way cases away from zero.
    std::cout << "round(" << rounding_val << ") = " << std::round(rounding_val) << "\n";
    double dividend = 10.5, divisor = 3.2;
    // fmod(x, y) - Computes the floating-point remainder of x/y.
    std::cout << "fmod(" << dividend << ", " << divisor << ") = " << std::fmod(dividend, divisor) << "\n";
    // remainder(x, y) - Computes the remainder as per IEEE 754.
    std::cout << "remainder(" << dividend << ", " << divisor << ") = " << std::remainder(dividend, divisor) << "\n";
    double integral_part;
    // modf(x, iptr) - Breaks a number into integral and fractional parts.
    double fractional_part = std::modf(3.14, &integral_part);
    std::cout << "modf(3.14): Integral part = " << integral_part << ", Fractional part = " << fractional_part << "\n\n";

    std::cout << "--- Part 6: Classification Functions ---\n";
    double inf = INFINITY;
    double nan = NAN;
    double norm = 1.0;
    // isinf(x) - Checks if x is infinite.
    std::cout << "Is " << inf << " infinite? " << std::boolalpha << std::isinf(inf) << "\n";
    // isnan(x) - Checks if x is a "Not a Number".
    std::cout << "Is " << nan << " NaN? " << std::boolalpha << std::isnan(nan) << "\n";
    // isnormal(x) - Checks if x is a normal floating-point number.
    std::cout << "Is " << norm << " normal? " << std::boolalpha << std::isnormal(norm) << "\n";
    // isfinite(x) - Checks if x is a finite value.
    std::cout << "Is " << inf << " finite? " << std::boolalpha << std::isfinite(inf) << "\n\n";
    
    return 0;
}

```