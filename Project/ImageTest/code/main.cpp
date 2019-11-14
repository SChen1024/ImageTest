/**
 * @file    code\main.cpp.
 * @copyright   Copyright (c) 2019 IRIS_Chen IRIS Lab
 *
 * @brief   Implements the main class
 * @changelog   2019/11/14    IRIS_Chen Created.
 */

#include "stdafx.h"
#include <QApplication>


#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"


TEST_CASE("Image Project") {
    std::string str = "12345";
    CHECK(str == "12345");
}

/**
 * @fn  int main(int argc, char *argv[])
 *
 * @brief   Main entry-point for this application
 *
 * @author  IRIS_Chen
 * @date    2019/11/14
 *
 * @param   argc    The number of command-line arguments provided
 * @param   argv    An array of command-line argument strings
 *
 * @return  Exit-code for the process - 0 for success, else an error code
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageTest w;
    w.show();

    // ²âÊÔ doc test ÊÇ¹»¹¤×÷
    doctest::Context context;
    // context.applyCommandLine(argc, argv);
    // context.addFilter("test-case-exclude", "*math*"); // exclude test cases with "math" in the name
    // context.setOption("rand-seed", 324);              // if order-by is set to "rand" use this seed
    context.setOption("order-by", "file");            // sort the test cases by file and line
                                                      // overrides
    context.setOption("no-breaks", true); // don't break in the debugger when assertions fail
    context.run(); // run doctest


    LTrace("test SpdLog");

    return a.exec();
}
