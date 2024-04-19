module;

#include <exception>

export module Eqx.Stdm.Utils.Exception;

export namespace stdm
{
    // Types
    using std::exception;
    using std::nested_exception;
    using std::bad_exception;
    using std::terminate_handler;
    using std::exception_ptr;

    // Functions
    using std::make_exception_ptr;
    using std::current_exception;
    using std::rethrow_exception;
    using std::throw_with_nested;
    using std::rethrow_if_nested;
    using std::terminate;
    using std::get_terminate;
    using std::set_terminate;
}
