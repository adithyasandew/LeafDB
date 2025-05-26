#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Function to create a new database (folder in ./data)
void newdb(const char *db_name)
{
    char path[256];
    snprintf(path, sizeof(path), "./data/%s", db_name);

    // Check if folder exists
    char check_cmd[300];
    snprintf(check_cmd, sizeof(check_cmd), "[ -d \"%s\" ]", path);
    if (system(check_cmd) == 0)
    {
        printf("Database '%s' already exists.\n", db_name);
        return;
    }

    // Make ./data directory if not exists
    system("mkdir -p ./data");

    // Create the new database directory
    char cmd[300];
    snprintf(cmd, sizeof(cmd), "mkdir \"%s\"", path);
    if (system(cmd) == 0)
    {
        printf("Database '%s' created successfully.\n", db_name);
    }
    else
    {
        printf("Error creating database '%s'\n", db_name);
    }
}

int main() {
    
    return 0;
}