#pragma once

#include <memory>
#include <string>
#include <vector>

#include "../component/ComponentIf.h"

namespace core
{
class FactoryIf
{
   public:
    virtual std::shared_ptr< ComponentIf > create( std::string const &name ) const = 0;
    virtual void cleanup( std::string const &name ) const = 0;
    virtual std::string getType() const = 0;
    virtual std::vector< std::string > getDependencies() const = 0;
};

}
