#include <stdio.h>

int main(){
    FILE *infile, *outfile;
    int i;
    double d;
    char str[32];

    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "a");

    fscanf(infile, "%d%lf%s", &i, &d, &str);
    fprintf(outfile, "%d%\n%.2lf\n%s\n", i, d, str);

    fclose(infile);
    fclose(outfile);
    return 0;
}