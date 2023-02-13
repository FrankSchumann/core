#pragma once

#include <map>
#include <string>
#include <vector>

#include "Plugin.h"

namespace core
{
class PluginController
{
   public:
    PluginController( std::string const &_folder );

    void loadPlugins();
    void loadPlugin( std::string const &plugin ) const;

    void closePlugins() const;
    void closePlugin( std::string const &plugin ) const;

    void list() const;

   private:
    static std::map< std::string, std::shared_ptr< Plugin > > plugins;

    std::string folder;
};

}