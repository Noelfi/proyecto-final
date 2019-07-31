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
    printf("   5) Digite 5 si desea buscar si la palabra buscada esta en espa%col o en otro idioma.\n",164);
    printf("   6) Salir\n");
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
        printf("   b) Digite b si quiere encontrar password o usuario de tipo Content-Type: multipart/form-data\n");
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
            //mult = fopen("C:\\Users\\noelf\\Downloads\\peticion2.txt", "rt");
            //extraer_password_multipart("C:\\Users\\noelf\\Downloads\\peticion2.txt");
            //extraer_usuario_multipart("C:\\Users\\noelf\\Downloads\\peticion2.txt");
            //puts(pruebab);
            /*while(!feof(mult))
            {
                pruebab[d]=fgetc(mult);

                d++;
                puts(extrae_password_multipart(pruebab));
                //puts(extrae_username_url_encoded(prueba));

            }*/
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
                if (((arr1a[k]=='e')&&(arr1a[k-1]=='m')&&(arr1a[k-2]=='a'))&&((arr1a[k-3]=='n')&&(arr1a[k-4]=='r')&&(arr1a[k-5]=='e')&&(arr1a[k-6]=='s')&&(arr[k-7]=='u'))||((arr[k-4]=='r')&&(arr[k-5]=='e')&&(arr[k-6]=='s')&&(arr[i-7]=='u'))||((arr[i]=='r')&&(arr[i-1]=='e')&&(arr[i-2]=='s')&&(arr[i-3]=='u'))||((arr[i]=='o')&&(arr[i-1]=='i')&&(arr[i-2]=='r')&&(arr[i-3]=='a')&&(arr[i-4]=='u')&&(arr[i-5]=='s')&&(arr[i-6]=='u')))
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
                fputs("C:\\Users\\noelf\\Downloads\\peticion2.txt",no);
                extrae_username_url_encoded("C:\\Users\\noelf\\Downloads\\peticion2.txt");
                fclose(si);
                printf("Se guardo correctamente\n");
            }
            else
            {
                printf("bye\n");
            }

            fclose(mult);

            break;
        }


        break;
    case 4:
        puts(leer_archivo_texto("C:\\Users\\noelf\\Documents\\proyectovd\\datosguardados.txt"));
        break;
    case 5:
       // extraer_password_multipart("C:\\Users\\noelf\\Downloads\\peticion2.txt");
        //extraer_usuario_multipart("C:\\Users\\noelf\\Downloads\\peticion2.txt");
        break;
    case 6:
        break;

    default:
        printf("Valor incorrecto");
    }
    return 0;
}


char * extrae_password_url_encoded(char * cuerpo_http)  //extrae password del tipo Content-Type application
{
    char * password = NULL;
    int inicio = buscar("password", cuerpo_http);

    if (inicio==-1)
    {
        return NULL;
    }
    inicio+=9;

    int final_s = buscar("&", cuerpo_http + inicio) + inicio;

    int tam = final_s - inicio;
    password = malloc((tam+1)*sizeof(char));
    strncpy(password, cuerpo_http+inicio, tam);
    password[tam] = '\0';
    return password;
}

int buscar (char *s,char *p)  //busca password de tipo Content-Type application
{
    int n=strlen(p);
    int tam_s = strlen(s);
    for (int i=0; p[i+tam_s]!='\0'; i++)
    {
        if(!strncmp(s,p+i,tam_s))
            return i;
    }
    return -1;
}


char * extrae_username_url_encoded(char * cuerpo_http)  //extrae usuario de tipo Content-Type application
{
    char * username = NULL;
    int inicio = buscar2("username", cuerpo_http);

    if (inicio==-1)
    {
        return NULL;
    }
    inicio+=9;

    int final_s = buscar2("&", cuerpo_http + inicio) + inicio;

    int tam = final_s - inicio;
    username = malloc((tam+1)*sizeof(char));
    strncpy(username, cuerpo_http+inicio, tam);
    username[tam] = '\0';
    return username;
}

int buscar2 (char *s,char *p)  //busca usuario de tipo Content-Type application
{
    int n=strlen(p);
    int tam_s = strlen(s);
    for (int i=0; p[i+tam_s]!='\0'; i++)
    {
        if(!strncmp(s,p+i,tam_s))
            return i;
    }
    return -1;
}



void buscar_palabra_html() //busca la palabra html
{
    char *p;
    FILE *fp;
    fp=fopen("C:\\Users\\noelf\\Downloads\\respuesta1.txt","rt"); //llama un archivo que contenga la palabra
    int i=0;
    //char aux[MAX];
    const char line[MAX], a[MAX]="html";
    while(!feof(fp))
    {
        fgets(line,MAX,fp);

        i++;
        p=strstr(line,a);

    }
    if(p!=NULL)
    {
        printf("Se encontro el parametro buscado\n");
    }
    else
    {
        printf("No se encontro el parametro\n");
    }

    fclose(fp);
}


void buscar_palabra_http() //busca la palabra http
{
    char p[MAX];
    FILE *fp;
    fp=fopen("C:\\Users\\noelf\\Downloads\\peticion1.txt","rt");
    fgets(p,MAX,fp);

    const char a[MAX]="POST";

    if(p!=NULL)
    {
        printf("Se encontro el parametro buscado\n");
    }
    else
    {
        printf("No se encontro el parametro\n");
    }

    fclose(fp);
}

void buscar_palabra_Content_type_application() //busca en un archivo la palabra content type applecation
{
    char *q;
    FILE *fq;
    fq=fopen("C:\\Users\\noelf\\Downloads\\peticion1.txt","rt");
    int i=0;
    //char aux[MAX];
    const char lin[MAX], b[MAX]="Content-Type: application";
    while(!feof(fq))
    {
        fgets(lin,MAX,fq);

        i++;
        q=strstr(lin,b);
        if (q!=NULL)
        {
            break;
        }

    }
    if(q!=NULL)
    {
        printf("Se encontro el parametro Content-Type: application\n");
    }
    else
    {
        printf("No se encontro el parametro\n");
    }

    fclose(fq);
}
void buscar_palabra_Content_type_multipart()
{
    char *q;
    FILE *fq;
    fq=fopen("C:\\Users\\noelf\\Downloads\\peticion2.txt","rt");
    int i=0;
    //char aux[MAX];
    const char lin[MAX], b[MAX]="Content-Type: multipart/form-data";
    while(!feof(fq))
    {
        fgets(lin,MAX,fq);

        i++;
        q=strstr(lin,b);
        if (q!=NULL)
        {
            break;
        }

    }
    if(q!=NULL)
    {
        printf("Se encontro el parametro Content-Type: multipart/form-data\n");
    }
    else
    {
        printf("No se encontro el parametro\n");
    }

    fclose(fq);
}




void buscar_palabra_http1() //busca la palabra http u otro protocolo
{
    char p[MAX];
    FILE *fp;
    fp=fopen("C:\\Users\\noelf\\Downloads\\peticion1.txt","rt");
    fgets(p,MAX,fp);

    const char a[MAX]="POST";

    if(p!=NULL)
    {
        printf("Se encontro contenido http\n");
    }
    else
    {
        printf("No se encontro el contenido, es otro protocolo\n");
    }

    fclose(fp);
}

char * leer_archivo_texto(char * nombre_archivo)
{
    FILE * fp;
    char * texto = NULL;
    int i = 0;
    char c;
    fp = fopen("C:\\Users\\noelf\\Documents\\proyectovd\\datosguardados.txt", "r");
    if (fp==NULL)
    {
        fputs("Error abriendo el archivo", stderr);
        return NULL;
    }
    while ((c=fgetc(fp))!=EOF)
    {
        if (texto==NULL)
        {
            texto = (char*) calloc(i+2, sizeof(char));
        }
        else
        {
            texto = (char*) realloc(texto, (i+2)* sizeof(char));
        }
        if (texto==NULL)
        {
            fputs("Error reservando memoria para el string", stderr);
            return NULL;
        }
        texto[i++]=c;
    }
    fclose(fp);
    texto[i]='\0';
    return texto;
}

