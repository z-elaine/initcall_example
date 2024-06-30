#include <stdio.h>

typedef void (*initcall_t)(void);

#define INITCALL(fn)                                                           \
  static initcall_t __initcall_##fn                                            \
      __attribute__((used, section(".initcall"))) = fn;

void init_func1(void) { printf("Initialization function 1!\n"); }

void init_func2(void) { printf("Initialization function 2!\n"); }

INITCALL(init_func1);
INITCALL(init_func2);

extern initcall_t __initcall_start;
extern initcall_t __initcall_end;

void call_initcalls(void) {
  initcall_t *call;

  for (call = &__initcall_start; call < &__initcall_end; call++) {
    (*call)();
  }
}

// void _start(void) {
//   call_initcalls();
//   asm("mov $60, %rax\n"
//       "xor %rdi, %rdi\n"
//       "syscall");
// }

int main(int argc, char *argv[]) {
  call_initcalls();
  return 0;
}
