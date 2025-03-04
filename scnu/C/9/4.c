#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

void extract_types(const char *line, FILE *output) {
    const char *types[] = {"int", "char", "double", "float", "long", "void"};
    int num_types = sizeof(types) / sizeof(types[0]);
    char buffer[N];
    int i = 0, j = 0;

    while (line[i] != '\0') {
        if (isalpha(line[i])) {
            buffer[j++] = line[i];
        } else {
            if (j > 0) {
                buffer[j] = '\0';
                for (int k = 0; k < num_types; k++) {
                    if (strcmp(buffer, types[k]) == 0) {
                        fprintf(output, "%s ", buffer);
                        break;
                    }
                }
                j = 0;
            }
        }
        i++;
    }
    if (j > 0) {
        buffer[j] = '\0';
        for (int k = 0; k < num_types; k++) {
            if (strcmp(buffer, types[k]) == 0) {
                fprintf(output, "%s ", buffer);
                break;
            }
        }
    }
    fprintf(output, "\n");
}

int main() {
    FILE *input = fopen("in.h", "r");
    FILE *output = fopen("out.txt", "w");
    char line[N];

    if (input == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    if (output == NULL) {
        perror("Error opening output file");
        fclose(input);
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), input)) {
        extract_types(line, output);
    }

    fclose(input);
    fclose(output);
    return EXIT_SUCCESS;
}