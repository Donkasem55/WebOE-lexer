#include <string>
#include <vector>

#ifdef _WIN32
#define pathsplitter "\\"
#else
#define pathsplitter "/"
#endif

std::string path(std::vector<std::string> patharr) {
    std::string out = "";
    for (int i=0; i<sizeof(patharr); i++) {
        out.append(patharr.at(i));
        out.append(pathsplitter);
    }
    return out;
}