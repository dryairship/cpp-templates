## cpp-templates

Here I explore some C++ template metaprogramming.

### How this works

The programs aren't supposed to compile. In fact, they will definitely not compile. We want the compiler to print out error messages, which, due to compile-time evaluations by the compiler, will contain the output we want to calculate! We can then grep on the error messages for the specific output we are looking for.


### How to run

Use `runner.sh` to run any program in `attempts/`. Example:

```
./runner.sh attempts/001_addition.cpp
```

The inputs to the program can be changed by updating the main function in the cpp file.