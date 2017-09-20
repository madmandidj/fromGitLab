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
./TestDataGenerator -n 100000
cd ..


cd ./CDRProcessor
gnome-terminal -x ./TestProcMngr -n 1
cd ..


cd ./Feeder
gnome-terminal -x ./TestFeedMngr -n 1
cd ..


cd ./UI
./TestUIMngr






