#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 10
#define MAX_LINE_LENGTH 10

/**
 * checks if a word can be added to the line.
 *
 * @param word the word to add.
 * @param current_line_length current line length.
 * @param max_line_length max line length.
 * @return `true` if the word fits; otherwise, `false`.
 */
int canAddWordToLine(const char *word, int current_line_length, int max_line_length) {
    int word_length = strlen(word);

    // space before word if not first word
    int space_length = (current_line_length > 0) ? 1 : 0;

    // new line length after adding the word
    int new_line_length = current_line_length + space_length + word_length;

    // check if it fits within the max line length
    if (new_line_length <= max_line_length) {
        return 1;
    }

    return 0;
}

/**
 * prints a justified line of text.
 *
 * @param words array of words.
 * @param word_count number of words.
 * @param max_line_length max line length.
 * @param is_last_line flag for last line.
 */
void printJustifiedLine(char **words, int word_count, int max_line_length) {
    if (word_count == 1) {
        printf("%s\n", words[0]);
    } else {
        // justify line
        int total_chars = 0;

        // sum word lengths
        for (int i = 0; i < word_count; i++) {
            total_chars += strlen(words[i]);
        }

        // calculate spaces
        int total_spaces = max_line_length - total_chars;
        int gaps = word_count - 1;
        int base_space = total_spaces / gaps;
        int extra_spaces = total_spaces % gaps;

        // print words with spaces
        for (int i = 0; i < word_count; i++) {
            printf("%s", words[i]);

            if (i < word_count - 1) {
                // base spaces
                for (int s = 0; s < base_space; s++) {
                    putchar(' ');
                }

                // extra space
                if (i < extra_spaces) {
                    putchar(' ');
                }
            }
        }

        // newline
        putchar('\n');
    }
}


/**
 * Processes a hyphenated word, splitting it at the hyphen and handling each part.
 *
 * @param word The hyphenated word.
 * @param words An array of words in the current line.
 * @param word_count Pointer to the number of words in the current line.
 * @param current_line_length Pointer to the current line length.
 * @param max_line_length The maximum allowed length of a line in characters.
 */
void processHyphenatedWord(char *word, char **words, int *word_count, int *current_line_length, int max_line_length) {
    // find hyphen in the word
    char *hyphen_ptr = strchr(word, '-');
    if (hyphen_ptr == NULL) {
        return;
    }

    // split the word at the hyphen
    size_t first_part_length = hyphen_ptr - word + 1; // include hyphen
    char first_part[MAX_WORD_LENGTH];
    char second_part[MAX_WORD_LENGTH];

    strncpy(first_part, word, first_part_length);
    first_part[first_part_length] = '\0';
    strcpy(second_part, hyphen_ptr + 1);

    // process the first part
    if (strlen(first_part) > max_line_length) {
        printf("Error. The word processor can’t display the output.\n");
        exit(0);
    }

    // try adding first part to current line
    int canAdd = canAddWordToLine(first_part, *current_line_length, max_line_length);
    if (canAdd == 1) {
        words[*word_count] = strdup(first_part);
        (*word_count)++;
        if (*current_line_length > 0) {
            (*current_line_length) += 1; // space
        }
        (*current_line_length) += strlen(first_part);
    } else {
        // print current line
        printJustifiedLine(words, *word_count, max_line_length);

        // reset line
        for (int i = 0; i < *word_count; i++) {
            free(words[i]);
            words[i] = NULL;
        }
        *word_count = 0;
        *current_line_length = 0;

        // add first part to new line
        words[*word_count] = strdup(first_part);
        (*word_count)++;
        *current_line_length = strlen(first_part);
    }

    // print line with first part
    printJustifiedLine(words, *word_count, max_line_length);

    // reset line
    for (int i = 0; i < *word_count; i++) {
        free(words[i]);
        words[i] = NULL;
    }
    *word_count = 0;
    *current_line_length = 0;

    // process the second part
    if (strlen(second_part) > max_line_length) {
        printf("Error. The word processor can’t display the output.\n");
        exit(0);
    }

    // add second part to new line
    words[*word_count] = strdup(second_part);
    (*word_count)++;
    *current_line_length = strlen(second_part);
}

void processFile(const char *filename, int max_line_length) {
    // Open file and read words
    // Handle word fitting and hyphenation
    // Print justified lines
    // Free allocated memory
}

int main(int argc, char *argv[]) {
    if (argc) {
    }
    int max_line_length = atoi(argv);
    if () {
        return 1;
    }

    processFile(argv, max_line_length);
    return 0;
}
