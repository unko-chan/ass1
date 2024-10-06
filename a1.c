#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 10
#define MAX_LINE_LENGTH 10

/**
 * Determines whether adding a new word to the current line will exceed the maximum line length.
 *
 * @param word The word to be added.
 * @param current_line_length The current length of the line in characters.
 * @param max_line_length The maximum allowed length of a line in characters.
 * @return `true` if the word can be added without exceeding the maximum line length; otherwise, `false`.
 */
bool canAddWordToLine(const char *word, int current_line_length, int max_line_length) {
  int word_length = strlen(word);
  int space_length = 0;

  // add space before word if not the first word in the line
  if (current_line_length > 0) {
    space_length = 1;
  }

  // the new length if word is added
  int new_line_length = current_line_length + space_length + word_length;

  // check if new length exceeds max
  return new_line_length <= max_line_length;
}

void printJustifiedLine(char **words, int word_count, int max_line_length,
                          bool is_last_line) {
  // Calculate total characters and spaces needed // Print words with spaces distributed evenly
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