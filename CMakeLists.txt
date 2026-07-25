cmake_minimum_required(VERSION 3.10)
project(OrderBook)

set(CMAKE_CXX_STANDARD 17)

add_executable(orderbook 
	src/main.cpp
	src/Order.cpp
)

target_include_directories(orderbook
	PRIVATE
		include
)