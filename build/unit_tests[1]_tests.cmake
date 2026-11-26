add_test([=[calcBmiTest.calculatesBmi]=]  /home/badblob/coding/cppdev/cppCapstone1/build/unit_tests [==[--gtest_filter=calcBmiTest.calculatesBmi]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[calcBmiTest.calculatesBmi]=]  PROPERTIES DEF_SOURCE_LINE /home/badblob/coding/cppdev/cppCapstone1/tests/BmiTest.cpp:4 WORKING_DIRECTORY /home/badblob/coding/cppdev/cppCapstone1/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  unit_tests_TESTS calcBmiTest.calculatesBmi)
