# create executables
add_executable(ImaPlatform main.cpp)
add_executable(LanguageTester language.cpp)

# link static libraries
target_link_libraries(ImaPlatform Ima)
target_link_libraries(ImaPlatform ImaParser)
target_link_libraries(ImaPlatform ${PROJECT_SOURCE_DIR}/antlr4-cpp-runtime-4.7.1-macos/lib/libantlr4-runtime.a)
target_link_libraries(ImaPlatform /Applications/CPLEX_Studio128/cplex/lib/x86-64_osx/static_pic/libcplex.a)
target_link_libraries(ImaPlatform /Applications/CPLEX_Studio128/cplex/lib/x86-64_osx/static_pic/libcplexdistmip.a)
target_link_libraries(ImaPlatform /Applications/CPLEX_Studio128/cplex/lib/x86-64_osx/static_pic/libilocplex.a)
target_link_libraries(ImaPlatform /Applications/CPLEX_Studio128/concert/lib/x86-64_osx/static_pic/libconcert.a)
target_link_libraries(LanguageTester Ima)
target_link_libraries(LanguageTester ImaParser)
target_link_libraries(LanguageTester ${PROJECT_SOURCE_DIR}/antlr4-cpp-runtime-4.7.1-macos/lib/libantlr4-runtime.a)
target_link_libraries(LanguageTester /Applications/CPLEX_Studio128/cplex/lib/x86-64_osx/static_pic/libcplex.a)
target_link_libraries(LanguageTester /Applications/CPLEX_Studio128/cplex/lib/x86-64_osx/static_pic/libcplexdistmip.a)
target_link_libraries(LanguageTester /Applications/CPLEX_Studio128/cplex/lib/x86-64_osx/static_pic/libilocplex.a)
target_link_libraries(LanguageTester /Applications/CPLEX_Studio128/concert/lib/x86-64_osx/static_pic/libconcert.a)
