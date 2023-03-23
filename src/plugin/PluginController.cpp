#include "plugin/PluginController.h"

#include <filesystem>
#include <iostream>

namespace core
{
std::map< std::string, std::shared_ptr< Plugin > > PluginController::plugins;

PluginController::PluginController( std::string const &_folder ) : folder( _folder )
{
}

void PluginController::loadPlugins()
{
    for ( auto &file : std::filesystem::recursive_directory_iterator( folder ) )
    {
        std::shared_ptr< Plugin > plugin = std::make_shared< Plugin >( file.path() );

        plugin->load();

        std::string const name = plugin->getName();

        plugins[ name ] = plugin;
    }
}

void PluginController::loadPlugin( std::string const &plugin ) const
{
}

void PluginController::closePlugins() const
{
    for ( auto const &[ name, plugin ] : plugins )
    {
        plugin->close();
        plugins.erase( name );
    }
}

void PluginController::closePlugin( std::string const &plugin ) const
{
    try
    {
        plugins.at( plugin )->close();

        plugins.erase( plugin );
    }

    catch ( const std::out_of_range &oor )
    {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
}

void PluginController::list() const
{
    std::cout << "PluginController::list" << std::endl;

    for ( auto const &[ name, plugin ] : plugins )
    {
        plugin->show();
    }

    std::cout << std::endl;
}

}
