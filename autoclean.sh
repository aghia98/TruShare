cd Client
source environment.sh
make clean

cd ..

cd Server
source environment.sh
make clean

cd ..

cd Spawned_node
source environment.sh
make clean

cd ..

cd Worker
source environment.sh
make clean