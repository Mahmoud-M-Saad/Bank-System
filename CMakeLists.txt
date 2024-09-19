# CMakeList.txt : CMake project for Bank-System, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Bank-System")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/app")

# Add source to this project's executable.
add_executable (Bank-System "app/main.cpp" "app/src/person.cpp" "app/src/employee.cpp" "app/src/admin.cpp" "app/src/client.cpp" "app/src/validation.cpp" "app/src/generalFunctions.cpp" "app/src/improvedValidation.cpp")

target_include_directories(Bank-System PRIVATE "app/include" "app/thirdParty" "app/database")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Bank-System PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.