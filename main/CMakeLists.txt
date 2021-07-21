project(CPP1_task)

add_executable(LinearSolver main.cpp functions.cpp)

include_directories (../linsolvers)

target_link_libraries(LinearSolver linsolvers)