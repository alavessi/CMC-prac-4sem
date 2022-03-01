#pragma once

class FC
{
public:
    virtual ~FC();
    virtual const char* stadium() = 0;
    virtual const char* coach() = 0;
    virtual const char* leader() = 0;
    virtual int UCL_winners() = 0;
};
