#ifndef ENUM_MAP_TEST_H
#define ENUM_MAP_TEST_H

#include <map>
#include <string>

std::map<std::string, int> SocketTalEnumMap
{
    { "DEV_ALL", 0 },
    { "DEV_MGT", 1 },
    { "DEV_PED", 2 },
    { "DEV_SCD", 3 },
    { "DEV_AUD", 4 },
    { "DEV_SCR", 5 },
};

#endif /* ENUM_MAP_TEST_H */
