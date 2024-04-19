module;

#include <random>

export module Eqx.Stdm.Numerics.Random;

export namespace stdm
{
    // Uniform Random Bit Generator Requirements
    using std::uniform_random_bit_generator;

    // Random Number Engines
    using std::linear_congruential_engine;
    using std::mersenne_twister_engine;
    using std::subtract_with_carry_engine;

    // Random Number Engine Adaptors
    using std::discard_block_engine;
    using std::independent_bits_engine;
    using std::shuffle_order_engine;

    // Predefined Generators
    using std::minstd_rand0;
    using std::minstd_rand;
    using std::mt19937;
    using std::mt19937_64;
    using std::ranlux24_base;
    using std::ranlux48_base;
    using std::ranlux24;
    using std::ranlux48;
    using std::knuth_b;
    using std::default_random_engine;

    // Non-Deterministic Random Numbers
    using std::random_device;

    // Uniform Distributions
    using std::uniform_int_distribution;
    using std::uniform_real_distribution;

    // Bernoulli Distributions
    using std::bernoulli_distribution;
    using std::binomial_distribution;
    using std::negative_binomial_distribution;
    using std::geometric_distribution;

    // Poisson Distributions
    using std::poisson_distribution;
    using std::exponential_distribution;
    using std::gamma_distribution;
    using std::weibull_distribution;
    using std::extreme_value_distribution;

    // Normal Distributions
    using std::normal_distribution;
    using std::lognormal_distribution;
    using std::chi_squared_distribution;
    using std::cauchy_distribution;
    using std::fisher_f_distribution;
    using std::student_t_distribution;

    // Sampling Distributions
    using std::discrete_distribution;
    using std::piecewise_constant_distribution;
    using std::piecewise_linear_distribution;

    // Utilities
    using std::seed_seq;

    // Functions
    using std::generate_canonical;
}
