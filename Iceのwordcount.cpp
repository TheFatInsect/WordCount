#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<malloc.h>

int record_words(char *filename);//记录单词数量的函数
int record_chars(char *filename);//记录字符数量的函数
int record_lines(char* filename);//记录行数数量的函数

int main(int argc, char* argv[])
{
	char filename[50];
	int sum_lines;
	int sum_chars;
	int sum_words;
	if(!strcmp(argv[1],"-w"))
		record_words(argv[2]);
	//调用单词计数函数
	else if(!strcmp(argv[1],"-c"))
		record_chars(argv[2]);
	//调用字符计数函数
	else if(!strcmp(argv[1],"-l"))
		record_lines(argv[2]);
	//调用行数计数函数
	return 0;
}

int record_words(char* filename)
{
	FILE *fp = NULL;
	FILE* fp2 = NULL;
	char protect[1003];
	int protection;
	int i;
	char c;
	int END = 0;
	int sum_words = 0;
	int NUMS= 0;
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		perror(filename);
		return NULL;
	}
	while (fgets(protect, 1003, fp) != NULL)
	{
		protection = strlen(protect);
		for (i = 0; i < protection; i++)
		{
			c = protect[i];
			if (c == ' ' || c == '\t')
			{
				!END && NUMS++;
				END = 1;
			}
			else if (c != '\n' && c != '\r')
			{
				END = 0;//判定当前读取是否为最后一个单词
			}
		}
		!END && NUMS++;
		END = 1;
		sum_words += NUMS;
		NUMS = 0;
	}
	//循环记录单词数目
	printf("sum_words:%d", sum_words);
	fp2 = fopen("result.txt", "a");
	if (fp2)
	{
		
		fclose(fp2);
	}
	//输出数据 将数据传入txt文件 关闭txt。
	return 0;
}

int record_chars(char* filename)
{

	FILE* fp = NULL;
	FILE* fp2 = NULL;
	char protect[1003];
	int protection;
	int i;
	char c;
	int END = 0;
	int sum_chars= 0;
	int NUMS= 0;
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		perror(filename);
		return NULL;
	}
	while (fgets(protect, 1003, fp) != NULL)
	{
		protection= strlen(protect);
		for (i = 0; i < protection; i++) {
			c = protect[i];
			if (c == ' ' || c == '\t') {
				END = 1;//???????
			}
			else if (c != '\n' && c != '\r')
			{
				NUMS++;
				END = 0;
			}
		}

		END = 1;

		sum_chars += NUMS;

		NUMS = 0;
		//判定是否读取的最后一个字符 并进行计数
	}
	printf("totalchar:%d", sum_chars);
	fp2 = fopen("result.txt", "a");
	if (fp2) {
		fprintf(fp2, "NUMS:%d\n", sum_chars);
		fclose(fp2);
	}
	//将数据输出 并计入result.txt 然后关闭txt文件
	return 0;
}

int record_lines(char* filename)
{
	FILE* fp = NULL;
	FILE* fp2 = NULL;
	char protect[1003];
	int  protection;
	int i;
	char c;
	int sum_lines=-1;
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		perror(filename);
		return NULL;
	}

	while (fgets(protect,1003,fp)!=NULL)
	{
		protection = strlen(protect);
		for (i = 0; i < protection; i++) 
		{
			c = protect[i];
			if (c == '\n' || c == '\r') 
			{
				sum_lines++;

			}
		}
	}
	printf("totalline:%d",( sum_lines-1)/2);
	fp2 = fopen("result.txt", "a");
	if (fp2) 
	{
		fprintf(fp2, "linenum:%d\n", (sum_lines-1)/2);
		fclose(fp2);
	}
	return 0;

}



