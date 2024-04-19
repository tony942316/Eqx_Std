module;

#include <complex>

export module Eqx.Stdm.Numerics.Complex;

// Operators
using std::operator+;
using std::operator-;
using std::operator*;
using std::operator/;
using std::operator==;
using std::operator<<;
using std::operator>>;
using std::operator""if;
using std::operator""i;
using std::operator""il;

export namespace stdm
{
    // Classes
    using std::complex;

    // Functions
    using std::real;
    using std::imag;
    using std::abs;
    using std::arg;
    using std::norm;
    using std::conj;
    using std::proj;
    using std::polar;

    // Exponential Functions
    using std::exp;
    using std::log;
    using std::log10;

    // Power Functions
    using std::pow;
    using std::sqrt;

    // Trigonometric Functions
    using std::sin;
    using std::cos;
    using std::tan;
    using std::asin;
    using std::acos;
    using std::atan;

    // Hyperbolic Functions
    using std::sinh;
    using std::cosh;
    using std::tanh;
    using std::asinh;
    using std::acosh;
    using std::atanh;
}
