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
cd ..

cd ./CDRProcessor
gnome-terminal -x ./TestProcMngr

cd ..
cd ./Feeder
gnome-terminal -x ./TestFeedMngr 

cd ..
cd ./UI
./TestUIMngr






