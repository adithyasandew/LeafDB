#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char current_db[256] = ""; // Default is null (empty)

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

void dbs()
{
    system("ls -1 ./data 2>/dev/null | awk '{print \"- \"$0}'");
}

void use(const char *db_name)
{
    char path[256];
    snprintf(path, sizeof(path), "./data/%s", db_name);
    
    // Check if the database folder exists
    char check_cmd[300];
    snprintf(check_cmd, sizeof(check_cmd), "[ -d \"%s\" ]", path);
    
    if (system(check_cmd) == 0)
    {
        strncpy(current_db, db_name, sizeof(current_db));
        printf("Using database '%s'\n", current_db);
    }
    else
    {
        printf("Database '%s' does not exist.\n", db_name);
    }
}


void newCollection(const char *collection_name)
{

    if (!is_db_selected())
    {
        printf("No database selected. Use a database first.\n");
        return;
    }
    
    char path[512];
    snprintf(path, sizeof(path), "./data/%s/%s.json", current_db, collection_name);

    // Check if collection already exists
    char check_cmd[600];
    snprintf(check_cmd, sizeof(check_cmd), "[ -f \"%s\" ]", path);
    if (system(check_cmd) == 0)
    {
        printf("Collection '%s' already exists in database '%s'.\n", collection_name, current_db);
        return;
    }

    // Create the collection as an empty JSON array
    char create_cmd[600];
    snprintf(create_cmd, sizeof(create_cmd), "echo '[]' > \"%s\"", path);
    if (system(create_cmd) == 0)
    {
        printf("Collection '%s' created successful.\n", collection_name);
    }
    else
    {
        printf("Failed to create collection '%s'.\n", collection_name);
    }
}


int main() {
    return 0;
}

