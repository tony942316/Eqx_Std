module;

#include <string>

export module Eqx.Stdm.Strings.String;

// Functions
export using std::operator+;
export using std::operator==;
export using std::operator<=>;

// Input/Output
export using std::operator<<;
export using std::operator>>;

// Literals
export using std::operator""s;

export namespace stdm
{
    // Classes
    using std::basic_string;
    using std::string;
    using std::u8string;
    using std::u16string;
    using std::u32string;
    using std::wstring;

    // Functions
    using std::swap;
    using std::erase;
    using std::erase_if;

    // Input/Output
    using std::getline;

    // Numeric Conversions
    using std::stoi;
    using std::stol;
    using std::stoll;
    using std::stoul;
    using std::stoull;
    using std::stof;
    using std::stod;
    using std::stold;
    using std::to_string;
    using std::to_wstring;

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
