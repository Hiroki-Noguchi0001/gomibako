#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	FILE *Outfp, *Ramfp;
	char *output_file = "output.txt";
	char *ramdom_file = "ramdom.txt";
	char mozi;
	long int mozi_cnt = 0;
	long int p_number = 0;
	long int c_number = 0;

	Outfp = fopen(output_file, "r");
	Ramfp = fopen(ramdom_file, "w");

	if(Outfp == NULL)
	{
        printf("%sのオープンに失敗しました.\n", output_file);
        return 1;
    }

	if(Ramfp == NULL)
	{
        printf("%sのオープンに失敗しました.\n", ramdom_file);
        return 1;
    }

	printf("%ld\n", mozi_cnt);
	while ((mozi = fgetc(Outfp)) != EOF)
	{
		if(mozi == 0x20 || (mozi >= 0x61 && mozi <= 0x7A))
		{
			mozi_cnt++;
		}
	}

	printf("%ld\n", mozi_cnt);

	srand((unsigned int)time(NULL));

	for(int i = 0; i <= 100; i++)
	{
		rewind(Outfp);
		p_number = 1 + rand() % mozi_cnt;

		while((mozi = fgetc(Outfp)) != EOF)
		{
			if(c_number == p_number)
			{
				fputc(mozi, Ramfp);
			}
			c_number++;
		}
		c_number = 0;
	}

	fclose(Outfp);
	fclose(Ramfp);

	printf("書き込みが終了しました.\n");
	return 0;
}
