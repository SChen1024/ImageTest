/**
 * @file    Code\inc\SpdLogger.h.
 * @copyright   Copyright (c) 2019 IRIS_Chen IRIS Lab
 *
 * @brief   Declares the speed logger class
 * @changelog   2019/10/17    IRIS_Chen  Created.
 */

#pragma once

/**************************************************************************//**
* spdLog 封装 文件输出和 控制台输出  自定义loggger
* https://blog.csdn.net/et_endeavoring/article/details/86109121
* * 使用方法
char your_log_file_name[] = "Example.log";
typedef CLogger<your_log_file_name> tlog;
*
* @author  IRIS_Chen
* @date    2019/6/25
*
* @tparam  file_name[] Type of the file name[].
*******************************************************************************/

// 判断文件夹是否存在 一层
//  static function check dir 
// Check only one layer
#ifndef CHECK_DIR_
#define CHECK_DIR_

#ifdef WIN32  
#include <io.h>
#include <direct.h>  
#endif  
#ifdef linux   
#include <unistd.h> 
#include <sys/types.h>  
#include <sys/stat.h> 
#endif  

/**
 * @fn  static bool check_dir(const char* dir)
 *
 * @brief   Check dir
 *
 * @author  IRIS_Chen
 * @date    2019/10/17
 *
 * @param   dir The dir
 *
 * @return  True if it succeeds, false if it fails
 */

static bool check_dir(const char* dir)
{
    if (_access(dir, 0) == -1)
    {
#ifdef WIN32  
        int flag = _mkdir(dir);
#endif  
#ifdef linux   
        int flag = mkdir(dir.c_str(), 0777);
#endif  
        return (flag == 0);
    }
    return true;
};
#endif

//*****************************************************
//注意：
//文件名 __FILE__ ,函数名 __func__ ，行号__LINE__ 是编译器实现的
//并非C++头文件中定义的 
//前两个变量是string类型，且__LINE__是整形，所以需要转为string类型
//******************************************************

//整数类型文件行号 ->转换为string类型  std::to_string 处理
#include "spdlog/sinks/stdout_color_sinks.h"
#ifdef _WIN32

/**
 * @def FILENAME_
 *
 * @brief   A macro that defines filename
 *
 * @author  IRIS_Chen
 * @date    2019/10/17
 */

#define FILENAME_ (strrchr(__FILE__, '\\') ? (strrchr(__FILE__, '\\') + 1):__FILE__)
#else

/**
 * @def FILENAME_
 *
 * @brief   A macro that defines filename
 *
 * @author  IRIS_Chen
 * @date    2019/10/17
 */

#define FILENAME_ (strrchr(__FILE__, '/') ? (strrchr(__FILE__, '/') + 1):__FILE__)
#endif

//定义一个在日志后添加 文件名 函数名 行号 的宏定义
#ifndef suffix_

/**
 * @def suffix_(msg)
 *
 * @brief   A macro that defines suffix
 *
 * @author  IRIS_Chen
 * @date    2019/10/17
 *
 * @param   msg The message
 */

#define suffix_(msg)  std::string(msg).append("  <")\
        .append(FILENAME_).append(":") \
        .append(std::to_string(__LINE__))\
        .append("> <")\
        .append(__func__)\
        .append(">").c_str()
//#define suffix_(msg)  std::string().append(" File:")\
//        .append(FILENAME_).append("\", Func:\"").append(__func__)\
//        .append("()\", Line:\"").append(std::to_string(__LINE__)).append("\"").append(msg).c_str()
#endif

//在  spdlog.h   之前定义，才有效
#ifndef SPDLOG_TRACE_ON
#define SPDLOG_TRACE_ON
#endif

#ifndef SPDLOG_DEBUG_ON
#define SPDLOG_DEBUG_ON
#endif



#ifndef CBOREHOLE_LOGGER_H_
#define CBOREHOLE_LOGGER_H_

/**
 * @def LOG2FILE_
 *
 * @brief   定义 LOGFILE 这样才会log 到相应文件
 *
 * @author  IRIS_Chen
 * @date    2019/10/17
 */

#define LOG2FILE_ 1
#include <ctime>   // 引入时间 便于生成文件


// spd log 参数
#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/async_logger.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/msvc_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"

/**
 * @class   SpdLogger SpdLogger.h Code\inc\SpdLogger.h
 *
 * @brief   A speed logger.
 *
 * @author  IRIS_Chen
 * @date    2019/10/17
 */

class SpdLogger
{

    public:

    /**
     * @fn  static SpdLogger& SpdLogger::GetInstance()
     *
     * @brief   Gets the instance
     *
     * @author  IRIS_Chen
     * @date    2019/10/17
     *
     * @return  The instance
     */

    static SpdLogger& GetInstance() {
        static SpdLogger m_instance;
        return m_instance;
    }

    /**
     * @fn  auto SpdLogger::GetLogger()
     *
     * @brief   Gets the logger
     *
     * @author  IRIS_Chen
     * @date    2019/10/17
     *
     * @return  The logger
     */

    auto GetLogger() {
        return nml_logger;
    }

    private:

    /**
     * @fn  SpdLogger::SpdLogger()
     *
     * @brief   Initializes a new instance of the SpdLogger class
     *
     * @author  IRIS_Chen
     * @date    2019/10/17
     */

    SpdLogger() {
        // 检查文件夹是否存在
        check_dir("logs");

        //std::vector<spdlog::sink_ptr> sinks;
        //sinks.push_back(std::make_shared<spdlog::sinks::msvc_sink_mt>());
        //sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>(file_name, 1024 * 1024 * 4, 1));
        //// sinks.push_back(std::make_shared<spdlog::sinks::basic_logger_mt>("Camera",file_name));

        //combined_logger = std::make_shared<spdlog::logger>(file_name, begin(sinks), end(sinks));
        //// 打印格式设置 https://github.com/gabime/spdlog/wiki/3.-Custom-formatting
        ////设置打印格式  年月日 时分秒.毫秒, 线程ID,日志等级,内容 );
        //combined_logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%t] [%l] %v");
        //combined_logger->set_level(spdlog::level::trace);

        //设置为异步日志
        // spdlog::set_async_mode(32768);  // 必须为 2 的幂

        std::vector<spdlog::sink_ptr> sinkList;

        // #FIXME (schen00) 此处修复每次打开console 的问题 
        // 命令行窗口输出 会打开console 
        #ifdef _CONSOLE
            #ifdef _DEBUG
                auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
                consoleSink->set_level(spdlog::level::trace);
                //consoleSink->set_pattern("[multi_sink_example] [%^%l%$] %v");
                consoleSink->set_pattern("[%H:%M:%S][%^%L%$] %v");
                sinkList.push_back(consoleSink);
            #endif
        #endif

        // VS 调试窗口 输出 debug 窗口输出内容
#ifdef _DEBUG
        auto debuggerSink = std::make_shared<spdlog::sinks::msvc_sink_mt>();
        debuggerSink->set_level(spdlog::level::trace);
        debuggerSink->set_pattern("[%m-%d %H:%M:%S.%e] [%t] [%L] %v");
        sinkList.push_back(debuggerSink);
#endif

#if LOG2FILE_
        // 使用 当前时间创建 log文件
        // 获取当前时间字符串
        time_t t = time(nullptr);
        struct tm ltm;
        localtime_s(&ltm,&t);
        std::string str = std::to_string(1900+ltm.tm_year)  + ""
                        + std::to_string(ltm.tm_mon)        + ""
                        + std::to_string(ltm.tm_mday)       + "-"
                        + std::to_string(ltm.tm_hour)       + ""
                        + std::to_string(ltm.tm_min);

        // 日志文件 每次运行新建文件 按照时间格式明明
        std::string log_file_name = "logs/Bhole-Log-" + str + ".txt";

        // 文件输入 日志全部记录
        auto basicSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(log_file_name);
        basicSink->set_level(spdlog::level::debug);
        basicSink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%t] [%l] %v");
        sinkList.push_back(basicSink);
#endif
        // 设置异步模式
        nml_logger = std::make_shared<spdlog::logger>("both", begin(sinkList), end(sinkList));
        //register it if you need to access it globally
        spdlog::register_logger(nml_logger);

        // 设置日志记录级别
#ifdef _DEBUG
        nml_logger->set_level(spdlog::level::trace);
#else
        nml_logger->set_level(spdlog::level::err);
#endif
        //设置 logger 格式[%^%L%$]
        //nml_logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%5l]  %v");
        //nml_logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%5l%$]  %v");
        //设置当出发 err 或更严重的错误时立刻刷新日志到  disk 
        nml_logger->flush_on(spdlog::level::err);

        // 每3秒刷新 将数据 刷新到文件 避免日志崩溃未保存
        spdlog::flush_every(std::chrono::seconds(3));

        nml_logger->info("======== Init SPDLOG ========");
    }

    /**
     * @fn  SpdLogger::~SpdLogger()
     *
     * @brief   Finalizes an instance of the SpdLogger class
     *
     * @author  IRIS_Chen
     * @date    2019/10/17
     */

    ~SpdLogger() {
        spdlog::drop_all();
    }

    /**
     * @fn  SpdLogger::SpdLogger(const SpdLogger&) = delete;
     *
     * @brief   Initializes a new instance of the SpdLogger class
     *
     * @author  IRIS_Chen
     * @date    2019/10/17
     *
     * @param   parameter1  The first parameter
     */

    SpdLogger(const SpdLogger&) = delete;

    /**
     * @fn  SpdLogger& SpdLogger::operator=(const SpdLogger&) = delete;
     *
     * @brief   Assignment operator
     *
     * @author  IRIS_Chen
     * @date    2019/10/17
     *
     * @param   parameter1  The first parameter
     *
     * @return  A shallow copy of this object
     */

    SpdLogger& operator=(const SpdLogger&) = delete;

    private:
    std::shared_ptr<spdlog::logger> nml_logger; ///< The nml logger
};

//Logger& operator<<(Logger& log, const char* s);
//Logger& operator<<(Logger& log, const std::string& s);

//#define DEBUG Logger::GetInstance() 

/**
 * @def LTrace(msg,...)
 *
 * @brief   A macro that defines trace
 *
 * @author  IRIS_Chen
 * @date    2019/10/17
 *
 * @param   msg The message
 * @param   ... Variable arguments providing additional information
 */

#define LTrace(msg,...) SpdLogger::GetInstance().GetLogger()->trace(suffix_(msg),__VA_ARGS__)
// #define LDebug(msg,...) Logger::GetInstance().GetLogger()->debug(suffix_(msg),__VA_ARGS__)

/**
 * @def LDebug(...)
 *
 * @brief   A macro that defines debug
 *
 * @author  IRIS_Chen
 * @date    2019/10/17
 *
 * @param   ... Variable arguments providing additional information
 */

#define LDebug(...) SpdLogger::GetInstance().GetLogger()->debug(__VA_ARGS__)

/**
 * @def LInfo(...)
 *
 * @brief   A macro that defines Information
 *
 * @author  IRIS_Chen
 * @date    2019/10/17
 *
 * @param   ... Variable arguments providing additional information
 */

#define LInfo(...) SpdLogger::GetInstance().GetLogger()->info(__VA_ARGS__)

/**
 * @def LWarn(...)
 *
 * @brief   A macro that defines Warning
 *
 * @author  IRIS_Chen
 * @date    2019/10/17
 *
 * @param   ... Variable arguments providing additional information
 */

#define LWarn(...) SpdLogger::GetInstance().GetLogger()->warn(__VA_ARGS__)

/**
 * @def LError(msg,...)
 *
 * @brief   A macro that defines error
 *
 * @author  IRIS_Chen
 * @date    2019/10/17
 *
 * @param   msg The message
 * @param   ... Variable arguments providing additional information
 */

#define LError(msg,...) SpdLogger::GetInstance().GetLogger()->error(suffix_(msg),__VA_ARGS__)

/**
 * @def LCritical(...)
 *
 * @brief   A macro that defines critical
 *
 * @author  IRIS_Chen
 * @date    2019/10/17
 *
 * @param   ... Variable arguments providing additional information
 */

#define LCritical(...) SpdLogger::GetInstance().GetLogger()->critical(__VA_ARGS__)

/**
 * @def criticalif(b, ...)
 *
 * @brief   A macro that defines criticalif
 *
 * @author  IRIS_Chen
 * @date    2019/10/17
 *
 * @param   b   A void to process
 * @param   ... Variable arguments providing additional information
 */

#define criticalif(b, ...)                        \
    do {                                       \
        if ((b)) {                             \
           SpdLogger::GetInstance().GetLogger()->critical(__VA_ARGS__); \
        }                                      \
    } while (0)

#ifdef WIN32  

/**
 * @def errcode
 *
 * @brief   A macro that defines errcode
 *
 * @author  IRIS_Chen
 * @date    2019/10/17
 */

#define errcode WSAGetLastError()
#endif








#if 0

/**
 * @class   CLogger SpdLogger.h Code\inc\SpdLogger.h
 *
 * @brief   A logger.
 *
 * @author  IRIS_Chen
 * @date    2019/10/17
 */

class CLogger
{
    // CLogger() = delete;
    static std::shared_ptr<spdlog::logger> combined_logger; ///< The combined logger
    public:

    /**
     * @fn  CLogger::CLogger(std::string file_name = "./logs/Bhole.log")
     *
     * @brief   Initializes a new instance of the CLogger class
     *
     * @author  IRIS_Chen
     * @date    2019/10/17
     *
     * @param   file_name   (Optional) Filename of the file
     */

    CLogger(std::string file_name = "./logs/Bhole.log")
    {
        Init(file_name);
    }

    /**
     * @fn  static void CLogger::Init(std::string file_name = "./logs/Bhole.log")
     *
     * @brief   Initializes this object
     *
     * @author  IRIS_Chen
     * @date    2019/10/17
     *
     * @param   file_name   (Optional) Filename of the file
     */

    static void Init(std::string file_name = "./logs/Bhole.log")
    {
        if (combined_logger) combined_logger = nullptr;
        try
        {
            std::vector<spdlog::sink_ptr> sinks;
            sinks.push_back(std::make_shared<spdlog::sinks::msvc_sink_mt>());
            sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>(file_name, 1024 * 1024 * 4, 1));
            // sinks.push_back(std::make_shared<spdlog::sinks::basic_logger_mt>("Camera",file_name));

            combined_logger = std::make_shared<spdlog::logger>(file_name, begin(sinks), end(sinks));
            // 打印格式设置 https://github.com/gabime/spdlog/wiki/3.-Custom-formatting
            //设置打印格式  年月日 时分秒.毫秒, 线程ID,日志等级,内容 );
            combined_logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%t] [%l] %v");
            combined_logger->set_level(spdlog::level::trace);
            combined_logger->info("======== Init SPDLOG ========");
        }
        catch (...)
        {
            combined_logger = nullptr;
        }
    }

    /**
     * @fn  CLogger::~CLogger()
     *
     * @brief   删除 log
     *
     * @author  IRIS_Chen
     * @date    2019/10/17
     */

    ~CLogger()
    {
        cease_log();
    }

    template <typename... Args>

    /**
     * @fn  static inline void CLogger::info(const char* fmt, const Args&... args)
     *
     * @brief   Infoes
     *
     * @author  IRIS_Chen
     * @date    2019/10/17
     *
     * @param   fmt     Describes the format to use
     * @param   args    Variable arguments providing the arguments
     */

    static inline void info(const char* fmt, const Args&... args)
    {
        if (combined_logger) combined_logger->info(fmt, args...);
    }

    /**
     * @fn  static void CLogger::flush()
     *
     * @brief   Flushes this object
     *
     * @author  IRIS_Chen
     * @date    2019/10/17
     */

    static void flush()
    {
        if (combined_logger) combined_logger->flush();
    }

    /**
     * @fn  static void CLogger::cease_log()
     *
     * @brief   Cease log
     *
     * @author  IRIS_Chen
     * @date    2019/10/17
     */

    static void cease_log()
    {
        flush();
        combined_logger = nullptr;
    }
};

#endif

#endif  //CBOREHOLE_LOGGER_H_
