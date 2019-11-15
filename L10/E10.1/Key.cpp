#include "Key.h"

Key::Key(int id)
{
    if (id != P1 && id != P2)
    {
        id_ = P1;
    }
    else
    {
        id_ = id;
    }
}

bool Key::pressed()
{
    return keyPressed(id_);
}