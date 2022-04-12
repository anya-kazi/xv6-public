#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "memlayout.h"
#include <stdint.h>

/*testing whether munprotect undoes the action of mprotect*/
int main(int argc, char *argv[])
{
    int ret = mprotect((int*)4096, 1);
    printf("XV6_TEST_OUTPUT: Return value of mprotect : %d\n", ret);

    ret = munprotect((int*)4096, 1);
    printf("XV6_TEST_OUTPUT: Return value of munprotect : %d\n", ret);

    *(char**)0x1000 = "this should not cause a pagefault";

    printf("XV6_TEST_OUTPUT: Written to 0x1000\n");

    exit(0);
}