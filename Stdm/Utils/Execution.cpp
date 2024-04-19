module;

#include <execution>

export module Eqx.Stdm.Utils.Execution;

export namespace stdm
{
    // Classes
    using std::is_execution_policy;
    using std::is_execution_policy_v;
    using std::execution::sequenced_policy;
    using std::execution::parallel_policy;
    using std::execution::parallel_unsequenced_policy;
    using std::execution::unsequenced_policy;
}

export namespace stdm::execution
{
    // Classes
    using std::execution::sequenced_policy;
    using std::execution::parallel_policy;
    using std::execution::parallel_unsequenced_policy;
    using std::execution::unsequenced_policy;

    // Constants
    using std::execution::seq;
    using std::execution::par;
    using std::execution::par_unseq;
    using std::execution::unseq;
}
