#include <boost/program_options.hpp>
#include <string>
#include <fstream>
#include <iostream>

using namespace boost::program_options;

int main(int argc, const char *argv[])
{
  try
  {
    options_description generalOptions{"General"};
    generalOptions.add_options()
      ("help,h", "Help screen")
      ("config", value<std::string>(), "Config file");

    options_description fileOptions{"File"};
    fileOptions.add_options()
      ("age", value<int>(), "Age");

    variables_map vm;
    store(parse_command_line(argc, argv, generalOptions), vm);
    if (vm.count("config"))
    {
      std::ifstream ifs{vm["config"].as<std::string>().c_str()};
      if (ifs)
        store(parse_config_file(ifs, fileOptions), vm);
    }
    notify(vm);

    if (vm.count("help"))
      std::cout << generalOptions << '\n';
    else if (vm.count("age"))
      std::cout << "Your age is: " << vm["age"].as<int>() << '\n';
  }
  catch (const error &ex)
  {
    std::cerr << ex.what() << '\n';
  }
}