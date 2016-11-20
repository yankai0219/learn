#!/bin/sh
### 编译jsoncpp
TMP_DIR=/tmp/
SOURCE_CODE_DIR=$TMP_DIR/jsoncpp-0.10.6
TMP_TAR_GZ_PATH=/tmp/0.10.6.tar.gz
rm -rf $TMP_TAR_GZ_PATH
wget https://github.com/open-source-parsers/jsoncpp/archive/0.10.6.tar.gz  -O $TMP_TAR_GZ_PATH
tar zxvf $TMP_TAR_GZ_PATH -C $TMP_DIR 
which scons
if [ $? != 0 ]; then
    sudo yum install -y scons
    if [ $? != 0 ]; then
        echo "install scons error"
        exit
    fi
fi

cd $SOURCE_CODE_DIR && scons platform=linux-gcc
if [ $? != 0 ]; then
    echo "scons error"
    exit
fi

### 写第一个例子
rm -rf /tmp/json_cpp_dist
mv ~/json_cpp_dist /tmp/
mkdir ~/json_cpp_dist
cp -r $SOURCE_CODE_DIR/include ~/json_cpp_dist
cp -r $SOURCE_CODE_DIR/libs ~/json_cpp_dist

###编译
cd ~/json_cpp_dist
cp /tmp/json_cpp_demo1.cpp ~/json_cpp_dist
g++ json_cpp_demo1.cpp -I ./include ./libs/linux-gcc-4.4.7/libjson_linux-gcc-4.4.7_libmt.a -o c
./c
## 将会输出
## got name TOM
## got id4
## gotmember id
## gotmember name
## got name JACK
## got id5
## gotmember id
## gotmember name

#参考文章
#http://www.cnblogs.com/logicbaby/archive/2011/07/03/2096794.html
