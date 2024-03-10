module;

#include <string_view>

export module Stdm.Strings.String_View;

// Functions
export using std::operator==;
export using std::operator<=>;

// Input/Output
export using std::operator<<;

// Literals
export using std::operator""sv;

export namespace stdm
{
    // Classes
    using std::basic_string_view;
    using std::string_view;
    using std::u8string_view;
    using std::u16string_view;
    using std::u32string_view;
    using std::wstring_view;

    // Functions
    using std::swap;

    // Range Access
    using std::begin;
    using std::cbegin;
    using std::end;
    using std::cend;
    using std::rbegin;
    using std::crbegin;
    using std::rend;
    using std::crend;
    using std::size;
    using std::ssize;
    using std::empty;
    using std::data;
}
