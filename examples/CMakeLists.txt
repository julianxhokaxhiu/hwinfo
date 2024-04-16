add_executable(Example example.cpp)
target_link_libraries(Example PUBLIC hwinfo::HWinfo)
target_compile_options(
  Example
  PRIVATE /D_CRT_SECURE_NO_WARNINGS
  PRIVATE /DNOMINMAX
  PRIVATE /Zc:strictStrings-
  PRIVATE /Zc:__cplusplus
  PRIVATE /Qpar
  PRIVATE /MP
)
target_compile_features(Example
  PRIVATE cxx_std_20
)
