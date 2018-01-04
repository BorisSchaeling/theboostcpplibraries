#include <boost/program_options.hpp>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace boost::program_options;

void to_cout(const std::vector<std::string> &v)
{
  std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>{
    std::cout, "\n"});
}

int main(int argc, const char *argv[])
{
  try
  {
    int age;

    options_description desc{"Options"};
    desc.add_options()
      ("help,h", "Help screen")
      ("pi", value<float>()->implicit_value(3.14f), "Pi")
      ("age", value<int>(&age), "Age")
      ("phone", value<std::vector<std::string>>()->multitoken()->
        zero_tokens()->composing(), "Phone")
      ("unreg", "Unrecognized options");

    command_line_parser parser{argc, argv};
    parser.options(desc).allow_unregistered().style(
      command_line_style::default_style |
      command_line_style::allow_slash_for_short);
    parsed_options parsed_options = parser.run();

    variables_map vm;
    store(parsed_options, vm);
    notify(vm);

    if (vm.count("help"))
      std::cout << desc << '\n';
    else if (vm.count("age"))
      std::cout << "Age: " << age << '\n';
    else if (vm.count("phone"))
      to_cout(vm["phone"].as<std::vector<std::string>>());
    else if (vm.count("unreg"))
      to_cout(collect_unrecognized(parsed_options.options,
        exclude_positional));
    else if (vm.count("pi"))
      std::cout << "Pi: " << vm["pi"].as<float>() << '\n';
  }
  catch (const error &ex)
  {
    std::cerr << ex.what() << '\n';
  }
}