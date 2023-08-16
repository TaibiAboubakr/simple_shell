#include "main.h"
/**
 * _cd - function that prints all environment variables
 */
int _cd(const char *dest_dir)
{
char *current_dir;
static char path[1024] = "\0";
int i = 0;
if (!dest_dir)
dest_dir = getenv("HOME");
current_dir = getcwd(NULL, 100); 
if (errno == ENOMEM){
printf("not enought memory\n");
return 12;}

printf("current working directory is : %s\n",current_dir);
if (strcmp(dest_dir,"-") == 0){
if(!path[0]){
printf("bash: cd: OLDPWD not set\n");
return(-1);}
dest_dir = path;
printf("from -\n");
printf("in %s -\n", dest_dir);
}

if (chdir(dest_dir) == 0) {
    for(i = 0;current_dir[i];i++){
    path[i] = current_dir[i];
}
    path[i] = '\0';
    free(current_dir);
    current_dir = getcwd(NULL, 100);
    setenv("PWD", current_dir, 1);
    free(current_dir);
    printf("Current working directory changed successfully.\n");
    } else {
        if (errno == EACCES ){
        printf("Permission Denied :(\n");
        return 13;}
        if (errno == ENOENT ){
        printf("sh: 1: cd: can't cd to %s\n",dest_dir);
        return 2;}
    }

current_dir = getcwd(NULL, 100); 
printf("after : current working directory is : %s\n",current_dir);

printf("PWD is %s\n",getenv("PWD"));
free(current_dir);
return (0);
}

int main(void){
const char *dir = "ooo";
_cd(dir);
printf("\n#########################\n");
 _cd("-");
printf("\n#########################\n");

 _cd("ppp");
printf("\n#########################\n");
_cd("../printf");
_cd(NULL);
    return 0;
}





