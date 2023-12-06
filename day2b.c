#include <stdio.h>
#include <string.h>

unsigned int red = 12, green = 13, blue = 14;

struct cubes {
  int red;
  int green;
  int blue;
};

void powergames(char* str, struct cubes* curr){
  unsigned int i[3] = {0,0,0};
  char s[3][10];
  int ret = sscanf(str, " %u %9[a-z],%u %9[a-z],%u %9[a-z],", &i[0],s[0],&i[1],s[1],&i[2],s[2]);
  for (int j = 0; j<ret/2; j++) {
    if (strcmp(s[j], "red") == 0)
      if (i[j]>curr->red)
        curr->red = i[j];
    if (strcmp(s[j], "green") == 0)
      if (i[j]>curr->green)
        curr->green = i[j];
    if (strcmp(s[j], "blue") == 0)
      if (i[j]>curr->blue)
        curr->blue = i[j];
  }
}

int parse(char* line) {
  unsigned int gameID, err=0;
  char longstring[200];
  sscanf(line, "Game %u:%199[^\n]s", &gameID, longstring);
  char * token = strtok(longstring, ";");
  struct cubes current = {0,0,0};
  do {
    powergames(token, &current);
  } while ((token = strtok(NULL, ";")) != NULL);
  printf("gameid %u r%i g%i b%i\n", gameID, current.red, current.green, current.blue);
  return current.red*current.green*current.blue;
}

int main() {
  unsigned int game_sum = 0;
  char linestr[206];
  while( fgets (linestr, 206, stdin)!=NULL )
    game_sum += parse(linestr);
  printf("sum of the valid games: %u", game_sum);
  return 0;

}
