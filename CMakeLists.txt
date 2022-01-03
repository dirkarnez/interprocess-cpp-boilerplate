cmake_minimum_required(VERSION 3.18)

# Yes, should be 11
set(CMAKE_CXX_STANDARD 11)
project(interprocess-cpp-boilerplate)

set(Boost_NO_SYSTEM_PATHS TRUE)
set(Boost_USE_STATIC_LIBS TRUE)
set(BOOST_ROOT "C:/Users/19081126D/Downloads/boost-playground-master/boost-prebuilt/boost-1.78.0-windows-2019-mingw/boost")

find_package(Boost REQUIRED COMPONENTS filesystem)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS} "include")

  SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

  add_executable(${PROJECT_NAME} 
    "src/ClInterprocBase.cpp"
    "src/ClInterprocClient.cpp"
    "src/ClInterprocListener.cpp"
    "src/ClInterprocMsgManager.cpp"
    "src/ClInterprocMsgQueue.cpp"
    "src/main.cpp"
  )
  
  target_link_libraries(${PROJECT_NAME} 
    ${Boost_LIBRARIES}
  )
endif()
