#include "component/ComponentController.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <utility>

#include "factory/FactoryController.h"

namespace core
{
std::map< std::string, std::map< std::string, std::shared_ptr< ComponentIf > > > ComponentController::components;

ComponentController::ComponentController() : ComponentController( std::make_shared< FactoryController >() )
{
}

ComponentController::ComponentController( std::shared_ptr< FactoryControllerIf > const &_factoryController ) : factoryController( _factoryController )
{
}

void ComponentController::create( std::string const &type, std::string const &name )
{
    std::shared_ptr< FactoryIf > factory = factoryController->get( type );

    std::shared_ptr< ComponentIf > component = factory->create( name );

    components.insert( std::make_pair( type, std::map< std::string, std::shared_ptr< ComponentIf > >() ) );
    components[ type ].insert( std::make_pair( name, component ) );
}

std::shared_ptr< ComponentIf > ComponentController::get( std::string const &type, std::string const &name ) const
{
    std::shared_ptr< ComponentIf > result( nullptr );

    try
    {
        result = components.at( type ).at( name );
    }
    catch ( const std::out_of_range &oor )
    {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }

    return result;
}

std::map< std::string, std::shared_ptr< ComponentIf > > ComponentController::get( std::string const &type ) const
{
    std::map< std::string, std::shared_ptr< ComponentIf > > result;

    try
    {
        result = components.at( type );
    }
    catch ( const std::out_of_range &oor )
    {
        std::cerr << "Out of Range error: " << oor.what() << " ComponentController::get"
                  << "type: " << type << '\n';
    }

    return result;
}

void ComponentController::erase( std::string const &type, std::string const &name )
{
    std::cout << "ComponentController::erase type: " << type << "name: " << name << std::endl;

    std::shared_ptr< FactoryIf > factory = factoryController->get( type );
    factory->cleanup( name );

    try
    {
        components.at( type ).at( name ).reset();
        components.at( type ).erase( name );

        if ( true == components.at( type ).empty() )
        {
            components.erase( type );
        }
    }
    catch ( const std::out_of_range &oor )
    {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
}

void ComponentController::erase( std::string const &type )
{
    auto first = components.at( type ).begin();
    auto last = components.at( type ).end();

    auto destroy = [ this ]( auto &componentPair ) { destroyComponentPair( componentPair ); };

    std::for_each( first, last, destroy );

    components.erase( type );
}

void ComponentController::destroyComponentPair( std::pair< std::string, std::shared_ptr< ComponentIf > > componentPair )
{
    auto const type = componentPair.second->getType();
    auto const name = componentPair.first;

    std::shared_ptr< FactoryIf > factory = factoryController->get( type );
    factory->cleanup( name );

    componentPair.second.reset();
}

void ComponentController::list() const
{
    std::cout << "ComponentController::list" << std::endl;

    for ( auto const &[ type, componentsSameType ] : components )
    {
        std::cout << std::endl << "type: " << type << std::endl;

        for ( auto const &[ name, component ] : componentsSameType )
        {
            std::cout << "name: " << name << std::endl;
        }
    }

    std::cout << std::endl;
}
}
