#Enter name of so folder as parameter

g++ -L/home/eyal/Desktop/EyalsFolder/work/C++/SmartHome/so_exercises/cpp/$1/ -Wall Test_shared.cpp -o test_shared -lshared
export LD_LIBRARY_PATH=/home/eyal/Desktop/EyalsFolder/work/C++/SmartHome/so_exercises/cpp/$1:$LD_LIBRARY_PATH
./test_shared
