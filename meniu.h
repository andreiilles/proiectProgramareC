#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct game
    {
        char name[255];
        float sizeOnDisk;
    } gamesInstalled[255];

float availableStorage;

void loadInstalledGames(int *installedGamesCount, float *availableStorage, struct game *gamesInstalled)
{
    FILE *fp;
    fp = fopen("localStorage.txt","r");
    int gamesRead = 0;
    float installedGamesSize = 0;
    int installedGamesCounter;    
    fscanf(fp, "%d", &installedGamesCounter);
    (*installedGamesCount) = installedGamesCounter;
    for (int i=1;i<=(installedGamesCounter*2);i++)
    {
        fgets(&gamesInstalled[gamesRead].name, 255, (FILE*)fp);
        //printf("%s\n", gamesInstalled[gamesRead].name);
        fscanf(fp,"%f",&gamesInstalled[gamesRead].sizeOnDisk);
        //printf("%.2f\n", gamesInstalled[gamesRead].sizeOnDisk);
        installedGamesSize+=gamesInstalled[gamesRead].sizeOnDisk;
        gamesRead+=1;
    }
    (*availableStorage) = (float)1024 - installedGamesSize;
    //printf("%.2f\n",availableStorage);
}

void afisareJocuriInstalate()
{
    int installedGamesCount;
    float availableStorage;
    struct game gamesInstalled[255];
    loadInstalledGames(&installedGamesCount,&availableStorage, &gamesInstalled);
    char keyPressed;
    printf("-------------------------------------------------------------------------\n");
    printf("--              Numar de jocuri instalate: %d                          --\n", installedGamesCount);
    printf("--            Spatiu disponibil: %.2fGB / 1024GB                         --\n",availableStorage); 
    for (int i=1;i<=installedGamesCount;i++)
    {
        printf("--                     %d. %s %.2fGB                     --\n", i, gamesInstalled[i].name, gamesInstalled[i].sizeOnDisk);
    } 
    printf("--            Apasa Q pentru a reveni la meniul principal              --\n");
    printf("-------------------------------------------------------------------------\n");

    while(1)
    {                
        if (kbhit())
        {
            keyPressed = getch();
            if (keyPressed=='Q'||keyPressed=='q')
                system("cls");
                mainMenu();
                break;
        }
    }
}

void afisareJocuriDisponibile()
{
    FILE *fp;
    fp = fopen("localStorage.txt","r");
    int installedGamesCount;
    fscanf(fp, "%d", &installedGamesCount);
    fclose(fp);

    for (int i=1;i>=2*installedGamesCount;i++)
    {

    }

    char keyPressed;
    printf("-------------------------------------------------------------------------\n");
    printf("--              Numar de jocuri instalate: %d                          --\n", installedGamesCount);
    printf("--            Spatiu disponibil: %dGB / 1024GB                         --\n");  
    printf("--            Apasa Q pentru a reveni la meniul principal              --\n");
    printf("-------------------------------------------------------------------------\n");

    while(1)
    {                
        if (kbhit())
        {
            keyPressed = getch();
            if (keyPressed=='Q'||keyPressed=='q')
                system("cls");
                mainMenu();
                break;
        }
    } 
}

void mainMenu()
{
    char keyPressed;
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
                afisareJocuriInstalate();
            }
            if (keyPressed=='2')
            {
                system("cls");
                afisareJocuriDisponibile();
            }
        }
    }
}