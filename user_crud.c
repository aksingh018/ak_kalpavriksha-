#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct User {
    int id;
    char name[100];
    int age;
};

int is_duplicate_id(int id) {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) return 0;

    struct User u;
    while (fscanf(file, "%d,%[^,],%d", &u.id, u.name, &u.age) == 3) {
        if (u.id == id) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

int is_valid_name(char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || name[i] == ' ')) {
            return 0;
        }
    }
    return 1;
}

int is_valid_positive_int(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int convert_to_int(char *str)
{
    int num=0;
    for(int i=0 ; str[i] != '\0' ; i++)
    {
        num = num*10 + (str[i] - '0');
    }
    return num;
}

void create_user() {
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct User u;
    char temp[100];

    printf("Enter User ID: ");
    scanf("%s", temp);
    if (!is_valid_positive_int(temp)) {
        printf("Invalid ID. Please enter a positive integer.\n");
        fclose(file);
        return;
    }
    u.id = convert_to_int(temp);

    if (is_duplicate_id(u.id)) {
        printf("Error: User ID already exists. Please use a unique ID.\n");
        fclose(file);
        return;
    }

    printf("Enter User Name: ");
    scanf(" %[^\n]s", u.name);
    if (!is_valid_name(u.name)) {
        printf("Invalid name. Only alphabetic characters and spaces are allowed.\n");
        fclose(file);
        return;
    }

    printf("Enter User Age: ");
    scanf("%s", temp);
    if (!is_valid_positive_int(temp)) {
        printf("Invalid age. Please enter a positive integer.\n");
        fclose(file);
        return;
    }
    u.age = convert_to_int(temp);

    fprintf(file, "%d,%s,%d\n", u.id, u.name, u.age);
    fclose(file);
    printf("User added successfully.\n");
}

void read_users() {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("No users found. File may not exist yet.\n");
        return;
    }

    struct User u;
    printf("\nID\tName\t\t\tAge\n");
    printf("-----------------------------------------\n");
    while (fscanf(file, "%d,%[^,],%d", &u.id, u.name, &u.age) == 3) {
        printf("%d\t%-15s\t%d\n", u.id, u.name, u.age);
    }
    fclose(file);
}

void update_user() {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("No users found.\n");
        return;
    }

    int targetId, found = 0;
    char temp[100];

    printf("Enter the User ID to update: ");
    scanf("%s", temp);
    if (!is_valid_positive_int(temp)) {
        printf("Invalid ID. Please enter a positive integer.\n");
        fclose(file);
        return;
    }
    targetId = convert_to_int(temp);

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    struct User u;
    while (fscanf(file, "%d,%[^,],%d", &u.id, u.name, &u.age) == 3) {
        if (u.id == targetId) {
            found = 1;

            printf("Enter new name: ");
            scanf(" %[^\n]s", u.name);
            if (!is_valid_name(u.name)) {
                printf("Invalid name. Only alphabetic characters and spaces are allowed.\n");
                fclose(file);
                fclose(tempFile);
                remove("temp.txt");
                return;
            }

            printf("Enter new age: ");
            scanf("%s", temp);
            if (!is_valid_positive_int(temp)) {
                printf("Invalid age. Please enter a positive integer.\n");
                fclose(file);
                fclose(tempFile);
                remove("temp.txt");
                return;
            }
            u.age = convert_to_int(temp);
        }
        fprintf(tempFile, "%d,%s,%d\n", u.id, u.name, u.age);
    }

    fclose(file);
    fclose(tempFile);

    remove("users.txt");
    rename("temp.txt", "users.txt");

    if (found) {
        printf("User updated successfully.\n");
    } else {
        printf("User not found.\n");
    }
}

void delete_user() {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("No users found.\n");
        return;
    }

    int targetId, found = 0;
    char temp[100];

    printf("Enter the User ID to delete: ");
    scanf("%s", temp);
    if (!is_valid_positive_int(temp)) {
        printf("Invalid ID. Please enter a positive integer.\n");
        fclose(file);
        return;
    }
    targetId = convert_to_int(temp);

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    struct User u;
    while (fscanf(file, "%d,%[^,],%d", &u.id, u.name, &u.age) == 3) {
        if (u.id == targetId) {
            found = 1;
            continue;
        }
        fprintf(tempFile, "%d,%s,%d\n", u.id, u.name, u.age);
    }

    fclose(file);
    fclose(tempFile);

    remove("users.txt");
    rename("temp.txt", "users.txt");

    if (found) {
        printf("User deleted successfully.\n");
    } else {
        printf("User not found.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nUser Management System\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_user();
                break;
            case 2:
                read_users();
                break;
            case 3:
                update_user();
                break;
            case 4:
                delete_user();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
