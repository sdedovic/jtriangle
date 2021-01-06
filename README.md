# JTriangle

A Java wrapper of the [Triangle](https://www.cs.cmu.edu/~quake/triangle.html) mesh generator and delaunay triangulator tool.

**This is very much a WIP and subject to changes at my whim!**
You have been warned.

## Using
... getting ahead of myself. it doesgstn't do anything quite yet

## Building
### From Sources
```bash
# compile shared library
cmake ./JTriangleJNI
make all

# build natives jar
mvn clean install

# build jar
cd JTriangle
mvn clean install
```

### New Java Bindings
```bash
javac -h .JTriangleJNI/src/ JTriangle/src/main/java/JTriangle.java JTriangle/src/main/java/LibUtils.java
```

## Thanks
- [JCuda](https://github.com/jcuda) for its structuring as platform-specific natives libraries plus the general-purpose Java libraries
- [Jonathan Richard Shewchuk](https://people.eecs.berkeley.edu/~jrs/) for the wonderful Triangle tool

## License
The original Triangle source code is distributed in this project. Refer to the [README](JTriangleJNI/include/triangle/README) of that project for licensing and stipulations.

Some code has been taken from the [JCuda](https://github.com/jcuda) project. Refer to the [file headers](JTriangle/src/main/java/LibUtils.java) for licensing and stipulations.

Copyright © 2020 Stevan Dedovic

Distributed under the Eclipse Public License v2.0.
