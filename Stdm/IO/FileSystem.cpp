module;

#include <filesystem>

export module Eqx.Stdm.IO.FileSystem;

export namespace stdm
{
    // Classes
    using std::hash;
}

export namespace stdm::filesystem
{
    // Classes
    using std::filesystem::path;
    using std::filesystem::filesystem_error;
    using std::filesystem::directory_entry;
    using std::filesystem::directory_iterator;
    using std::filesystem::recursive_directory_iterator;
    using std::filesystem::file_status;
    using std::filesystem::space_info;
    using std::filesystem::file_type;
    using std::filesystem::perms;
    using std::filesystem::perm_options;
    using std::filesystem::copy_options;
    using std::filesystem::directory_options;
    using std::filesystem::file_time_type;

    // Functions
    using std::filesystem::absolute;
    using std::filesystem::canonical;
    using std::filesystem::weakly_canonical;
    using std::filesystem::relative;
    using std::filesystem::proximate;
    using std::filesystem::copy;
    using std::filesystem::copy_file;
    using std::filesystem::copy_symlink;
    using std::filesystem::create_directory;
    using std::filesystem::create_directories;
    using std::filesystem::create_hard_link;
    using std::filesystem::create_symlink;
    using std::filesystem::create_directory_symlink;
    using std::filesystem::current_path;
    using std::filesystem::exists;
    using std::filesystem::equivalent;
    using std::filesystem::file_size;
    using std::filesystem::hard_link_count;
    using std::filesystem::last_write_time;
    using std::filesystem::permissions;
    using std::filesystem::read_symlink;
    using std::filesystem::remove;
    using std::filesystem::remove_all;
    using std::filesystem::rename;
    using std::filesystem::resize_file;
    using std::filesystem::space;
    using std::filesystem::status;
    using std::filesystem::symlink_status;
    using std::filesystem::temp_directory_path;

    // File Types
    using std::filesystem::is_block_file;
    using std::filesystem::is_character_file;
    using std::filesystem::is_directory;
    using std::filesystem::is_empty;
    using std::filesystem::is_fifo;
    using std::filesystem::is_other;
    using std::filesystem::is_regular_file;
    using std::filesystem::is_socket;
    using std::filesystem::is_symlink;
    using std::filesystem::status_known;
}

#ifdef __GLIBCXX__
export namespace std::filesystem
{
    stdm::filesystem::directory_iterator begin(
        stdm::filesystem::directory_iterator& iter) noexcept
    {
        return iter;
    }

    stdm::filesystem::directory_iterator end(
        [[maybe_unused]] stdm::filesystem::directory_iterator& iter) noexcept
    {
        return stdm::filesystem::directory_iterator{};
    }

    stdm::filesystem::recursive_directory_iterator begin(
        stdm::filesystem::recursive_directory_iterator& iter) noexcept
    {
        return iter;
    }

    stdm::filesystem::recursive_directory_iterator end(
        [[maybe_unused]] stdm::filesystem::recursive_directory_iterator& iter)
        noexcept
    {
        return stdm::filesystem::recursive_directory_iterator{};
    }
}
#endif // __GLIBCXX__
