#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LIMITE 5000
#define MAX 50

char * extrae_password_url_encoded(char * cuerpo_http);
int buscar (char *s,char *p);
char * extrae_username_url_encoded(char * cuerpo_http);
int buscar2 (char *s,char *p);
int encontrado(int pos, FILE *fichero);
void buscar_palabra_html();
void buscar_palabra_http();
void buscar_palabra_Content_type_application();
void buscar_palabra_http1();
void buscar_palabra_Content_type_multipart();

char * leer_archivo_texto(char * nombre_archivo);

int main()
{

    int d;

    int sw;
    FILE *no;
    FILE *si;
    FILE *pass;
    FILE *mult;
    char prueba[LIMITE];
    char pruebab[LIMITE];
    char part4;
    char x;

    printf("           RECOLECTOR DE PASSWORD Y USUARIO EN HTTP\n"); //menu principal
    printf("\n");
    printf("   ...MENU...\n");
    printf("   1) Digite 1 si quiere determinar HTML de una pagina.\n");
    printf("   2) Digite 2 si quiere determinar el contenido de un paquete si es http u otro protocolo.\n");
    printf("   3) Digite 3 si quiere ingresar HTTP de una pagina.\n");
    printf("   4) Digite 4 si quiere cargar de un archivo el contenido de un paquete HTTP.\n");
    printf("   5) Salir\n");
    printf("Opcion: ");
    scanf("%d",&sw);

    switch(sw)
    {
    case 1:
        buscar_palabra_html();//llama a la funcion que me busca la palabra html

        break;
    case 2:
        buscar_palabra_http1();//llama a la funcion que me busca la paabra http
        break;

    case 3:
        buscar_palabra_http(); //busca la palabra http
        printf("   ...MENU...\n");
        printf("   a) Digite a si quiere encontrar password o usuario de tipo Content-Type: application\n");
        printf("   b) Digite b si quiere encontrar password de tipo Content-Type: multipart/form-data\n");

        printf("Opcion: ");
        scanf("%s",&part4);
        switch(part4)
        {
        case 'a':
            buscar_palabra_Content_type_application();//asegura que el tipo de content sea application
            pass = fopen("C:\\Users\\noelf\\Downloads\\peticion1.txt", "rt");

            while(!feof(pass))
            {
                fgets(prueba,LIMITE,pass);

                d++;
                puts(extrae_password_url_encoded(prueba));
                puts(extrae_username_url_encoded(prueba));

            }
            printf("   ...MENU...\n");
            printf("Digite s si quiere guardar los datos obtenidos, n si desea salir\n");
            scanf("%s",&x);
            if (x=='s')
            {
                no = fopen("C:\\Users\\noelf\\Documents\\proyectovd\\datosguardados.txt", "a+t");
                fputs(extrae_password_url_encoded(prueba),no);
                fputs(extrae_username_url_encoded(prueba),no);
                fclose(no);
                printf("Se guardo correctamente\n");
            }
            else
            {
                printf("bye\n");
            }
            fclose(pass);

            break;
        case 'b':
            buscar_palabra_Content_type_multipart();

            FILE* p;
            char c;
            char arr[500],arr2[100],arr3[100],arr4[100];
            int i=0;

            p=fopen("C:\\Users\\noelf\\Downloads\\peticion2.txt","r");
            while (!feof(p))
            {
                c=fgetc(p);
                arr[i]=c;
                if (((arr[i]=='d')&&(arr[i-1]=='s')&&(arr[i-2]=='p'))||((arr[i]=='a')&&(arr[i-1]=='n')&&(arr[i-2]=='e')&&(arr[i-3]=='s')&&(arr[i-4]=='a')&&(arr[i-5]=='r')&&(arr[i-6]=='t')&&(arr[i-7]=='n')&&(arr[i-8]=='o')&&(arr[i-9]=='c'))||((arr[i]=='s')&&(arr[i-1]=='s')&&(arr[i-2]=='a')&&(arr[i-3]=='p'))||((arr[i]=='d')&&(arr[i-2]=='r')&&(arr[i-3]=='o')&&(arr[i-4]=='w')&&(arr[i-5]=='s')&&(arr[i-6]=='s')&&(arr[i-7]=='a')&&(arr[i-8]=='p')))
                {
                    fgets(arr2,100,p);
                    fgets(arr3,100,p);
                    fgets(arr4,100,p);
                    puts(arr4);
                }
                i++;
            }
            fclose(p);


            FILE* Z;
            char j;
            char arr1a[500],arr2a[100],arr3a[100],arr4a[100];
            int k=0;

            Z=fopen("C:\\Users\\noelf\\Downloads\\peticion2.txt","r");
            while (!feof(Z))
            {
                j=fgetc(Z);
                arr1a[k]=j;
                if (((arr1a[k]=='e')&&(arr1a[k-1]=='m')&&(arr1a[k-2]=='a')&&(arr1a[k-3]=='n')&&(arr1a[k-4]=='r')&&(arr1a[k-5]=='e')&&(arr1a[k-6]=='s')&&(arr1a[k-7]=='u'))||((arr1a[k]=='r')&&(arr1a[k-1]=='e')&&(arr1a[k-2]=='s')&&(arr1a[k-3]=='u'))||((arr1a[k]=='r')&&(arr1a[k-1]=='e')&&(arr1a[k-2]=='s')&&(arr1a[k-3]=='u'))||((arr1a[k]=='o')&&(arr1a[k-1]=='i')&&(arr1a[k-2]=='r')&&(arr1a[k-3]=='a')&&(arr1a[k-4]=='u')&&(arr1a[k-5]=='s')&&(arr1a[k-6]=='u')))
                {
                    fgets(arr2a,100,Z);
                    fgets(arr3a,100,Z);
                    fgets(arr4a,100,Z);
                    puts(arr4a);
                }
                k++;
            }
            fclose(Z);


            printf("   ...MENU...\n");
            printf("Digite g si quiere guardar los datos obtenidos, d si desea salir\n");
            scanf("%s",&x);
            if (x=='g')
            {
                si = fopen("C:\\Users\\noelf\\Documents\\proyectovd\\datosguardados.txt", "a+t");
                fputs(arr4,p);
                fputs(arr4a,Z);

                fclose(si);
                printf("Se guardo correctamente\n");

            }
            else
            {
                printf("bye\n");
            }

            break;

        }
    case 4:
        puts(leer_archivo_texto("C:\\Users\\noelf\\Documents\\proyectovd\\datosguardados.txt"));
        break;

    case 5:
        break;

    default:
        printf("Valor incorrecto");
    }
    return 0;
}


