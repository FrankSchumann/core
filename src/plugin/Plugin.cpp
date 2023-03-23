#include "plugin/Plugin.h"

#include <dlfcn.h>

#include <iostream>

Plugin::Plugin( std::filesystem::path const& _file ) : file( _file )
{
}

void Plugin::load()
{
    std::cout << "Plugin::load file: " << file.string() << std::endl;

    typedef void ( *subscribeFunctionType )();

    //   handle = dlopen( file.string().c_str(), RTLD_GLOBAL );
    handle = dlopen( file.string().c_str(), RTLD_LAZY );

    if ( nullptr != handle )
    {
        receiveName();
        receiveVersion();
        subscribe();
    }
    else
    {
        char* errormessage = dlerror();

        std::cout << "errormessage: " << errormessage << std::endl;
    }
}

void Plugin::close() const
{
    std::cout << "Plugin::close file: " << file.string() << std::endl;

    unsubscribe();

    dlclose( handle );
}

std::string Plugin::getName() const
{
    return name;
}

void Plugin::show() const
{
    std::cout << std::left << std::setw(20) << name << std::setw(15) << version << file.string() << std::endl;
}

void Plugin::receiveVersion()
{
    receiveString( std::string( "getVersion" ), version );
}

void Plugin::receiveName()
{
    receiveString( std::string( "getName" ), name );
}

void Plugin::receiveString( std::string const& functionName, std::string& destination ) const
{
    typedef const char* ( *getStringFunctionType )();
    void* getStringFunctionSymbol = dlsym( handle, functionName.c_str() );

    if ( nullptr != getStringFunctionSymbol )
    {
        getStringFunctionType getStringFunction = ( getStringFunctionType )getStringFunctionSymbol;

        const char* stringTmp = getStringFunction();
        destination.assign( stringTmp );
    }
}

void Plugin::subscribe() const
{
    callPluginFunction( "subscribePlugin" );
}

void Plugin::unsubscribe() const
{
    callPluginFunction( "unsubscribePlugin" );
}

void Plugin::callPluginFunction( std::string const& function ) const
{
    typedef void ( *functionType )();
    void* functionSymbol = dlsym( handle, function.c_str() );

    if ( nullptr != functionSymbol )
    {
        functionType function = ( functionType )functionSymbol;

        function();
    }
}
