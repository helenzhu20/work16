#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    int f1, f2, w, status, ww;
    f1 = fork();
    if (f1) {
        f2 = fork();
    }
    
    if (f1) {
        printf("I'm the parent!\n");
        w = wait(&status);
        ww = WEXITSTATUS(status);
        //printf("pid: %d\tppid: %d\tf1: %d\tf2: %d\n", getpid(), getppid(), f1, f2);
        printf("childpid: %d\tstatus: %d\tsleep time: %d\n", w, status, ww);
        exit(0);
    } else {
        printf("I'm a child! pid: %d\n", getpid());
        srand(time(NULL));
        int r = (rand() % 3) + 2;
        //printf("sleep time: %d\n", r);
        printf("I've awoken! pid: %d\n", getpid());
        exit(r);
    }
    return 0;
}
