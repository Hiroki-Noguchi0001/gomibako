#include <stdio.h>
#include <ctype.h>

int main(void) {
    FILE *Outfp;
	char *output_file = "output.txt";
    char mozi;

	Outfp = fopen(output_file, "r");
	
	if(Outfp == NULL)
	{
		printf("%sのオープンに失敗しました.\n", output_file);
		return 1;
	}

    while (( mozi = fgetc(Outfp)) != EOF )
	{
		printf("%c", mozi);
    }

	fclose(Outfp);
	printf("ファイルの読み込みが成功しました\n");
    return 0;
}

