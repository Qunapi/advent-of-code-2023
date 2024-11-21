#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Hello world, \n");

  FILE *file_ptr;

  file_ptr = fopen("./data-1.txt", "r");

  const int LINES_AMOUNT = 2000;
  const int LINE_MAX_LENGTH = 400;

  char buffer[LINES_AMOUNT][LINE_MAX_LENGTH];

  char *readStatus = fgets(buffer[0], LINE_MAX_LENGTH, file_ptr);

  int linesCount = 0;

  while (readStatus != NULL) {
    linesCount++;
    readStatus = fgets(buffer[linesCount], LINE_MAX_LENGTH, file_ptr);
  }

  fclose(file_ptr);

  char **numbers = malloc(linesCount * sizeof(char *));
  if (numbers == NULL) {
    printf("1 Memory allocation failed!\n");
    return 1;
  }

  for (int i = 0; i < linesCount; i++) {
    int symbolNumber = 0;

    char symbol = buffer[i][symbolNumber];

    int numberPosition = 0;

    numbers[i] = malloc(LINE_MAX_LENGTH * sizeof(char));

    char firstDigit = 0;
    char lastDigit = 0;

    while (symbol != '\n') {

      if (symbol >= '0' && symbol <= '9') {
        if (firstDigit == 0) {
          firstDigit = symbol;
        }

        lastDigit = symbol;
      }

      symbolNumber++;

      symbol = buffer[i][symbolNumber];
    }

    numbers[i][0] = firstDigit;
    numbers[i][1] = lastDigit;
  }

  int sum = 0;

  for (int i = 0; i < linesCount; i++) {
    char *endptr;

    char finalNumber[3] = {numbers[i][0], numbers[i][1], '\0'};

    printf("%d %c %c final number = %s\n", i, numbers[i][0], numbers[i][1],
           finalNumber);

    int rowNumber = strtol(finalNumber, &endptr, 10);

    sum = sum + rowNumber;
  }

  printf("total lines %d\n", linesCount);
  printf("sum: %d\n", sum);
  printf("\n");

  return 0;
}
