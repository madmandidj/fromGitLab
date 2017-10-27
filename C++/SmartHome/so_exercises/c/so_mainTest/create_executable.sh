#Enter name of so folder as parameter

gcc -L/home/eyal/Desktop/EyalsFolder/work/C++/SmartHome/so_exercises/c/$1/ -Wall Test_shared.c -o test_shared -lshared
export LD_LIBRARY_PATH=/home/eyal/Desktop/EyalsFolder/work/C++/SmartHome/so_exercises/c/$1:$LD_LIBRARY_PATH
./test_shared
