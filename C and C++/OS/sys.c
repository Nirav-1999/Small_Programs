#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>

void main(){
    printf("pid = %d\n",(int)getpid());
    printf("ppid = %d\n",(int)getppid());
    printf("uid = %d\n",(int)getuid());
    printf("euid = %d\n",(int)geteuid());
    printf("gid = %d\n",(int)getgid());
    printf("egid = %d\n",(int)getegid());
    int fd,fd1;
    char buff[13];
    fd = open("my.txt",O_RDWR|O_CREAT,0777);
    if (fd==1)
    {
        printf("Failed\n");
    }
    else
    {
        printf("%d\n",fd);
        write(fd,"Hello World!\n",13);
        close(fd);
    }
    fd1 = open("my..txt",O_RDWR);
    read(fd1,buff,13);
    buff[13] = '\0';
    puts(buff);
    close(fd1);
    

}