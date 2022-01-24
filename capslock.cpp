#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#define MAXN 10000

void aggiusta(int N, char S[]) {
    for (int i=0; i<N; i++) {
      if (isupper(S[i])) {
        S[i]=tolower(S[i]);
      } else if (islower(S[i])) {
        S[i]=toupper(S[i]);
      }
    }
}


char S[MAXN + 5]; // Maggiore di MAXN per contenere newline e null

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d\n", &N));
    assert(fgets(S, MAXN + 5, fr) == S);
    S[N] = 0;

    aggiusta(N, S);
    fprintf(fw, "%s\n", S);
    fclose(fr);
    fclose(fw);
    return 0;
}
