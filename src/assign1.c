#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LINESIZE 512
#define NAMESIZE 20

int prompt_id(char id[]);
int prompt_name(char fname[], char lname[]);
int prompt_score();
int prompt_commands();
int c(const int a);

int is_valid_id(const char id[]);
int is_valid_name(const char name[]);
int is_valid_score(int score);


/*  Main method */
int main(void)
{
    prompt_commands();
   
    return 0;
}


/* prompts user to enter a command */
int prompt_commands()
{   
    char id[NAMESIZE];
    char fname[NAMESIZE];
    char lname[NAMESIZE];

    char input_cmd[LINESIZE];
    int scanned_cmd;
    
    fprintf(stderr, "Enter a command: \n");

    fgets(input_cmd, LINESIZE, stdin);
    if(input_cmd[0] == '0')
    {
        prompt_id(id);
        prompt_name(fname, lname);
        prompt_score();
    }
    if(sscanf(input_cmd, "%d", &scanned_cmd))
    {
        return scanned_cmd;
    }
    return 1;
    
}



/* prompts user for id */
int prompt_id(char id[])
{
    char input_id[LINESIZE];
    char scanned_id[NAMESIZE];

    while(1)
    {
        fprintf(stderr, "Enter your student ID: \n");
    
        fgets(input_id, LINESIZE, stdin);
        sscanf(input_id, "%s", scanned_id);
    
        if(is_valid_id(scanned_id) == 1)
        {
            fprintf(stderr, "Your ID is: %s\n", scanned_id);
            strcpy(id, scanned_id);
           
            return 1;
        }
    }
}

/* prompts user for name */
int prompt_name(char fname[], char lname[])
{
    char input_name[LINESIZE];
	char scanned_fname[NAMESIZE];
	char scanned_lname[NAMESIZE];
    
    while(1)
    {
        fprintf(stderr, "Enter your name: \n");
    
        fgets(input_name, LINESIZE, stdin);
        sscanf(input_name, "%s%s", scanned_fname, scanned_lname);
    
        if(is_valid_name(scanned_fname) == 1 && is_valid_name(scanned_lname) == 1)
        {
            fprintf(stderr, "Your name is: %s%s\n", scanned_fname, scanned_lname);
            strcpy(fname, scanned_fname);
            strcpy(lname, scanned_lname);
            return 1;
        }
    }
}



/* prompts user to enter a score */
int prompt_score()
{
    char input_score[LINESIZE];
    int scanned_score;
    
    while(1)
    {
        fprintf(stderr, "Enter your score: \n");
        
        fgets(input_score, LINESIZE, stdin); 
        if(input_score[0] == '~')
            {
                prompt_commands();
            }
        if(sscanf(input_score, "%d", &scanned_score))
        {  
            if(is_valid_score(scanned_score))
            {
                fprintf(stderr, "Your score is: %d\n",scanned_score);
                return scanned_score;
            }
        }
    }
}




/* checks if users score is valid */
int is_valid_score(int score)
{
    if(score <= 0 || score >= 100)
    {
        return 0;
    }
    
    return 1;
}



/* checks whether the users id is valid */
int is_valid_id(const char id[])
{
    size_t i;
    
    if(id[0] == '~')
    {
        prompt_commands();
    }
    if(id[0] != 'a' && !islower(id[0]))
    {
        return 0;
    }
    if(strlen(id)!= 9)
    {
        return 0;
    }

    for(i = 1; i < strlen(id); i++)
    {
        if(!isdigit(id[i]))
        {
            return 0;
        }
    }
  
    return 1;
}




/* checks to see if names are valide */
int is_valid_name(const char name[])
{
    size_t i;
    
    if(name[0] == '~')
    {
        prompt_commands();
    }
    /* checks length, more than 2 less than 20 */
	if(strlen(name) < 2 || strlen(name) > 20)
	{
		return 0;
	}
    /* checks first character and last character*/
	if(name[0] == '-' || name[strlen(name) - 1] == '-')
	{
		return 0;
	}
    
    /* checks for hyphens at start and end */
    for(i = 0; i < strlen(name); i++)
	{
		if(!isalpha(name[i]) && name[i] != '-')
		{
			return 0;
		}
	}
	return 1;
}