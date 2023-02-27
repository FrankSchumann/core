#include "factory/FactoryController.h"

#include <iostream>

namespace core
{
std::map< std::string, std::shared_ptr< FactoryIf > > FactoryController::factories;

FactoryController::FactoryController()
{
}

void FactoryController::subscribe( std::shared_ptr< FactoryIf > const factory )
{
    std::cout << "FactoryController::subscribe " << factory->getType() << std::endl;

    std::string const type = factory->getType();

    factories[ type ] = factory;
}

void FactoryController::unsubscribe( std::string const &type )
{
    auto factory = get( type ); 

	factories.erase( type );

    factory = nullptr;
}

std::shared_ptr< FactoryIf > FactoryController::get( std::string const &type ) const
{
    std::shared_ptr< FactoryIf > result( nullptr );

    try
    {
        result = factories.at( type );
    }
    catch ( const std::out_of_range &oor )
    {
        std::cerr << "Out of Range error: " << oor.what() << " type: " << type << '\n';
    }

    return result;
}

void FactoryController::list() const
{
    std::cout << "FactoryController::list " << std::endl;

    for ( auto const &factory : factories )
    {
        std::cout << "Factory first: " << factory.first << " second " << factory.second->getType() << std::endl;
    }

    std::cout << std::endl;
}

}
