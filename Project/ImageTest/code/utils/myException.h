/**********************************************************************************************//**
 * @file    include\MyException.h.
 *
 * @brief   声明自己处理过程中遇到的异常, 在遇到异常的时候直接返回处异常位置, 便于后续处理
 * @changelog   2018/11/28    SChen Created.
 *************************************************************************************************/
#pragma once
#include <string>

/**
 * @enum    ErrorCode
 *
 * @brief   定义错误代码 表示不同功能, 从小到达依次定义
 *          *        可以参考错误代码表
 */

enum ErrorCode
{
    ConfigError = 101,
    Error_IDOI_File_Write = 201,    // IDOI 写文件指针错误
    Error_IDOI_FileNotExist         =   5000,
    Error_IDOI_FileWritePointerNull =   5001,   //    写入文件指针为空
    Error_IDOI_FileVerifyError      =   5002,   // 读取文件头校验失败

    Error_Image_Resize_Crash =  3001,   // 图片缩放错误

    Error_Serial_Timeout_Over_Set_Time = 4002,  // 串口超时无数据

};

/**********************************************************************************************//**
 * @class   MyException MyException.h include\MyException.h
 *
 * @brief   直接从 异常基类继承 , 可以考虑分别使用不同的基类继承出来不同的类
 *
 * @author  SChen
 * @date    2018/11/28
 *************************************************************************************************/

/**
 * @class   MyException myException.h Code\inc\myException.h
 *
 * @brief   Exception for signalling my errors.
 *
 * @author  IRIS_Chen
 * @date    2019/11/7
 */

class MyException : public std::exception
{
    public:

    // 错误信息返回
    int error_code; ///< The error code
    std::string error_mes;  ///< The error mes

    /**
     * @fn  MyException::MyException(int num = 100, std::string str = "Unknown exception")
     *
     * @brief   初始对象生成 默认会出现  位置错误 对于错误异常 直接处理结果
     *
     * @author  IRIS_Chen
     * @date    2019/11/7
     *
     * @param   num (Optional) Number of
     * @param   str (Optional) The string
     */

    MyException(int num = 100, std::string str = "Unknown exception")
    {
        // LOG(INFO) << "错误代码:" << err_num << ":" << err_str;
        error_code = num;
        error_mes = str;
        // log出异常
        LError("Exception occur:\t Code:{}\tMess:{}", error_code, error_mes);
    }
};
