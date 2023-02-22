set(PNAME roster)
add_executable(${PNAME} main.cpp 
  person.cpp
  person_process.cpp
  )

target_include_directories(${PNAME} PUBLIC
  ${PROJECT_SOURCE_DIR}/inc
  )

target_link_directories(${PNAME} PUBLIC
  ${PROJECT_SOURCE_DIR}/src
  )

set_property(TARGET ${PNAME} PROPERTY CXX_STANDARD 17)


target_compile_options(
  ${PNAME} BEFORE
  PRIVATE
  "$<$<CONFIG:Release>:-ofast>"

  "$<$<CONFIG:Debug>:-ggdb>"

  "$<$<CONFIG:test>:-ggdb>"

  "$<$<CONFIG:bench>:-ofast>"
  )
