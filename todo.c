#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct todo {
    char task[100];
    struct todo *next;
} todo;

todo *head = NULL;

void pause();

void add_task() {
    todo *new_task = (todo *) malloc(sizeof(todo));
    if (new_task == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter a task: ");
    fgets(new_task->task, sizeof(new_task->task), stdin);
    // remove the newline character from the task name
    new_task->task[strcspn(new_task->task, "\n")] = '\0';
    new_task->next = head;
    head = new_task;
}

void display_tasks() {
    todo *current = head;
    int count = 1;
    while (current != NULL) {
        printf("%d. %s", count, current->task);
        current = current->next;
        count++;
    }
}

void delete_task() {
    int task_number;
    todo *current = head;
    todo *previous = NULL;
    printf("Enter the task number to delete: ");
    scanf("%d", &task_number);
    int count = 1;
    while (current != NULL) {
        if (count == task_number) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Task deleted.\n");
            return;
        }
        previous = current;
        current = current->next;
        count++;
    }
    printf("Task not found.\n");
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause() {
    #ifdef _WIN32
        system("pause");
    #else
        printf("\nPress enter to continue...");
        getchar();
    #endif
}

int main() {
    int choice;
    while (1) {
        clear_screen();
        printf("\n1. Add task\n2. Display tasks\n3. Delete task\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume the newline character
        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                display_tasks();
                break;
            case 3:
                delete_task();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
        pause(); // pause the program to allow the user to see the output
    }
    return 0;
}
