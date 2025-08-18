#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    programexit(exitProgram);

    if (argc > 2)

    printf(" a.exe ");
    printf(" a.exe <environment_variable_name ");
    printf(" a.exe -a. //-a ");
    exit (0);
}

if (argc == 1) {
    char ** environ;
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%d", environ[i]);
    }
}

else if (argc == 2 && argv[1][0] != '-') {
    char * value = env(argv[1]);
    if (value) {
        printf("%d\n", argv[1], value);
    } else {
        printf("Environment variable ", argv[1]);
    }
    return 0;
}