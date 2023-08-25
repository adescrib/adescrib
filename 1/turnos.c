#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <haru/hpdf.h> // Incluye la biblioteca libHaru

#define DAYS_IN_WEEK 7
#define MAX_NAME_LENGTH 20
#define MONTHS_IN_YEAR 12

typedef struct {
    char name[MAX_NAME_LENGTH];
    int rotation;
} Worker;

void printCalendarToPDF(int year, int daysInMonth, Worker workers[], int numWorkers) {
    HPDF_Doc pdf;
    HPDF_Page page;
    char filename[100];

    // Inicializa el objeto PDF
    HPDF_Init();
    pdf = HPDF_New(NULL, NULL);

    // Crea una página
    page = HPDF_AddPage(pdf);
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);

    // Inicia la generación del contenido del PDF
    HPDF_Page_BeginText(page);
    HPDF_Page_SetFontAndSize(page, HPDF_Font_GetHelvetica(pdf), 12);

    // Escribe el contenido del calendario en el PDF
    // ... (Aquí debes implementar la lógica para escribir en el PDF)

    // Finaliza la generación del contenido del PDF
    HPDF_Page_EndText(page);

    // Guarda el PDF en un archivo
    sprintf(filename, "calendario_%d.pdf", year);
    HPDF_SaveToFile(pdf, filename);

    // Limpia la memoria y finaliza
    HPDF_Free(pdf);
    HPDF_Cleanup();
}

int main() {
    int daysInMonth, numWorkers, year;

    printf("Ingrese el número de días en la rotación del turno: ");
    scanf("%d", &daysInMonth);

    printf("Ingrese el número de trabajadores: ");
    scanf("%d", &numWorkers);

    Worker workers[numWorkers];

    for (int i = 0; i < numWorkers; ++i) {
        printf("Ingrese el nombre del trabajador %d: ", i + 1);
        scanf("%s", workers[i].name);

        printf("Ingrese la rotación de turnos para %s: ", workers[i].name);
        scanf("%d", &workers[i].rotation);
    }

    printf("Ingrese el año: ");
    scanf("%d", &year);

    printCalendarToPDF(year, daysInMonth, workers, numWorkers);

    return 0;
}

