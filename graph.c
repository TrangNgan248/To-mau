#include <stdio.h>
#include <string.h>
#define MAX 100
// int fillFullColor(int a[][MAX], int n, int v[]);
// int checkColor(int a[][MAX], int n, int v[], int i, int c);
// int fillOneColor(int a[][MAX], int n, int v[], int color);

int checkColor(int a[][MAX], int n, int v[], int i, int c)
{
    for (int j = 1; j <= n; j++)
        if (a[i][j] != 0 && v[j] == c)
            return 0;
    return 1;
}
int fillOneColor(int a[][MAX], int n, int v[], int color)
{
    int i;
    int count = 0;
    for (i = 1; i <= n; i++)
        if (v[i] == 0 && checkColor(a, n, v, i, color))
        {
            v[i] = color;
            count++;
        }
    return count;
}
int fillFullColor(int a[][MAX], int n, int v[])
{
    for (int i = 1; i <= n; i++)
        v[i] = 0;
    int color = 0;
    int count = 0;
    while (count < n)
    {
        color++;
        count += fillOneColor(a, n, v, color);
    }
    return color;
}
void readFile(char *fname, int a[][MAX], int n)
{
    FILE *f;
    int d, canh, d1, d2, i, j;

    f = fopen(fname, "r");
    if (f == NULL)
    {
        printf("file khong ton tai!\n");
        return;
    }
    else
    {
        f = fopen(fname, "r");
        fscanf(f, " %d %d", &d, &canh);
        int c = fgetc(f);

        for (int i = 1; i <= d; i++)
            for (int j = 1; j <= d; j++)
                a[i][j] = 0;
        for (int i = 1; i <= canh; i++)
        {
            fscanf(f, "%d %d", &d1, &d2);
            int c = fgetc(f);
            a[d1][d2] = 1;
            a[d2][d1] = 1;
        }
    }
    fclose(f);
    int v[MAX];
    n = d;
    int kq = fillFullColor(a, n, v);
    // ghi ra file dot
    FILE *g;
    g = fopen("dothimau.dot", "w");
    fprintf(g, "%s", "graph dothi\n {\n");
    for (i = 1; i <= n; i++)
    {
        fprintf(g, "%d", i);
        fprintf(g, "%s", "[ fillcolor = ");
        switch (v[i])
        {
        case 1:
        {
            fprintf(g, "%s", "red");
            break;
        }
        case 2:
        {
            fprintf(g, "%s", "green");
            break;
        }
        case 3:
        {
            fprintf(g, "%s", "yellow");
            break;
        }
        case 4:
        {
            fprintf(g, "%s", "orange");
            break;
        }
        case 5:
        {
            fprintf(g, "%s", "blue");
            break;
        }
        case 6:
        {
            fprintf(g, "%s", "purple");
            break;
        }
        case 7:
        {
            fprintf(g, "%s", "brown");
            break;
        }
        case 8:
        {
            fprintf(g, "%s", "violet");
            break;
        }
        case 9:
        {
            fprintf(g, "%s", "grey");
            break;
        }
        case 10:
        {
            fprintf(g, "%s", "pink");
            break;
        }
        }
        fprintf(g, "%s", ", style = filled ];\n");
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (a[i][j] != 0)
            {
                a[j][i] = 0;
                fprintf(g, "%d", i);
                fprintf(g, "%s", " -- ");
                fprintf(g, "%d", j);
                fprintf(g, "%s", "\n");
            }
        }
    }
    fprintf(g, "%s", "}\n");
    fclose(g);
}
int main()
{
    int a[MAX][MAX];
    int n;
    readFile("g.txt", a, n);
}