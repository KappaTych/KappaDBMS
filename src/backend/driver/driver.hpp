#include <string>

class Driver {
public:
    static Driver& Instance()
    {
        static Driver instance;
        return instance;
    }

    std::string handle(std::string) {};
private:
    Driver() = default;
};