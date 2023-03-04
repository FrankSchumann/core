#pragma once

#include <stdint.h>

#include <string>

namespace core
{
class Info
{
   public:
    static std::string getVersion();
    static uint32_t getMajorVersion();
    static uint32_t getMinorVersion();
    static uint32_t getPatchVersion();
    static uint32_t getTweakVersion();

    static std::string getName();
    static std::string getDescription();

    static std::string getCompileMode();
    static std::string getArchitecture();
    static std::string getLibstcpp();
    static std::string getCompiler();
    static std::string getSubsytem();

    static void show();
};

}
