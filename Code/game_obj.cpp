#include "game_obj.h"

game_obj::game_obj() : name("N/A"), contains_clue(false), found(false), clues() {}

game_obj::game_obj(my_str t_name, bool cl, bool t_f, dynamic_array<clue> t_clues): name(t_name), contains_clue(cl), found(t_f), clues(t_clues) {}

game_obj::game_obj(const game_obj& other): name(other.name), contains_clue(other.contains_clue), found(other.found), clues(other.clues) {}

game_obj& game_obj::operator=(const game_obj& other)
{
    if (this != &other)
    {
        name = other.name;
        contains_clue = other.contains_clue;
        found = other.found;
        clues = other.clues;
    }
    return *this;
}

bool game_obj::operator==(const game_obj& other)
{
    if (!(name == other.name))
        return false;

    if (contains_clue != other.contains_clue)
        return false;

    if (found != other.found)
        return false;

    if (clues != other.clues)
        return false;

    return true;
}

bool game_obj::operator!=(const game_obj& other)
{
    if (!(*this == other))
        return true;

    return false;
}

dynamic_array<clue>& game_obj::get_clue()
{
    return clues;
}

bool game_obj::get_contains_cl()
{
    return contains_clue;
}

bool game_obj::get_found()
{
    return found;
}

my_str game_obj::get_name()
{
    return name;
}

ostream& operator<<(ostream& out, const game_obj& obj)
{
    out << obj.name << "\n";
    return out;
}

game_obj::~game_obj() {}