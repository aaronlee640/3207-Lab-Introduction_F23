#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>


int dircheck(char* dirname){

    struct dirent **namelist;
    int n;


    n = scandir(dirname,&namelist,NULL,alphasort);
    printf("Number Files %d\n", n);

        if (n == -1) {
            perror("scandir");

            exit(EXIT_FAILURE);
        }

        while (n--)
        {

            if(!strcmp(namelist[n]->d_name, "..")){
            free(namelist[n]);

                return 0;
            }

            printf("%s\n",namelist[n]->d_name);
            DIR *dp = opendir(namelist[n]->d_name);
            


            if (dp != NULL){
                dircheck(namelist[n]->d_name);
                free(namelist[n]);

                return 0;
            }

        }

     
}


int main(int argc, char *argv[]){
    struct dirent **namelist;
    int n;

    DIR *dp = opendir(".");

    if (dp == NULL){
        perror("opendir");
        return -1;
    }

    n = scandir(".",&namelist,NULL,alphasort);
    printf("Number Files %d\n", n);

        if (n == -1) 
        {
            perror("scandir");

            exit(EXIT_FAILURE);
        }

        while (n--)
        {
            printf("%s\n",namelist[n]->d_name);
            free(namelist[n]);
        }

        if (argc == 2)
        {
        dircheck(argv[1]);
        }

        return 0;
}