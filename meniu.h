#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void afisareJocuriInstalate(int *storage)
{
    char keyPressed;
    int storageSpace = *storage;
    printf("-------------------------------------------------------------------------\n");
    printf("--            Spatiu disponibil: %dGB / 1024GB                         --\n", storageSpace);
    
    printf("--            Apasa Q pentru a reveni la meniul principal              --\n");
    printf("-------------------------------------------------------------------------\n");

    while(1)
    {                
        if (kbhit())
        {
            keyPressed = getch();
            if (keyPressed=='Q'||keyPressed=='q')
                system("cls");
                mainMenu(&storageSpace);
                break;
        }
    }
}

void afisareJocuriDisponibile(int *storage)
{
    char keyPressed;
    int storageSpace = *storage;
    printf("-------------------------------------------------------------------------\n");
    printf("--            Spatiu disponibil: %dGB / 1024GB                         --\n", storageSpace);
    printf("--            Apasa Q pentru a reveni la meniul principal              --\n");
    printf("-------------------------------------------------------------------------\n");

    while(1)
    {                
        if (kbhit())
        {
            keyPressed = getch();
            if (keyPressed=='Q'||keyPressed=='q')
                system("cls");
                mainMenu(&storageSpace);
                break;
        }
    } 
}

void mainMenu(int *storage)
{
    char keyPressed;
    int storageSpace = *storage;
    printf("-------------------------------------------------------------------------\n");
    printf("-- Selecteaza o optiune de mai jos sau apasa Q pentru a inchide meniul --\n");
    printf("-- 1. Vizualizeaza lista de jocuri instalate pe sistem                 --\n");
    printf("-- 2. Vizualizeaza lista de jocuri disponibile pentru a fi instalate   --\n");
    printf("-- Selecteaza o optiune de mai sus sau apasa Q pentru a inchide meniul --\n");
    printf("-------------------------------------------------------------------------\n");

    while(1)
    {                
        if (kbhit())
        {
            keyPressed = getch();
            if (keyPressed=='Q'||keyPressed=='q')
                break;
            if (keyPressed=='1')
            {
                system("cls");
                afisareJocuriInstalate(&storageSpace);
            }
            if (keyPressed=='2')
            {
                system("cls");
                afisareJocuriDisponibile(&storageSpace);
            }
        }
    }
}