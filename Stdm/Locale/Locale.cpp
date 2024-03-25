module;

#include <locale>

export module Stdm.Locale.Locale;

export namespace stdm
{
    // Classes
    using std::locale;

    // Facet Category Base Classes
    using std::ctype_base;
    using std::codecvt_base;
    using std::messages_base;
    using std::time_base;
    using std::money_base;

    // Facet Categories
    using std::ctype;
    using std::codecvt;
    using std::collate;
    using std::messages;
    using std::time_get;
    using std::time_put;
    using std::num_get;
    using std::num_put;
    using std::numpunct;
    using std::money_get;
    using std::money_put;
    using std::moneypunct;

    // Locale-Specific Facet Categories
    using std::ctype_byname;
    using std::codecvt_byname;
    using std::messages_byname;
    using std::collate_byname;
    using std::time_get_byname;
    using std::time_put_byname;
    using std::numpunct_byname;
    using std::moneypunct_byname;

    // Locales And Facets
    using std::use_facet;
    using std::has_facet;

    // Character Classification
    using std::isspace;
    using std::isblank;
    using std::iscntrl;
    using std::isupper;
    using std::islower;
    using std::isalpha;
    using std::isdigit;
    using std::ispunct;
    using std::isxdigit;
    using std::isalnum;
    using std::isprint;
    using std::isgraph;

    // Character Conversions
    using std::toupper;
    using std::tolower;
}
