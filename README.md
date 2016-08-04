# operations_test

A simple orocos component to test an orocos operation with a std::vector output.

1. Compile package

   ```sh
   mkdir build && cd build
   cmake .. -DCMAKE_INSTALL_PREFIX=../install
   make install
   cd ..
   ```

2. Run `operations_test.ops`

   ```sh
   export RTT_COMPONENT_PATH=$(pwd)/install/lib/orocos:$RTT_COMPONENT_PATH
   deployer -l info operations_test.ops
   ```
   
