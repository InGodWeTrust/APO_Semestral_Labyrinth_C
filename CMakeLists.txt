cmake_minimum_required(VERSION 3.7)
project(semestral)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c font_rom8x16.c font_types.h font_prop14x16.c mzapo_parlcd.h mzapo_parlcd.c mzapo_regs.h mzapo_phys.h mzapo_phys.c)
add_executable(semestral ${SOURCE_FILES})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(semestral Threads::Threads)