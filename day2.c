#include <stdio.h>
#include <string.h>

unsigned int red = 12, green = 13, blue = 14;

int gameok(char* str){
  int err = 0;
	unsigned int i[3] = {0,0,0};
	char s[3][10];
	int ret = sscanf(str, " %u %9[a-z],%u %9[a-z],%u %9[a-z]", &i[0],s[0],&i[1],s[1],&i[2],s[2]);
	//printf("vars: %i\n",ret);
	for (int j = 0; j<ret/2; j++) {
    if (strcmp(s[j], "red") == 0)
      if (i[j]>red)
        err=1;
    if (strcmp(s[j], "green") == 0)
      if (i[j]>green)
        err=1;
    if (strcmp(s[j], "blue") == 0)
      if (i[j]>blue)
        err=1;
    //printf("gameok: err=%d, s%s i%u\n",err,s[j],i[j]);
  }
	return err;
}

int parse(char* line) {
	unsigned int gameID, err=0;
	char longstring[200];
	sscanf(line, "Game %u:%199[^\n]s", &gameID, longstring);
	//printf("longstring: %s, for game : %u\n", longstring, gameID);
	char * token = strtok(longstring, ";");
	do {
		//printf("%s \n", token);
		err += gameok(token);
	} while ((token = strtok(NULL, ";")) != NULL);
  //printf("ok %s, gameid %u\n", !err?"true":"false", gameID);
  return !err?gameID:0;
}

int main() {
	unsigned int game_sum = 0;
  char linestr[206];
  while( fgets (linestr, 206, stdin)!=NULL )
    game_sum += parse(linestr);
  printf("sum of the valid games: %u", game_sum);
	return 0;

}
