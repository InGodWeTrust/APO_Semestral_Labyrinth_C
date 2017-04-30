cmake_minimum_required(VERSION 3.7)
project(semestral)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c util/font/font_rom8x16.c util/font/font_types.h util/font/font_prop14x16.c util/lcd/mzapo_parlcd.h util/lcd/mzapo_parlcd.c util/lcd/mzapo_regs.h util/mem/mzapo_phys.h util/mem/mzapo_phys.c)
add_executable(semestral ${SOURCE_FILES})