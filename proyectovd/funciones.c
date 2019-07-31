#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LIMITE 5000
#define MAX 50

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


