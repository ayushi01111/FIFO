#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

struct record {
    char name[50];
    int rollno;
    int marks;
};

int main() {
    int fd;
    struct record student;
    fd = open("student", O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    printf("Enter Name: ");
    scanf("%s",student.name);
    printf("Enter Roll No: ");
    scanf("%d", &student.rollno);
    printf("Enter Marks: ");
    scanf("%d", &student.marks);
    if (write(fd, &student, sizeof(struct record)) == -1) {
        perror("write");
        exit(1);
    }
    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }

    return 0;
}

