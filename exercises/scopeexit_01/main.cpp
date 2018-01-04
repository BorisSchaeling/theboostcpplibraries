#include <string>
#include <memory>
#include <cstdio>

struct CloseFile
{
    void operator()(std::FILE *file)
    {
        std::fclose(file);
    }
};

void write_to_file(const std::string &s)
{
    std::unique_ptr<std::FILE, CloseFile> file{
      std::fopen("hello-world.txt", "a") };
    std::fprintf(file.get(), s.c_str());
}

int main()
{
    write_to_file("Hello, ");
    write_to_file("world!");
}
