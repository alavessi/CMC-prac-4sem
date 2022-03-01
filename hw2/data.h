#pragma once

class Data
{
private:
    const char* name;
    int phone;
    int number;
    static int Number;
    
public:
    Data (const char* _name, int _phone);
    Data (const Data& data);
    void print() const;
};
