int main()
{
char str[80], ch;
printf("Enter a string, then a blank space and then any single character\n");

scanf("%s \n", str);
scanf("%c", &ch);
printf("%s\n", str);
printf("%c", ch);
return 0;
}