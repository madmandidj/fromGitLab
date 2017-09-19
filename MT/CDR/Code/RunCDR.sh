cd ./UI
make clean
make
cd ..

cd ./CDRProcessor
make clean
make
cd ..

cd ./Feeder
make clean
make
cd ./NewFileWatcher
mkdir DONE
mkdir WORKING
mkdir NEW
cd ../..

cd ./DataGenerator
make clean
make
./TestDataGenerator -n 10000
./TestDataGenerator -n 10000
./TestDataGenerator -n 10000
cd ..

cd ./CDRProcessor
gnome-terminal -x ./TestProcMngr
cd ..

cd ./Feeder
gnome-terminal -x ./TestFeedMngr 
cd ..

cd ./UI
./TestUIMngr






