//#pragma once

#include <stdint.h>
#include <cstring>

template <typename Type, size_t MaxElements>
class RingBufCPP
{
public:
RingBufCPP()
{
         _numElements = 0;
         _head = 0;
}

void empty()
{
         _numElements = 0;
         _head = 0;
}

bool ICACHE_RAM_ATTR push(Type obj)
{
    bool ret = false;
        if (!isFull()) 
        {
            _buf[_head] = obj;
            _head = (_head + 1)%MaxElements;
            _numElements++;

            ret = true;
        }
    return ret;
}

Type ICACHE_RAM_ATTR pull()
{
    size_t tail;

        if (!isEmpty()) {
            tail = getTail();
            Type dest = _buf[tail];
            _numElements--;
            return dest;
        }

    return -1;
}

bool ICACHE_RAM_ATTR isFull()
{
    bool ret;

        ret = _numElements >= MaxElements;

    return ret;
}

size_t ICACHE_RAM_ATTR size()
{
    size_t ret;

        ret = _numElements;

    return ret;
}

size_t ICACHE_RAM_ATTR capacity()
{
    return MaxElements - _numElements;
}

bool ICACHE_RAM_ATTR isEmpty()
{
    bool ret;

        ret = !_numElements;

    return ret;
}

Type* ICACHE_RAM_ATTR peek(size_t num)
{
    Type *ret = NULL;

        if (num < _numElements) //make sure not out of bounds
            ret = &_buf[(getTail() + num)%MaxElements];

    return ret;
}

protected:

size_t ICACHE_RAM_ATTR getTail()
{
    return (_head + (MaxElements - _numElements))%MaxElements;
}

Type _buf[MaxElements];
size_t _head;
size_t _numElements;
};
