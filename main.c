#include <stdio.h>

typedef struct node Node;

struct node {
    int id;
//    char name[10];
    int age;
    int salary;
};

int main() {
    Node dude;
    dude.id = 2;
//    dude.name = "Matey";
    dude.age = 33;
    dude.salary = 90000;

    printf("dude ID:\t\t%d\n", dude.id);
    printf("dude AGE:\t%d\n", dude.age);
    printf("dude SALARY:\t%d\n", dude.salary);
    return 0;
}
