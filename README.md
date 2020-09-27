# LeetCode Problems

## Project
I like to do daily (hopefully) programming problems to have a better understanding of the language and have fun learning how to solve different problems.

I've decided to do these problems as header only, just so I don't have a .h and .cpp file for each problem. Since each problem is just a function (usually) I find it's easier this way.

## Build
* CMake 3.16
* C++17
* Google test 1.10.0

To build you can use the cmake extension in vscode. For command line I use the following.

    cmake --build ./build --config Debug --target all -j 14

    or simply cmake.

## Running and testing
There is no binary to "run". I write tests for all problems and this is how I know they are correct. So all we do is just run the tests.

    Running the test binary from the build directory
    ./build/test/LeetCodeTests

## License
MIT License

Copyright (c) 2020 Joe Berria

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
