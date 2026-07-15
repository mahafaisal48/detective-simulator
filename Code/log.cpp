#include"log.h"

logger::logger() {}
logger::~logger()
{
    if (file.is_open())
        file.close();
}

logger& logger::getInstance()
{
    static logger obj;
    return obj;
}

void logger::initialize(const my_str& filename)
{

    file.open(filename.get_cs(), ios::trunc);
    if (!file.is_open())
    {
        cout << "Failed to open log file." << endl;
    }
    file.close();

    file.open(filename.get_cs(), ios::out|ios::app);
    if (!file.is_open())
    {
        cout << "Failed to open log file." << endl;
    }
}

void logger::cleanup()
{
    if (file.is_open())
        file.close();
}

void logger::write_log(const my_str& log_type,const my_str& message) 
{
    if (!file.is_open())
    {
        cout << "Log file not open!" << endl;
        return;
    }

    time_t now = time(0);
    char timestamp[26];
    ctime_s(timestamp, sizeof(timestamp), &now);
    timestamp[strcspn(timestamp, "\n")] = '\0'; // remove newline

    file << log_type.get_cs()<<" "<< message.get_cs() << " (" << timestamp << ")\n";
}

void logger::write_error(const my_str& error_message)
{
    write_log("ERROR", error_message);
}

void logger::write_action(const my_str& action_message)
{
    write_log("ACTION", action_message);
}

void logger::write_info(const my_str& info_message)
{
    write_log("INFO", info_message);
}