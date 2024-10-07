#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
bool canAddWordToLine(const char *word, int current_line_length, int max_line_length) {
  int word_length = strlen(word);

  // space before word if not first word
  int space_length = (current_line_length > 0) ? 1 : 0;

  // new line length after adding the word
  int new_line_length = current_line_length + space_length + word_length;

  // check if it fits within the max line length
  return new_line_length <= max_line_length;
}

/**
 * prints a justified line of text.
 *
 * @param words array of words.
 * @param word_count number of words.
 * @param max_line_length max line length.
 * @param is_last_line flag for last line.
 */
void printJustifiedLine(char **words, int word_count, int max_line_length, bool is_last_line) {
  if (word_count == 1) {
    // if single word, center it
    int word_length = strlen(words[0]);
    int total_spaces = max_line_length - word_length;
    int left_spaces = total_spaces / 2;
    int right_spaces = total_spaces - left_spaces;

    // left padding
    for (int i = 0; i < left_spaces; i++) {
      putchar(' ');
    }

    // print word
    printf("%s", words[0]);

    // right padding
    for (int i = 0; i < right_spaces; i++) {
      putchar(' ');
    }

    // newline
    putchar('\n');
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


void processHyphenatedWord(char *word, char **words, int *word_count, int *current_line_length,
                             int max_line_length) {
  // Split word at hyphen and process each part
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