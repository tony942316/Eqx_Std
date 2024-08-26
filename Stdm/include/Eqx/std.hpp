#ifdef __clang__

import <bits/stdc++.h>;

#endif // __clang__

#ifdef _MSC_VER

// Algorithms
import <algorithm>;
import <numeric>;

// Concepts
import <concepts>;

// Concurrency
import <atomic>;
import <barrier>;
import <condition_variable>;
import <future>;
import <latch>;
import <mutex>;
import <semaphore>;
import <thread>;

// Containers
import <array>;
import <deque>;
import <forward_list>;
import <list>;
import <map>;
import <queue>;
import <set>;
import <span>;
import <stack>;
import <unordered_map>;
import <unordered_set>;
import <vector>;

// IO
import <filesystem>;
import <fstream>;
import <iomanip>;
import <ios>;
import <iostream>;
import <istream>;
import <ostream>;
import <sstream>;

// Iterator
import <iterator>;

// Locale
import <locale>;

// Meta
import <type_traits>;

// Numerics
import <cmath>;
import <complex>;
import <numbers>;
import <random>;

// Ranges
import <ranges>;

// Strings
import <string>;
import <string_view>;

// Time
import <chrono>;

// Utils
import <bit>;
import <compare>;
import <cstddef>;
import <cstdint>;
import <cstdlib>;
import <exception>;
import <execution>;
import <functional>;
import <initializer_list>;
import <limits>;
import <optional>;
import <source_location>;
import <utility>;

#endif // _MSC_VER

#if !defined(__clang__) && defined(__GNUC___)

#error No GCC Implementation

#endif // __GNUC__
