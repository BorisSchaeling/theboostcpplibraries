#include <boost/program_options.hpp>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace boost::program_options;

void to_cout(const std::vector<std::string> &v)
{
  std::copy(v.begin(), v.end(),
    std::ostream_iterator<std::string>{std::cout, "\n"});
}

int main(int argc, const char *argv[])
{
  try
  {
    options_description desc{"Options"};
    desc.add_options()
      ("help,h", "Help screen")
      ("phone", value<std::vector<std::string>>()->
        multitoken()->zero_tokens()->composing(), "Phone");

    positional_options_description pos_desc;
    pos_desc.add("phone", -1);

    command_line_parser parser{argc, argv};
    parser.options(desc).positional(pos_desc).allow_unregistered();
    parsed_options parsed_options = parser.run();

    variables_map vm;
    store(parsed_options, vm);
    notify(vm);

    if (vm.count("help"))
      std::cout << desc << '\n';
    else if (vm.count("phone"))
      to_cout(vm["phone"].as<std::vector<std::string>>());
  }
  catch (const error &ex)
  {
    std::cerr << ex.what() << '\n';
  }
}