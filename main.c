#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

/**
 * main - Entry point
 *
 * @argc: number of arguments
 * @argv: arguments
 * Return: always 1
 */

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		char *buff = malloc(sizeof(char) * 100);
		int fd;
		
		fd = open(argv[1], O_RDONLY);
		
		if(fd < 0)
		{
			fprintf(stderr, "it din't work");
			exit(EXIT_FAILURE);
		}
		int rd = read(fd, buff, 100);
		if (rd < 0)
		{
			fprintf(stderr, "it din't work");
			exit(EXIT_FAILURE);
		}
		buff[strlen(buff)] = '\0';
		int i = 0;
		int j;
		char *com1 = malloc(sizeof(char) * 100);

		while (buff[i] != '\0')
		{
			for (j = 0; buff[i] != 32; j++)
			{
				com1[j] = buff[i];
				i++;
			}
			printf("command: %s\n", com1);
		}
		printf("string length %ld\n", strlen(buff));
		printf("buffer string %s\n", buff);
		close(fd);
	}
	printf("%d", argc);
}
