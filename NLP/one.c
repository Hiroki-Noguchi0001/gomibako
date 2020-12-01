#include <stdio.h>
#include <ctype.h>

int main(void) {
    FILE *Infp, *Outfp;
    char *input_file = "input.txt";
	char *output_file = "output.txt";
    char mozi;

    Infp = fopen(input_file, "r");
	Outfp = fopen(output_file, "w");

    if(Infp == NULL)
	{
        printf("%sのオープンに失敗しました.\n", input_file);
        return 1;
    }

	if(Outfp == NULL)
	{
		printf("%sのオープンに失敗しました.\n", output_file);
		return 1;
	}

    while (( mozi = fgetc(Infp)) != EOF )
	{
		if(isalpha(mozi) || mozi == ' ' || mozi == '\n')
		{
			fputc(mozi, Outfp);
		}

		else fputc(' ', Outfp);
    }

    fclose(Infp);
	fclose(Outfp);

	printf("ファイルの読み込みと書き込みが成功しました\n");
    return 0;
}
