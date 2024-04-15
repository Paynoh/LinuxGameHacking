#!/bin/bash

# Set the path to your shared object
#so_file="pwd/injected.so"

# Set the PID of the target process
pid=$(pidof linux_client)

gdb -ex "attach $pid" -ex "call (void *)dlopen(\"$so_file\", 2)" -ex "printf \"Shared object injected into process %d\n\", $pid" -ex "detach" -ex "quit"
