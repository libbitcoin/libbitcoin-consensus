#!/bin/bash
source ./bindings-env.sh

mkdir -p $TARGET_DIR/objs
mkdir -p $TARGET_DIR/lib
mkdir -p $TARGET_DIR/classes

gcc -fPIC -c $GENERATED_SRC/src/main/cpp/java-wrap/$LIB_NAME.cpp -o $TARGET_DIR/objs/javawrap$LIB_NAME.o -I$JAVA_HOME/include -I$JAVA_HOME/include/linux
gcc -fPIC  -shared $TARGET_DIR/objs/javawrap$LIB_NAME.o -o $TARGET_DIR/lib/libjavawrap$LIB_NAME.so -L/usr/local/lib -lbitcoin-$ARTIFACT_ID

$JAVA_HOME/bin/javac -sourcepath $TARGET_DIR/generated-sources/src/main/java/ $TARGET_DIR/generated-sources/src/main/java/org/libbitcoin/$LIB_NAME/*.java -d $TARGET_DIR/classes
$JAVA_HOME/bin/javac -sourcepath bindings/src/main/java/ bindings/src/main/java/org/libbitcoin/$LIB_NAME/*.java -d $TARGET_DIR/classes

$JAVA_HOME/bin/jar cf $TARGET_DIR/lib/$LIB_NAME-$VERSION.jar -C $TARGET_DIR/classes .
$JAVA_HOME/bin/jar uf $TARGET_DIR/lib/$LIB_NAME-$VERSION.jar -C $TARGET_DIR/lib libjavawrap$LIB_NAME.so 
