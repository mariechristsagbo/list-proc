#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#define BUF_SIZE 25

  
void read_proc(const char *pid) {
    char path[BUF_SIZE];
    FILE *fp;
    char buf[BUF_SIZE];
    char name[BUF_SIZE];


    snprintf(path, sizeof(path), "/proc/%s/status", pid);

    
    fp = fopen(path, "r");
    if (fp == NULL) {
        fprintf(stderr, "Une erreur s'est produite");
        return;
    }

    
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        
        if (strncmp(buf, "VmSize:", 7) == 0) {
            printf("PID: %s, Nom du processus: %s, Utilisation de la mémoire: %s \n", pid, name, buf + 7);
            break;
        }
        
        else if (strncmp(buf, "Name:", 5) == 0) {
            sscanf(buf, "%*s %s", name); 
        }
    }

    
    fclose(fp);
}


int list_processes() {
    DIR *dir;
    struct dirent *entry;

    
    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Une erreur s'est produite");
        return 0;
    }

    
    while ((entry = readdir(dir)) != NULL) {
        
        if (entry->d_type == DT_DIR && atoi(entry->d_name) != 0) {
            
            read_proc(entry->d_name);
        }
    }

    
    closedir(dir);
    
    return 3;
}

int main() {
    printf("Liste des processus en cours d'exécution :\n");
    list_processes();
    return 0;
}
