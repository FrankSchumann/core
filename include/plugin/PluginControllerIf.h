#pragma once

#include <string>

namespace core
{

class PluginControllerIf
{
   public:
    virtual void loadPlugins() = 0;
    virtual void loadPlugin( std::string const &plugin ) const = 0;

    virtual void closePlugins() const = 0;
    virtual void closePlugin( std::string const &plugin ) const = 0;

    virtual void list() const = 0;
};

}
