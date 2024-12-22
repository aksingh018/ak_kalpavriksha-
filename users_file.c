#include <stdio.h>
#include <string.h>

struct User {
    int id;
    char name[100];
    int age;
};

void create_users() {
    FILE *file = fopen("user.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct User u;
    printf("Enter user ID: ");
    if (scanf("%d", &u.id) != 1 || u.id <= 0) {
        printf("Invalid ID. Please enter a positive integer.\n");
        fclose(file);
        return;
    }

    printf("Enter user name: ");
    scanf(" %[^\n]s", u.name);

    printf("Enter user age: ");
    if (scanf("%d", &u.age) != 1 || u.age <= 0) {
        printf("Invalid age. Please enter a positive integer.\n");
        fclose(file);
        return;
    }

    fprintf(file, "%d,%s,%d\n", u.id, u.name, u.age);
    fclose(file);
    printf("User data added successfully.\n");
}


void read_user() {
    FILE *file = fopen("user.txt", "r");
    if (file == NULL) {
        printf("No users found.\n");
        return;
    }

    struct User u;
    printf("\nID\tName\t\t\tAge\n");
    printf("-------------------------------------\n");
    while (fscanf(file, "%d,%[^,],%d", &u.id, u.name, &u.age) == 3) {
        printf("%d\t%-15s\t%d\n", u.id, u.name, u.age);
    }
    fclose(file);
}

void update_user() {
    FILE *file = fopen("user.txt", "r");
    if (file == NULL) {
        printf("No users found.\n");
        return;
    }

    int targetId, found = 0;
    printf("Enter the user ID to update: ");
    scanf("%d", &targetId);

    FILE *tempfile = fopen("temp.txt", "w");
    if (tempfile == NULL) {
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

            printf("Enter new age: ");
            scanf("%d", &u.age);
        }
        fprintf(tempfile, "%d,%s,%d\n", u.id, u.name, u.age);
    }

    fclose(file);
    fclose(tempfile);

    remove("user.txt");
    rename("temp.txt", "user.txt");

    if (found) {
        printf("User updated \n");
    } else {
        printf("User not found.\n");
    }
}

void delete_user() {
    FILE *file = fopen("user.txt", "r");
    if (file == NULL) {
        printf("No users found.\n");
        return;
    }

    int targetId, found = 0;
    printf("Enter the user ID : ");
    scanf("%d", &targetId);

    FILE *tempfile = fopen("temp.txt", "w");
    if (tempfile == NULL) {
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
        fprintf(tempfile, "%d,%s,%d\n", u.id, u.name, u.age);
    }

    fclose(file);
    fclose(tempfile);

    remove("user.txt");
    rename("temp.txt", "user.txt");

    if (found) {
        printf("User deleted \n");
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
                create_users();
                break;
            case 2:
                read_user();
                break;
            case 3:
                update_user();
                break;
            case 4:
                delete_user();
                break;
            case 5:
                printf("Exit.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
