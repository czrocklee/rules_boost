#include <boost/dll.hpp>
#include <boost/core/ignore_unused.hpp>

int main()
{
  try
  {
    boost::dll::shared_library lib("a_library_should_never_exists");
    int plugin_constant = lib.get<const int>("integer_variable");
    auto f = lib.get<int()>("function_returning_int");
    int& i = lib.get_alias<int>("alias_to_int_variable");
    boost::ignore_unused(plugin_constant, f, i);
  }
  catch (const std::exception&)
  {
    return EXIT_SUCCESS;
  }

  return EXIT_FAILURE;
}
