// Created by: Jim Dawes - 19311267

void login(char* user, char* pass, char* perm)
{
	strcpy(perm, "standard_level");

	printf("User: ");
	scanf("%s", user);

	printf("Pass: ");
	scanf("%s", pass);

	if((strcmp(user, "admin") == 0) && strcmp(pass, "password1") == 0)
	{
		strcpy(perm, "admin_level");
	}
}

void displayuserinfo(char* user, char* pass, char* perm)
{
	printf("Username: %s (%p\33[0m)\n", user, user);

	if(strcmp(pass, perm) == 0)
	{
		printf("Password: %s (\33[31m%p\33[0m)\n", pass, pass);
		printf("Perm lvl: %s (\33[31m%p\33[0m)\n", perm, perm);
	}
	else
	{
		printf("Password: %s (%p)\n", pass, pass);
		printf("Perm lvl: %s (%p)\n", perm, perm);
	}
}