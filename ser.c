#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct record
{
    char name[50];
    int rollno;
    int marks;
};

int main() 
{
    int fd;
    struct record student;
    fd = open("student", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }
    if (read(fd, &student, sizeof(struct record)) == -1)
    {
        perror("read");
        exit(1);
    }
    if (close(fd) == -1) 
    {
        perror("close");
        exit(1);
    }
    printf("Name: %s\n", student.name);
    printf("Roll No: %d\n", student.rollno);
    printf("Marks: %d\n", student.marks);

    return 0;
}

