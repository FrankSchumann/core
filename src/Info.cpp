#include "Info.h"

#include <iostream>
#include <sstream>

#include "config.h"

namespace core
{

std::string Info::getVersion()
{
    return CORE_VERSION;
}

uint32_t Info::getMajorVersion()
{
    return CORE_VERSION_MAJOR;
}

uint32_t Info::getMinorVersion()
{
    return CORE_VERSION_MINOR;
}

uint32_t Info::getPatchVersion()
{
    return CORE_VERSION_PATCH;
}

uint32_t Info::getTweakVersion()
{
    return CORE_VERSION_TWEAK;
}

std::string Info::getName()
{
    return CORE_NAME;
}

std::string Info::getDescription()
{
    return CORE_DESCRIPTION;
}

std::string Info::getCompileMode()
{
#ifdef NDEBUG
    return std::string( "Release" );
#else
    return std::string( "Debug" );
#endif

    return std::string( "N/A" );
}

std::string Info::getArchitecture()
{
#ifdef _M_X64
    return std::string( "_M_X64" );
#endif

#ifdef _M_IX86
    return std::string( "_M_IX86" );
#endif

#ifdef _M_ARM64
    return std::string( "_M_ARM64" );
#endif

#if __i386__
    return std::string( "__i386__" );
#endif

#if __x86_64__
    return std::string( "__x86_64__" );
#endif

#if __aarch64__
    return std::string( "__aarch64__" );
#endif

    return std::string( "N/A" );
}

std::string Info::getLibstcpp()
{
#if defined _GLIBCXX_USE_CXX11_ABI
    return std::string( "TRUE" );
#else
    return std::string( "FALSE" );
#endif
}

std::string Info::getCompiler()
{
    std::ostringstream compiler = std::ostringstream();

#if _MSC_VER
    compiler << "_MSC_VER: " << _MSC_VER << std::endl;
#endif

#if _MSVC_LANG
    compiler << "_MSVC_LANG: " << _MSVC_LANG << std::endl;
#endif

#if __cplusplus
    compiler << "__cplusplus: " << __cplusplus << std::endl;
#endif

#if __INTEL_COMPILER
    compiler << "__INTEL_COMPILER: " << __INTEL_COMPILER << std::endl;
#endif

#if __GNUC__
    compiler << "__GNUC__: " << __GNUC__ << std::endl;
#endif

#if __GNUC_MINOR__
    compiler << "__GNUC_MINOR__: " << __GNUC_MINOR__ << std::endl;
#endif

#if __clang_major__
    compiler << "__clang_major__: " << __clang_major__ << std::endl;
#endif

#if __clang_minor__
    compiler << "__clang_minor__: " << __clang_minor__ << std::endl;
#endif

#if __apple_build_version__
    compiler << "__apple_build_version__: " << __apple_build_version__ << std::endl;
#endif

    return compiler.str();
}

std::string Info::getSubsytem()
{
#if __MSYS__
    return std::string( "__MSYS__" );
#endif

#if __MINGW32__
    return std::string( "__MINGW32__" );
#endif

#if __MINGW64__
    return std::string( "__MINGW64__" );
#endif

#if __CYGWIN__
    return std::string( "__CYGWIN__" );
#endif

    return std::string( "N/A" );
}

void Info::show()
{
    std::cout <<__PRETTY_FUNCTION__ << std::endl;
    std::cout << std::endl;
    std::cout << "Version: " << getVersion() << std::endl;
    std::cout << "Major: " << getMajorVersion() << std::endl;
    std::cout << "Minor: " << getMinorVersion() << std::endl;
    std::cout << "Patch: " << getPatchVersion() << std::endl;
    std::cout << "Tweak: " << getTweakVersion() << std::endl;
    std::cout << std::endl;
    std::cout << "Name: " << CORE_NAME << std::endl;
    std::cout << "Description: " << CORE_DESCRIPTION << std::endl;
    std::cout << std::endl;
    std::cout << "Compile Mode: " << getCompileMode() << std::endl;
    std::cout << "Architecture: " << getArchitecture() << std::endl;
    std::cout << "Libstdc++: " << getLibstcpp() << std::endl;
    std::cout << "Compiler: " << getCompiler() << std::endl;
    std::cout << "Subsystem: " << getSubsytem() << std::endl;
}

}
