#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <vector>

class Application
{
public:
    virtual ~Application(){}

    using Ptr = std::shared_ptr<Application>;
    using ArgName = std::string;
    using ArgValue = std::string;
    using Argument = std::pair<ArgName, ArgValue>;
    using Arguments = std::vector<Argument>;

    virtual bool Init(const Arguments& args) = 0;
    virtual void Update() = 0;
protected:

};

#endif // APPLICATION_H
