#include <stdio.h>
#include <ctype.h>

int main(void){
	FILE *Outfp;
	char *output_file = "output.txt";
	char small_alpha[26];
	int counter[26] = {};
	int count = 0;
	char a = 97;// 97 = a
	char mozi;

	Outfp = fopen(output_file, "r");

	if(Outfp == NULL)
	{
		printf("%sのオープンに失敗しました.\n", output_file);
		return 1;
	}


	for(int i = 0; i < 26; i++)
	{
		small_alpha[i] = a;
		a++;
	}
	small_alpha[26] = 32;//32 = ' '

	while(mozi = fgetc(Outfp) != EOF)
	{

		printf("%c", mozi);


		/*

		if(mozi == small_alpha[26])
		{
			count++;
		}

		else
		{
			for(int i = 0; i < 26; i++)
			{
				if(tolower(mozi) == small_alpha[i])
				{
					counter[i] = 1; 
				}
			}
		}

		*/
	}

	for(int i = 0; i <= 26; i++)
	{
		printf("%c = %d\n", small_alpha[i], counter[i]);
	}

	fclose(Outfp);

	return 0;
}
