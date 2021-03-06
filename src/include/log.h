
#ifndef __LOG_H
#define __LOG_H

#include <string>

enum 
{
    FILE_TYPE_ALLOC = 0,
    FILE_TYPE_FREE,
    FILE_TYPE_BUTT
};

struct LogHeadInfo
{
    size_t leak_sum;

    std::string description;
};

class LogHandle
{
private:

    std::string log_file_name;

    enum log_level
    {
       LOG_INFO,
       LOG_DEBUG,
       LOG_ERROR,
       LOG_CRITICAL,
       LOG_BUTT
    };

public:

    static LogHandle& get_instance(unsigned int type);

    void log_debug(const std::string& content);

    void log_error(const std::string& content);

    void log_head_info(LogHeadInfo head_info);
    
    void log_print(const std::string& log);

    void log_print(const char* log);
 
private:

    LogHandle(unsigned int type);

    virtual ~LogHandle(){}; 

    void log_consist(enum log_level level, const std::string& content, std::string& log);

    void get_logname(std::string& log_name);

    void get_systime(std::string& now);
    
    unsigned int m_type;
};

#endif
