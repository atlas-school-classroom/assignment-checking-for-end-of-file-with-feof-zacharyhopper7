#include <stdio.h>

int main() {
    FILE *fp;
    char line[200];
    int count = 1;

    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        perror("Could not open file");
        return 1;
    }

    while (!feof(fp)) {
        if (fgets(line, sizeof(line), fp) != NULL) {
            printf("Line %d: %s", count, line);
            count++;
        }

        if (ferror(fp)) {
            perror("Error reading file");
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}