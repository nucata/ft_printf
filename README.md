# FT_PRINTF

This is my implementation of the `printf` function.

## How to make it work?

1. Clone the repository
```bash
git clone https://github.com/nucata/ft_printf.git
```

2. Move to the repository and compile the source files in order to get the staticallly linked library
```bash
cd ft_printf && make
```

3. Remove the object files
```bash
make clean
```

4. Create a main function
```bash
touch main.c
```

5. Copy this code inside the `main.c` file
 ```c
 #include "ft_printf.h"   // Here are the prototypes of my functions.
 
 int main(void)
 {
    char  *this_is_a_test = "Hello World!";
    ft_printf("text: %s\n", this_is_a_test);
    ft_printf("addr: %p", this_is_a_test);
    return (0);
 }
 ```
 
 6. Compile it
 ```bash
 cc main.c libftprintf.a
 ```
 
 7. Execute it
 ```bash
 ./a.out
 ```
 
 8. Change things in the code and have fun!
