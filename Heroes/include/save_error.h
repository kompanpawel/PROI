#ifndef SAVE_ERROR_H
#define SAVE_ERROR_H

#include <string>
class save_error
{
    std::string except;
    public:
    save_error(): except{"error while saving"} {}
    save_error(std::string except_): except{except_} {}
    std::string what() {return except;}
};

#endif // SAVE_ERROR_H
