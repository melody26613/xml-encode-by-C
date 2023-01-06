### Test environment

* Ubuntu 20.04

### Preparation

1. download googletest

        git clone https://github.com/google/googletest
        
        cd googletest
        
        cmake -DCMAKE_CXX_FLAGS=-std=c++11 -Dgtest_build_samples=ON
        
        make -j4

    output library is lib/libgtest.a

    header files at googletest/include/

2. compile test sample

        make clean; make

3. execute test

        ./test_xml_module

[reference](https://shengyu7697.github.io/googletest/)