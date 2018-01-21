cd ./UI
make
cd ..


cd ./CDRProcessor
make
cd ..


cd ./Feeder
make
cd ..


cd ./DataGenerator
make
./TestDataGenerator -n 1000000 -s 4 -o 6
cd ..


cd ./CDRProcessor
gnome-terminal -x ./TestProcMngr -n 5 -s 1000000 -o 100000
cd ..


cd ./Feeder
gnome-terminal -x ./TestFeedMngr -n 5
cd ..


cd ./UI
./TestUIMngr






