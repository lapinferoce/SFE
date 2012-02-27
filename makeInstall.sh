#! /bin/bash
echo "compiling: libs"
cd ./SFEProtocole
make clean all
cp *.so* /opt/lib -vf
cp *.h   /opt/include -vf
cd ../
cd ./client
make clean all
cd ..
cd ./server 
make clean all

#export LD_LIBRARY_PATH="/opt/lib:$LD_LIBRAY_PATH"
cd ./gui/SFEGui
make clean all
cd ..
cp ./gui/SFEGui/SFEGui /opt/bin -vf
echo "please do :export LD_LIBRARY_PATH=/opt/lib:\$LD_LIBRARY_PATH"
