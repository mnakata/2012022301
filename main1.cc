#include <iostream>
#include <vector>
#include <string>


class EllysDirectoryListing {
public:
  std::vector<std::string> getFiles(std::vector<std::string> files);
};

std::vector<std::string> EllysDirectoryListing::getFiles(std::vector<std::string> files)
{
  int n = files.size();

  if (files[n - 2] == "." && files[n - 1] == "..")
    return files;

  if (files[n - 2] == ".." && files[n - 1] == ".")
    return files;

  for (int i = 0; i < n; i ++)
    if (files[i] == "." || files[i] == "..") {
      std::swap(files[i], files[n - 1]);
      break;
    }

  if (files[n - 2] == "." && files[n - 1] == "..")
    return files;

  if (files[n - 2] == ".." && files[n - 1] == ".")
    return files;

  for (int i = 0; i < n; i ++)
    if (files[i] == "." || files[i] == "..") {
      std::swap(files[i], files[n - 2]);
      break;
    }

  return files;
}

int main(int argc, char** argv)
{
  int n;

  std::cin >> n;

  std::vector<std::string> files;

  for (int i = 0; i < n; i ++) {
    std::string s;

    std::cin >> s;

    files.push_back(s);
  }

  files = EllysDirectoryListing().getFiles(files);

  for (std::vector<std::string>::iterator it = files.begin(); it != files.end(); ++ it)
    std::cout << *it << std::endl;
}
