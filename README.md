# Realtime c++ runtime

An experiment i dit a while ago for running new c++ code without restarting the application. 

## How does it work

The program compiles the sub command into a so-file, loads it and runs it.
This way, a file that has been compiled after the application was started can be used
without restarting the application. It can be used to create plugins like in this application,
but it can also be used to create "scripts" in c++ that is compiled only once and then used
directly.
