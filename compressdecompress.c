#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void compress_string(char* buffer, int buffer_size) {
    FILE* input = fopen("text.txt", "r");
    int i;
    char ch;
    for (i = 0; (i < buffer_size - 1) && ((ch = fgetc(input)) != EOF) && (ch != '\n'); i++) {
        buffer[i] = ch;
    }
    buffer[i] = '\0';
    fclose(input);

    FILE* output = fopen("output.txt", "w");
    if (output == NULL) {
        perror("Failed to open output file");
        return;
    }

    int count;
    for (i = 0; buffer[i] != '\0'; i++) {
        count = 1;
        while (buffer[i] == buffer[i + 1]) {
            count++;
            i++;
        }
        fprintf(output, "%d%c", count, buffer[i]);
    }

    fclose(output);
}


void decompress(FILE* stream, char* buffer, int buffer_size) {
    
    stream = fopen("output.txt", "r");
    if (stream != NULL) {
        int i;
        char ch;
        for (i = 0; (i < buffer_size - 1) && ((ch = fgetc(stream)) != EOF) && (ch != '\n'); i++) {
            buffer[i] = ch;
        }
        buffer[i] = '\0';
        fclose(stream);
    } 

  
    FILE* output = fopen("output2.txt", "w");
    for (int i = 0; i < buffer_size && buffer[i] != '\0'; i++) {
        if (isdigit(buffer[i])) {
            int count = buffer[i] - '0'; 
            while (count != 0 && buffer[i + 1] != '\0') {
                fprintf(output, "%c", buffer[i + 1]);
                count--;
            }
            i++; 
        }
    }

    fclose(output);
}


int main() {
    FILE* stream;
    char buffer[9];
    compress_string(buffer, 9);
    return 0;
}
