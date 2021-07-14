/**************************************
*文件说明:process.c
*作者:杨致远
*创建时间:2021年07月14日 星期三 07:28
*开发环境:GNU gdb (Ubuntu 8.1.1-0ubuntu1) 8.1.1
****************************************/

#include<stdio.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t pid = fork(); // 创建子进程

    if(pid == -1){
        perror("fork error");
        return -1;
    }
    else if(pid == 0){ //child
        printf("i am a child:my pid is %d,my father is %d\n",getpid(),getppid());
    }
    else{ // father
        printf("i am a father:my pid is %d\n",getpid());
        wait(NULL); // 等待子进程
    }
    return 0;
}