#include <set>
#include <algorithm>
#include "Led.h"

const std::set<int> valid = {LD1, LD2, LD3, LD4, LD5, LD6};

Led::Led(int id)
{
    if (valid.find(id) == valid.end())
    {
        id_ = LD1;
    }
    else
    {
        id_ = id;
    }
}

void Led::on(int intensity)
{
    if (id_ == LD6)
    {
        ledOn(id_, std::min(100, std::max(intensity, 60)));
    }
    else
    {
        ledOn(id_);
    }
}

void Led::off()
{
    ledOff(id_);
}