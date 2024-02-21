#pragma once
#include <iostream>

enum class Tribe
{
	Human,
	Undead,
	Zombie,
	God,
	Count	//call static_cast<int>(Tribe::Count) to get the number of entries in enum
};

namespace TribeInfo {
    inline std::string tribeToString(Tribe tribe)
    {
        switch (tribe)
        {
            case Tribe::Human:
                return "Human";
            case Tribe::Undead:
                return "Undead";
            case Tribe::Zombie:
                return "Zombie";
            case Tribe::God:
                return "God";
            case Tribe::Count:
            default:
                return "";
        }
    }
}