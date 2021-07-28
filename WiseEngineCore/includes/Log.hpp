#ifndef LOG_HPP
#define LOG_HPP
#include<iostream>
namespace OverEngine {

#ifdef NDEBUG
#define LOG_INFO(...)// std::cout<<"LOG:  "<< __VA_ARGS__;
#define LOG_WARN(...)// std::cout<<"WARN:  "<< __VA_ARGS__;
#define LOG_ERROR(...)// std::cout<<"ERROR:  "<< __VA_ARGS__;
#define LOG_CRIT(...)// std::cout<<"CRIT:  "<< __VA_ARGS__;
#else	 
#define LOG_INFO(...) std::cout<<"LOG:  "<< __VA_ARGS__;
#define LOG_WARN(...) std::cout<<"WARN:  "<< __VA_ARGS__;
#define LOG_ERROR(...) std::cout<<"ERROR:  "<< __VA_ARGS__;
#define LOG_CRIT(...) std::cout<<"CRIT:  "<< __VA_ARGS__;
#endif
}
#endif