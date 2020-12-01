#include <stdio.h>
#include <ctype.h>

int main(void){
	FILE *Outfp;
	char *output_file = "output.txt";
	char small_alpha[26];
	int count[27] = {};
	int tmp1, tmp2;
	char a = 0x61;
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

	small_alpha[26] = 0x20;

	while((mozi = fgetc(Outfp)) != EOF)
	{
		mozi = tolower(mozi);

		if(mozi == 0x20)
		{
			count[26]++;
		}

		if(mozi >= 0x61 && mozi <= 0x7A)
		{
			count[(int)mozi - 0x61]++;
		}
	}

	for (int i=0; i<27; ++i)
	{
    	for (int j=i+1; j<27; ++j)
		{
      		if (count[i] < count[j]) 
			{
        		tmp1 = count[i];
        		tmp2 = small_alpha[i];
        		count[i] = count[j];
				small_alpha [i]= small_alpha[j];
        		count[j] = tmp1;
        		small_alpha[j] = tmp2;
      		}
    	}
  }

	for(int i = 0; i <= 26; i++)
	{
		printf("%c = %d\n", small_alpha[i], count[i]);
	}

	fclose(Outfp);

	printf("上記の文字の出現頻度は大文字・小文字の区別はしていません。\n");

	return 0;
}
