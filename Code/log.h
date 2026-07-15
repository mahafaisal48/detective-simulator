#ifndef LOG_H
#define LOG_H
#include <fstream>
#include <ctime>
#include <iostream>
#include "mystr.h"
using namespace std;

class logger 
{
    fstream file;
    logger();                 
    ~logger();                

public:
    static logger& getInstance();

    void initialize(const my_str& filename);
    void cleanup();

    void write_log(const my_str& log_type,const my_str& message);
    void write_error(const my_str& error_message);
    void write_action(const my_str& action_message);
    void write_info(const my_str& info_message);
};
#endif