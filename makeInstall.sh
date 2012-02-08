#! /bin/bash
echo "compiling: libs"
cd ./SFEProtocole
make clean all
cp *.so* /opt/lib -vf
cd ../
cd ./client
make clean all
cd ..
cd ./server 
make clean all
echo "please do :export LD_LIBRARY_PATH=/opt/lib:\$LD_LIBRARY_PATH"
#export LD_LIBRARY_PATH="/opt/lib:$LD_LIBRAY_PATH"
