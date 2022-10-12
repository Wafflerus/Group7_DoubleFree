// Created by: Jim Dawes - 19311267

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "supporting.h"

char* perm; char* user; char* pass;

void main()
{
	printf("Please enter your credentials\n");
	printf("Privileged users will be provided a working environment\n\n");

	while(1)
	{
		perm = (char*) malloc(32*sizeof(char));
		user = (char*) malloc(32*sizeof(char));
		pass = (char*) malloc(32*sizeof(char));

		// Display user permissions and details
		login(user, pass, perm);
		displayuserinfo(user, pass, perm);

		// Provide a shell to users with admin_level permission
		if(strcmp(perm, "admin_level") == 0)
		{
			printf("Welcome administrator!\nCreating shell...\n");
			// Create shell
			char* const args[] = { "sh", NULL };
			execv("/bin/sh", args);
		}

		printf("\nCheck another user\n");

		// Clean up memory
		free(perm);
		free(user);
		// Now thats password :)
		free(pass);
	}
}