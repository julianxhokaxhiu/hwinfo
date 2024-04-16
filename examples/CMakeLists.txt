find_package(fmt QUIET)

if (NOT fmt_FOUND)
    message(" -> libfmt not found. Fetching from github...")
    include(FetchContent)
    FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 11.0.1)
    FetchContent_MakeAvailable(fmt)
else ()
    message(" -> using installed libfmt")
endif ()

add_executable(system_info system_infoMain.cpp)

target_link_libraries(system_info PRIVATE lfreist-hwinfo::hwinfo fmt::fmt)

install(TARGETS system_info)

target_compile_options(
  system_info
  PRIVATE /D_CRT_SECURE_NO_WARNINGS
  PRIVATE /DNOMINMAX
  PRIVATE /Zc:strictStrings-
  PRIVATE /Zc:__cplusplus
  PRIVATE /Qpar
  PRIVATE /MP
)
target_compile_features(system_info
  PRIVATE cxx_std_20
)