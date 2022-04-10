#include <stdio.h>

void writeToFile() {
    FILE *f = fopen("input.txt", "w"); char c;
    while((c = getchar()) != '#') { fputc(c, f); }
    fclose(f); }

void printFile() {
    FILE *f=fopen("output.txt","r"); char line[100];
    while(!feof(f)){ fgets(line,100,f); if (feof(f)) break;
    printf("%s",line); } fclose(f);
}

int main() {
    writeToFile();
    char character; FILE *read = fopen("input.txt", "r");
    int n=fgetc(read) - '0', arr[n][n], sum=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            fscanf(read, "%d", &arr[i][j]);
                if(j==i){ sum+=arr[i][j]; } } }

    FILE *write = fopen("output.txt", "w");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j>i){ fprintf(write, "%03d ", sum); }
            else { fprintf(write, "    "); }
        }
        fprintf(write, "\n");
    }

    fclose(write); printFile(); return 0;
}
