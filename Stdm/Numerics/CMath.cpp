module;

#include <cmath>

export module Eqx.Stdm.Numerics.CMath;

export namespace stdm
{
    // Types
    using std::float_t;
    using std::double_t;

    // Macros
    inline constexpr auto Huge_ValF = HUGE_VALF;
    inline constexpr auto Huge_Val = HUGE_VAL;
    inline constexpr auto Huge_ValL = HUGE_VALL;
    inline constexpr auto Infinity = INFINITY;
    inline constexpr auto Nan = NAN;
    inline constexpr auto Fp_Normal = FP_NORMAL;
    inline constexpr auto Fp_Subnormal = FP_SUBNORMAL;
    inline constexpr auto Fp_Zero = FP_ZERO;
    inline constexpr auto Fp_Infinite = FP_INFINITE;
    inline constexpr auto Fp_Nan = FP_NAN;

    // Basic Operations
    using std::abs;
    using std::fabs;
    using std::fmod;
    using std::remainder;
    using std::remquo;
    using std::fma;
    using std::fmax;
    using std::fmin;
    using std::fdim;
    using std::nan;

    // Linear Interpolation
    using std::lerp;

    // Exponential Functions
    using std::exp;
    using std::exp2;
    using std::expm1;
    using std::log;
    using std::log10;
    using std::log2;
    using std::log1p;


    // Power Functions
    using std::pow;
    using std::sqrt;
    using std::cbrt;
    using std::hypot;

    // Trigonometric Functions
    using std::sin;
    using std::cos;
    using std::tan;
    using std::asin;
    using std::acos;
    using std::atan;
    using std::atan2;

    // Hyperbolic Functions
    using std::sinh;
    using std::cosh;
    using std::tanh;
    using std::asinh;
    using std::acosh;
    using std::atanh;

    // Error And Gamma Functions
    using std::erf;
    using std::erfc;
    using std::tgamma;
    using std::lgamma;

    // Nearest Integer Floating-Point Operations
    using std::ceil;
    using std::floor;
    using std::trunc;
    using std::round;
    using std::nearbyint;
    using std::rint;

    // Floating-Point Manipulation Functions
    using std::frexp;
    using std::ldexp;
    using std::modf;
    using std::scalbn;
    using std::ilogb;
    using std::logb;
    using std::nextafter;
    using std::nexttoward;
    using std::copysign;

    // Classification And Comparison
    using std::fpclassify;
    using std::isfinite;
    using std::isinf;
    using std::isnan;
    using std::isnormal;
    using std::signbit;
    using std::isgreater;
    using std::isgreaterequal;
    using std::isless;
    using std::islessequal;
    using std::islessgreater;
    using std::isunordered;

    // Mathematical Special Functions
    using std::assoc_laguerre;
    using std::assoc_legendre;
    using std::beta;
    using std::comp_ellint_1;
    using std::comp_ellint_2;
    using std::comp_ellint_3;
    using std::cyl_bessel_i;
    using std::cyl_bessel_j;
    using std::cyl_bessel_k;
    using std::cyl_neumann;
    using std::ellint_1;
    using std::ellint_2;
    using std::ellint_3;
    using std::expint;
    using std::hermite;
    using std::legendre;
    using std::laguerre;
    using std::riemann_zeta;
    using std::sph_bessel;
    using std::sph_legendre;
    using std::sph_neumann;
}
