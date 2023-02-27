#pragma once

#include <map>
#include <string>
#include <vector>

#include "PluginControllerIf.h"
#include "Plugin.h"

namespace core
{
class PluginController : public PluginControllerIf
{
   public:
    PluginController( std::string const &_folder );

    void loadPlugins() override;
    void loadPlugin( std::string const &plugin ) const override;

    void closePlugins() const override;
    void closePlugin( std::string const &plugin ) const override;

    void list() const override;

   private:
    static std::map< std::string, std::shared_ptr< Plugin > > plugins;

    std::string folder;
};

}
