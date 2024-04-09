#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int main(int argc, char** argv)
{
    FILE* f = fopen("in.txt", "r");
    int count = 0;
    int sentlen = 0;
    int memory = 0;
    char sentence = 0;

    while (!feof(f))
    {
        char c = 0;
        fscanf(f, "%c", &c);
        if ((c == ' ') || (c == '\n'))
        {
            count++;
        }
        if (c == '.')
        {
            sentlen = (count + 1 - memory > sentlen ? count + 1 - memory : sentlen);
            memory += sentlen;
        }
    }
    int sum = count + 1;
    fclose(f);
    f = fopen("out.txt", "w");
    fprintf(f, "Number of words: %d\n", sum);
    fprintf(f, "Length of the longest sentence: %d\n", sentlen);
    fclose(f);
	return 0;
}
